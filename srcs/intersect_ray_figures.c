/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_figures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:58:17 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 18:58:17 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
	x3 = DOT(pool->coord, pool->coord) - RADIUS * RADIUS;
	discriminant = x2 * x2 - 4 * x1 * x3;
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

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