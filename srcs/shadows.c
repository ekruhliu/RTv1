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
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_cone(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;
	double	cone_radiana;
	t_vector	cone;

	cone.x = pool->l.x;
	cone.y = pool->l.y;
	cone.z = pool->l.z;
	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	cone_radiana = tan((pool->figure[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(cone_radiana, 2)) * pow(DOT(cone, pool->figure[i].dir), 2);
	x2 = 2 * (DOT(cone, pool->coord) - (1 + pow(cone_radiana, 2)) * DOT(cone, pool->figure[i].dir) * (DOT(pool->coord, pool->figure[i].dir)));
	x3 = DOT(pool->coord, pool->coord) - (1 + pow(cone_radiana, 2)) * pow(DOT(pool->coord, pool->figure[i].dir), 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	else
	{
		pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
		pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
	}
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

int	intersect_shadow_plane(t_pool *pool, int i)
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
	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	// printf("X_x = %f\n", pool->coord.x);
	// printf("X_y = %f\n", pool->coord.y);
	// printf("X_z = %f\n", pool->coord.z);
	copy_1.x = pool->l.x;
	copy_1.y = pool->l.y;
	copy_1.z = pool->l.z;
	// printf("q copy_1_x = %f\n", copy_1.x);
	// printf("q copy_1_y = %f\n", copy_1.y);
	// printf("q copy_1_z = %f\n", copy_1.z);
	copy_2.x = pool->figure[i].dir.x;
	copy_2.y = pool->figure[i].dir.y;
	copy_2.z = pool->figure[i].dir.z;
	// printf("v copy_2_x = %f\n", copy_2.x);
	// printf("v copy_2_y = %f\n", copy_2.y);
	// printf("v copy_2_z = %f\n", copy_2.z);
	pool->coord.x *= -1;
	pool->coord.y *= -1;
	pool->coord.z *= -1;
	// printf("2_X_x = %f\n", pool->coord.x);
	// printf("2_X_y = %f\n", pool->coord.y);
	// printf("2_X_z = %f\n", pool->coord.z);
	x1 = DOT(pool->coord, copy_2) / DOT(copy_1, copy_2);
	// printf("t x1 = %f\n", x1);
	copy_2.x *= -1;
	copy_2.y *= -1;
	copy_2.z *= -1;
	// printf("2_v copy_2_x = %f\n", copy_2.x);
	// printf("2_v copy_2_y = %f\n", copy_2.y);
	// printf("2_v copy_2_z = %f\n", copy_2.z);
	pool->normal.x = copy_2.x;
	pool->normal.y = copy_2.y;
	pool->normal.z = copy_2.z;
	// printf("normal_x = %f\n", pool->normal.x);
	// printf("normal_y = %f\n", pool->normal.y);
	// printf("normal_z = %f\n", pool->normal.z);
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

void	create_shadow(t_pool *pool)
{
	int		i;
	double	x;

	i = -1;
	x = 0.0;
	pool->shadow_t = INFINITY;
	pool->sdw_figure = -1;
	while (++i < pool->fig_counter)
	{
		(pool->figure[i].type == 1 ? intersect_shadow_sphere(pool, i) : 0);
		(pool->figure[i].type == 2 ? intersect_shadow_cylinder(pool, i) : 0);
		if (pool->figure[i].type == 3)
		{
			x = intersect_shadow_plane(pool, i);
			if (x > 0.0001 && x < 1 && x < pool->shadow_t)
				pool->sdw_figure = i;
		// 	{
		// 		// pool->shadow_t = x;
		// 		
		// 	}
			continue ;
		}
		(pool->figure[i].type == 4 ? intersect_shadow_cone(pool, i) : 0);
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
