/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:11 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:12 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_cylinder(t_pool *pool, int i)
{
	double		x1;
	double		x2;
	double		x3;
	double		discriminant;
	t_vector	cyl;

	cyl.x = pool->ray.x;
	cyl.y = pool->ray.y;
	cyl.z = pool->ray.z;
	pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	x1 = DOT(cyl, cyl) - pow(DOT(cyl, pool->figure->dir), 2);
	x2 = 2 * (DOT(cyl, pool->coord) - (DOT(cyl, pool->figure->dir) * DOT(pool->coord, pool->figure->dir)));
	x3 = DOT(pool->coord, pool->coord) - pow(DOT(pool->coord, pool->figure->dir), 2) - pow(RADIUS, 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
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

void	find_normal_cylinder(t_pool *pool)
{
	double		x_1;
	t_vector	x_2;
	t_vector	x_3;
	t_vector	x_4;
	
	x_2.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
	x_2.y = pool->p.y - pool->figure[pool->cls_figure].pos.y;
	x_2.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
	x_1 = DOT(pool->figure[pool->cls_figure].dir, x_2);
	x_3.x = x_1 * pool->figure[pool->cls_figure].dir.x;
	x_3.y = x_1 * pool->figure[pool->cls_figure].dir.y;
	x_3.z = x_1 * pool->figure[pool->cls_figure].dir.z;
	x_4.x = x_2.x - x_3.x;
	x_4.y = x_2.y - x_3.y;
	x_4.z = x_2.z - x_3.z;
	pool->normal.x = x_4.x / pool->figure[pool->cls_figure].radius;
	pool->normal.y = x_4.y / pool->figure[pool->cls_figure].radius;
	pool->normal.z = x_4.z / pool->figure[pool->cls_figure].radius;
}