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
	else
	{
		pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
		pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
	}
}

void	intersect_ray_cone(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;
	double	cone_radiana;
	t_vector	cone;

	cone.x = pool->ray.x;
	cone.y = pool->ray.y;
	cone.z = pool->ray.z;
	pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	cone_radiana = tan((pool->figure[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(cone_radiana, 2)) * pow(DOT(cone, pool->figure[i].dir), 2);
	x2 = 2 * (DOT(cone, pool->coord) - (1 + pow(cone_radiana, 2)) * DOT(cone, pool->figure[i].dir) * (DOT(pool->coord, pool->figure[i].dir)));
	x3 = DOT(pool->coord, pool->coord) - (1 + pow(cone_radiana, 2)) * pow(DOT(pool->coord, pool->figure[i].dir), 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	else
	{
		pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
		pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
	}
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

int	intersect_ray_plane(t_pool *pool, int i)
{
	double	x1;
	t_vector copy_1;
	t_vector copy_2;
	// double	x2;
	// double	x3;
	// double	discriminant;

	// pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	// pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	// pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	copy_1.x = pool->ray.x;
	copy_1.y = pool->ray.y;
	copy_1.z = pool->ray.z;
	copy_2.x = pool->figure[i].dir.x;
	copy_2.y = pool->figure[i].dir.y;
	copy_2.z = pool->figure[i].dir.z;
	double inv = 1 / X5;
	copy_2.x *= inv;
	copy_2.y *= inv;
	copy_2.z *= inv;
	pool->coord.x *= -1;
	pool->coord.y *= -1;
	pool->coord.z *= -1;
	x1 = DOT(pool->coord, copy_2) / DOT(copy_1, copy_2);
	copy_2.x *= -1;
	copy_2.y *= -1;
	copy_2.z *= -1;
	pool->normal.x = copy_2.x;
	pool->normal.y = copy_2.y;
	pool->normal.z = copy_2.z;
	return (x1);
	// if (x1 > 1 && x1 < INFINITY && x1 < pool->closest_t)
	// {
	// 	pool->closest_t = x1;
	// 	return (i);
	// 	// pool->cls_fidure = i;
	// }
	// return (0);
	// x2 = 2 * DOT(pool->coord, pool->ray);
	// x3 = DOT(pool->coord, pool->coord) - RADIUS * RADIUS;
	// discriminant = x2 * x2 - 4 * x1 * x3;
	// if (discriminant < 0)
	// {
	// 	pool->t1 = INFINITY;
	// 	pool->t2 = INFINITY;
	// }
	// pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	// pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}