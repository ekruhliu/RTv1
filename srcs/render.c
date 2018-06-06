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
	pool->figure[pool->cls_figure].type == 1 ? find_normal_sphere(pool) : 0;
	pool->figure[pool->cls_figure].type == 2 ? find_normal_cylinder(pool) : 0;
	pool->figure[pool->cls_figure].type == 3 ? find_normal_plane(pool) : 0;
	pool->figure[pool->cls_figure].type == 4 ? find_normal_cone(pool) : 0;
}

int				render(t_pool *pool)
{
	int		i;

	i = -1;
	pool->closest_t = INFINITY;
	pool->cls_figure = -1;
	while (++i < pool->fig_counter)
	{
		intersect_ray_figures(pool, i);
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