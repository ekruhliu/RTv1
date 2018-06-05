/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:00:03 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/05/16 14:00:03 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	intersection(t_pool *pool)
{
	pool->p.x = pool->cam.x + (pool->closest_t * pool->ray.x);
	pool->p.y = pool->cam.y + (pool->closest_t * pool->ray.y);
	pool->p.z = pool->cam.z + (pool->closest_t * pool->ray.z);
}

static	void	find_normal(t_pool *pool)
{
	double		x_1;
	t_vector	x_2;
	t_vector	x_3;
	t_vector	x_4;
	t_vector	x_5;
	double		x_6;
	double		x_7;
	double		x_8;

	if (pool->figure[pool->cls_figure].type == 1)
	{
		pool->normal.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
		pool->normal.y = pool->p.y - pool->figure[pool->cls_figure].pos.y;
		pool->normal.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
		pool->normal.x /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
		pool->normal.y /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
		pool->normal.z /= (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)));
	}
	if (pool->figure[pool->cls_figure].type == 2)
	{
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
	if (pool->figure[pool->cls_figure].type == 3)
	{
		pool->normal.x = pool->figure[pool->cls_figure].dir.x;
		pool->normal.y = pool->figure[pool->cls_figure].dir.y;
		pool->normal.z = pool->figure[pool->cls_figure].dir.z;
		pool->normal.x *= -1;
		pool->normal.y *= -1;
		pool->normal.z *= -1;
	}
	if (pool->figure[pool->cls_figure].type == 4)
	{
		x_2.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
		x_2.y = pool->p.y - pool->figure[pool->cls_figure].pos.y; // b
		x_2.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
		x_6 = (sqrt(pow(x_2.x, 2) + pow(x_2.y, 2) + pow(x_2.z, 2)));
		x_7 = (sqrt(pow(pool->figure[pool->cls_figure].dir.x, 2) + pow(pool->figure[pool->cls_figure].dir.y, 2) + pow(pool->figure[pool->cls_figure].dir.z, 2)));
		x_8 = ((x_2.x * pool->figure[pool->cls_figure].dir.x) + (x_2.y * pool->figure[pool->cls_figure].dir.y) + (x_2.z * pool->figure[pool->cls_figure].dir.z));
		x_1 = (x_8 / (x_6 * x_7));
		x_3.x = x_1 * pool->figure[pool->cls_figure].dir.x;
		x_3.y = x_1 * pool->figure[pool->cls_figure].dir.y; // a
		x_3.z = x_1 * pool->figure[pool->cls_figure].dir.z;
		x_4.x = x_2.x - x_3.x;
		x_4.y = x_2.y - x_3.y; // n
		x_4.z = x_2.z - x_3.z;

		// c.x = (a->y * b->z) - (a->z * b->y);
		// c.y = (a->x * b->z) - (a->z * b->x);
		// c.z = (a->x * b->y) - (a->y * b->x);

		x_5.x = (x_2.y * x_4.z) - (x_2.z * x_4.y);
		x_5.y = (x_2.x * x_4.z) - (x_2.z * x_4.x);
		x_5.z = (x_2.x * x_4.y) - (x_2.y * x_4.x);
		
		x_4.x = (x_5.y * x_2.z) - (x_5.z * x_2.y);
		x_4.y = (x_5.x * x_2.z) - (x_5.z * x_2.x);
		x_4.z = (x_5.x * x_2.y) - (x_5.y * x_2.x);
		pool->normal.x = x_4.x / X8;
		pool->normal.y = x_4.y / X8;
		pool->normal.z = x_4.z / X8;
	}
}

int				render(t_pool *pool)
{
	int		i;
	double	x;

	i = -1;
	x = 0.0;
	pool->closest_t = INFINITY;
	pool->cls_figure = -1;
	while (++i < pool->fig_counter)
	{
		(pool->figure[i].type == 1 ? intersect_ray_sphere(pool, i) : 0);
		(pool->figure[i].type == 2 ? intersect_ray_cylinder(pool, i) : 0);
		(pool->figure[i].type == 4 ? intersect_ray_cone(pool, i) : 0);
		if (pool->figure[i].type == 3)
		{
			x = intersect_ray_plane(pool, i);
			if (x > 1 && x < INFINITY && x < pool->closest_t)
			{
				pool->closest_t = x;
				pool->cls_figure = i;
			}
			continue ;
		}
		if (pool->t1 > 1 && pool->t1 < INFINITY && pool->t1 < pool->closest_t)
		{
			pool->closest_t = pool->t1;
			pool->cls_figure = i;
		}
		if (pool->t2 > 1 && pool->t2 < INFINITY && pool->t2 < pool->closest_t)
		{
			pool->closest_t = pool->t2;
			pool->cls_figure = i;
		}
	}
	if (pool->cls_figure == -1)
		return (0);
	intersection(pool);
	find_normal(pool);
	create_light(pool);
	return (ret_color(pool));
}