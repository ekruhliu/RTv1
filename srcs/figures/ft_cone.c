/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:18 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:18 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_cone(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;
	t_vector	cone;

	cone.x = pool->ray.x;
	cone.y = pool->ray.y;
	cone.z = pool->ray.z;
	pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	pool->cone_radiana = tan((pool->figure[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(pool->cone_radiana, 2)) * pow(DOT(cone, pool->figure[i].dir), 2);
	x2 = 2 * (DOT(cone, pool->coord) - (1 + pow(pool->cone_radiana, 2)) * (DOT(cone, pool->figure[i].dir) * (DOT(pool->coord, pool->figure[i].dir))));
	x3 = DOT(pool->coord, pool->coord) - (1 + pow(pool->cone_radiana, 2)) * pow(DOT(pool->coord, pool->figure[i].dir), 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_cone(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;
	t_vector	cone;

	cone.x = pool->l.x;
	cone.y = pool->l.y;
	cone.z = pool->l.z;
	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	pool->cone_radiana = tan((pool->figure[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(pool->cone_radiana, 2)) * pow(DOT(cone, pool->figure[i].dir), 2);
	x2 = 2 * (DOT(cone, pool->coord) - (1 + pow(pool->cone_radiana, 2)) * (DOT(cone, pool->figure[i].dir) * (DOT(pool->coord, pool->figure[i].dir))));
	x3 = DOT(pool->coord, pool->coord) - (1 + pow(pool->cone_radiana, 2)) * pow(DOT(pool->coord, pool->figure[i].dir), 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	find_normal_cone(t_pool *pool)
{
	pool->var = malloc(sizeof(t_variable));

	pool->var->x2.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
	pool->var->x2.y = pool->p.y - pool->figure[pool->cls_figure].pos.y;
	pool->var->x2.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
	pool->var->x6 = (sqrt(pow(pool->var->x2.x, 2) + pow(pool->var->x2.y, 2) + pow(pool->var->x2.z, 2)));
	pool->var->x7 = (sqrt(pow(pool->figure[pool->cls_figure].dir.x, 2) + pow(pool->figure[pool->cls_figure].dir.y, 2) + pow(pool->figure[pool->cls_figure].dir.z, 2)));
	pool->var->x8 = ((pool->var->x2.x * pool->figure[pool->cls_figure].dir.x) + (pool->var->x2.y * pool->figure[pool->cls_figure].dir.y) + (pool->var->x2.z * pool->figure[pool->cls_figure].dir.z));
	pool->var->x1 = (pool->var->x8 / (pool->var->x6 * pool->var->x7));
	pool->var->x3.x = pool->var->x1 * pool->figure[pool->cls_figure].dir.x;
	pool->var->x3.y = pool->var->x1 * pool->figure[pool->cls_figure].dir.y;
	pool->var->x3.z = pool->var->x1 * pool->figure[pool->cls_figure].dir.z;
	pool->var->x4.x = pool->var->x2.x - pool->var->x3.x;
	pool->var->x4.y = pool->var->x2.y - pool->var->x3.y;
	pool->var->x4.z = pool->var->x2.z - pool->var->x3.z;
	pool->var->x5.x = (pool->var->x2.y * pool->var->x4.z) - (pool->var->x2.z * pool->var->x4.y);
	pool->var->x5.y = (pool->var->x2.x * pool->var->x4.z) - (pool->var->x2.z * pool->var->x4.x);
	pool->var->x5.z = (pool->var->x2.x * pool->var->x4.y) - (pool->var->x2.y * pool->var->x4.x);
	pool->var->x4.x = (pool->var->x5.y * pool->var->x2.z) - (pool->var->x5.z * pool->var->x2.y);
	pool->var->x4.y = (pool->var->x5.z * pool->var->x2.x) - (pool->var->x5.x * pool->var->x2.z);
	pool->var->x4.z = (pool->var->x5.x * pool->var->x2.y) - (pool->var->x5.y * pool->var->x2.x);
	pool->normal.x = pool->var->x4.x / (X8);
	pool->normal.y = pool->var->x4.y / (X8);
	pool->normal.z = pool->var->x4.z / (X8);
	free(pool->var);
}