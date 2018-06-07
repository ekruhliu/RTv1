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
	double		x_1;
	t_vector	x_2;
	t_vector	x_3;
	t_vector	x_4;

	x_2.x = pool->p.x - FIGURE[CLS_F].pos.x;
	x_2.y = pool->p.y - FIGURE[CLS_F].pos.y;
	x_2.z = pool->p.z - FIGURE[CLS_F].pos.z;
	x_1 = DOT(FIGURE[CLS_F].dir, x_2);
	x_3.x = x_1 * FIGURE[CLS_F].dir.x;
	x_3.y = x_1 * FIGURE[CLS_F].dir.y;
	x_3.z = x_1 * FIGURE[CLS_F].dir.z;
	x_4.x = x_2.x - x_3.x;
	x_4.y = x_2.y - x_3.y;
	x_4.z = x_2.z - x_3.z;
	NORMAL.x = x_4.x / FIGURE[CLS_F].radius;
	NORMAL.y = x_4.y / FIGURE[CLS_F].radius;
	NORMAL.z = x_4.z / FIGURE[CLS_F].radius;
}
