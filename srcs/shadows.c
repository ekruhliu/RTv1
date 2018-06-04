/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:54:26 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 18:54:27 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
	x3 = DOT(pool->coord, pool->coord) - RADIUS * RADIUS;
	discriminant = x2 * x2 - 4 * x1 * x3;
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_cylinder(t_pool *pool, int i)
{
	double		x1;
	double		x2;
	double		x3;
	double		discriminant;
	t_vector	cyl;

	cyl.x = pool->l.x;
	cyl.y = pool->l.y;
	cyl.z = pool->l.z;
	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	x1 = DOT(cyl, cyl) - pow(DOT(cyl, pool->figure->dir), 2);
	x2 = 2 * (DOT(cyl, pool->coord) - (DOT(cyl, pool->figure->dir) * DOT(pool->coord, pool->figure->dir)));
	x3 = DOT(pool->coord, pool->coord) - pow(DOT(pool->coord, pool->figure->dir), 2) - pow(RADIUS, 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	create_shadow(t_pool *pool)
{
	int i;

	i = -1;
	pool->shadow_t = INFINITY;
	pool->sdw_figure = -1;
	while (++i < pool->fig_counter)
	{
		(pool->figure[i].type == 1 ? intersect_shadow_sphere(pool, i) : 0);
		(pool->figure[i].type == 2 ? intersect_shadow_cylinder(pool, i) : 0);
		//cone
		//cyl
		//plane
		if (pool->sdw_t1 > 0.0001 && pool->sdw_t1 < 1 && pool->sdw_t1 < pool->shadow_t)
		{
			pool->shadow_t = pool->sdw_t1;
			pool->sdw_figure = i;
		}
		if (pool->sdw_t2 > 0.0001 && pool->sdw_t2 < 1 && pool->sdw_t2 < pool->shadow_t)
		{
			pool->shadow_t = pool->sdw_t2;
			pool->sdw_figure = i;
		}
	}
}
