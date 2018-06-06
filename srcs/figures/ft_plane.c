/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:23 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:24 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_plane(t_pool *pool, int i)
{
	double	x1;

	pool->coord.x = pool->cam.x - pool->figure[i].pos.x;
	pool->coord.y = pool->cam.y - pool->figure[i].pos.y;
	pool->coord.z = pool->cam.z - pool->figure[i].pos.z;
	x1 = DOT(-pool->coord, pool->figure[i].dir) / DOT(pool->ray, pool->figure[i].dir);
	if (x1 > 1 && x1 < INFINITY && x1 < pool->closest_t)
	{
		pool->closest_t = x1;
		pool->cls_figure = i;
	}
}

void	intersect_shadow_plane(t_pool *pool, int i)
{
	double	x1;

	pool->coord.x = pool->p.x - pool->figure[i].pos.x;
	pool->coord.y = pool->p.y - pool->figure[i].pos.y;
	pool->coord.z = pool->p.z - pool->figure[i].pos.z;
	x1 = DOT(-pool->coord, pool->figure[i].dir) / DOT(pool->ray, pool->figure[i].dir);
	if (x1 > 1 && x1 < INFINITY && x1 < pool->shadow_t)
	{
		pool->shadow_t = x1;
		pool->sdw_figure = i;
	}
}

void	find_normal_plane(t_pool *pool)
{
	pool->normal = pool->figure[pool->cls_figure].dir;
	pool->normal.x *= -1;
	pool->normal.y *= -1;
	pool->normal.z *= -1;
}
