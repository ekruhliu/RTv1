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
	COORD.x = pool->cam.x - FIGURE[i].pos.x;
	COORD.y = pool->cam.y - FIGURE[i].pos.y;
	COORD.z = pool->cam.z - FIGURE[i].pos.z;
	x1 = DOT(cyl, cyl) - pow(X9, 2);
	x2 = 2 * (DOT(cyl, COORD) - (X9 * X10));
	x3 = DOT(COORD, COORD) - pow(X10, 2) - pow(RADIUS, 2);
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
	COORD.x = pool->p.x - FIGURE[i].pos.x;
	COORD.y = pool->p.y - FIGURE[i].pos.y;
	COORD.z = pool->p.z - FIGURE[i].pos.z;
	x1 = DOT(cyl, cyl) - pow(X9, 2);
	x2 = 2 * (DOT(cyl, COORD) - (X9 * X10));
	x3 = DOT(COORD, COORD) - pow(X10, 2) - pow(RADIUS, 2);
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
	double		x1;
	t_vector	x2;
	t_vector	x3;
	t_vector	x4;

	x2.x = pool->p.x - FIGURE[CLS_F].pos.x;
	x2.y = pool->p.y - FIGURE[CLS_F].pos.y;
	x2.z = pool->p.z - FIGURE[CLS_F].pos.z;
	x1 = DOT(FIGURE[CLS_F].dir, x2);
	x3.x = x1 * FIGURE[CLS_F].dir.x;
	x3.y = x1 * FIGURE[CLS_F].dir.y;
	x3.z = x1 * FIGURE[CLS_F].dir.z;
	x4.x = x2.x - x3.x;
	x4.y = x2.y - x3.y;
	x4.z = x2.z - x3.z;
	NORMAL.x = x4.x / FIGURE[CLS_F].radius;
	NORMAL.y = x4.y / FIGURE[CLS_F].radius;
	NORMAL.z = x4.z / FIGURE[CLS_F].radius;
}
