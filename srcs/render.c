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
		double		x_1d = 0.0;
		double		x_2m;
		t_vector	x_3a;
		t_vector	x_4v;

		(pool->t1 > pool->t2 ? x_1d = pool->t2 : pool->t1);
		x_3a.x = pool->p.x - pool->figure[pool->cls_figure].pos.x;
		x_3a.y = pool->p.y - pool->figure[pool->cls_figure].pos.y;
		x_3a.z = pool->p.z - pool->figure[pool->cls_figure].pos.z;
		x_2m = DOT(pool->ray, pool->figure[pool->cls_figure].dir) * x_1d + DOT(x_3a, pool->figure[pool->cls_figure].dir);
		x_4v.x = pool->figure[pool->cls_figure].dir.x;
		x_4v.y = pool->figure[pool->cls_figure].dir.y;
		x_4v.z = pool->figure[pool->cls_figure].dir.z;
		x_4v.x *= x_2m;
		x_4v.y *= x_2m;
		x_4v.z *= x_2m;
		pool->normal.x = x_3a.x - x_4v.x;
		pool->normal.y = x_3a.y - x_4v.y;
		pool->normal.z = x_3a.z - x_4v.z;

		double inv = 1 / X1;
		pool->normal.x *= inv;
		pool->normal.y *= inv;
		pool->normal.z *= inv;
		
		// printf("%f\n", X1);
	}
}

int				render(t_pool *pool)
{
	int i;

	i = -1;
	pool->closest_t = INFINITY;
	pool->cls_figure = -1;
	while (++i < pool->fig_counter)
	{
		(pool->figure[i].type == 1 ? intersect_ray_sphere(pool, i) : 0);
		(pool->figure[i].type == 2 ? intersect_ray_cylinder(pool, i) : 0);
		//cone
		//cyl *
		//plane
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
	pool->v.x = pool->ray.x * -1;
	pool->v.y = pool->ray.y * -1;
	pool->v.z = pool->ray.z * -1;
	intersection(pool);
	find_normal(pool);
	create_light(pool);
	return (ret_color(pool));
}