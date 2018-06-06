/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:01 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:02 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_sphere(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;

	pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	x1 = DOT(pool->ray, pool->ray);
	x2 = 2 * DOT(pool->coord, pool->ray);
	x3 = DOT(pool->coord, pool->coord) - (RADIUS * RADIUS);
	discriminant = (x2 * x2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_sphere(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;

	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	x1 = DOT(pool->l, pool->l);
	x2 = 2 * DOT(pool->coord, pool->l);
	x3 = DOT(pool->coord, pool->coord) - (RADIUS * RADIUS);
	discriminant = (x2 * x2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	find_normal_sphere(t_pool *pool)
{
	pool->normal.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
	pool->normal.y = pool->p.y - pool->figure[pool->cls_figure].pos.y;
	pool->normal.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
	pool->normal.x /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
	pool->normal.y /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
	pool->normal.z /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
}