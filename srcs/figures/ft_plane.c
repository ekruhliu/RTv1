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

	COORD.x = pool->cam.x - FIGURE[i].pos.x;
	COORD.y = pool->cam.y - FIGURE[i].pos.y;
	COORD.z = pool->cam.z - FIGURE[i].pos.z;
	x1 = DOT(-COORD, FIGURE[i].dir) / DOT(pool->ray, FIGURE[i].dir);
	if (x1 > 1 && x1 < INFINITY && x1 < pool->closest_t)
	{
		pool->closest_t = x1;
		CLS_F = i;
	}
}

void	intersect_shadow_plane(t_pool *pool, int i)
{
	double	x1;

	COORD.x = pool->p.x - FIGURE[i].pos.x;
	COORD.y = pool->p.y - FIGURE[i].pos.y;
	COORD.z = pool->p.z - FIGURE[i].pos.z;
	x1 = DOT(-COORD, FIGURE[i].dir) / DOT(pool->ray, FIGURE[i].dir);
	if (x1 > 1 && x1 < INFINITY && x1 < pool->shadow_t)
	{
		pool->shadow_t = x1;
		pool->sdw_figure = i;
	}
}

void	find_normal_plane(t_pool *pool)
{
	NORMAL = FIGURE[CLS_F].dir;
	NORMAL.x *= -1;
	NORMAL.y *= -1;
	NORMAL.z *= -1;
}
