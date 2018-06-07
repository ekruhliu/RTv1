/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:01 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:02 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_sphere(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;

	COORD.x = pool->cam.x - pool->figure[i].pos.x;
	COORD.y = pool->cam.y - pool->figure[i].pos.y;
	COORD.z = pool->cam.z - pool->figure[i].pos.z;
	x1 = DOT(pool->ray, pool->ray);
	x2 = 2 * DOT(COORD, pool->ray);
	x3 = DOT(COORD, COORD) - (RADIUS * RADIUS);
	discriminant = (x2 * x2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_sphere(t_pool *pool, int i)
{
	double	x1;
	double	x2;
	double	x3;
	double	discriminant;

	COORD.x = pool->p.x - pool->figure[i].pos.x;
	COORD.y = pool->p.y - pool->figure[i].pos.y;
	COORD.z = pool->p.z - pool->figure[i].pos.z;
	x1 = DOT(pool->l, pool->l);
	x2 = 2 * DOT(COORD, pool->l);
	x3 = DOT(COORD, COORD) - (RADIUS * RADIUS);
	discriminant = (x2 * x2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	find_normal_sphere(t_pool *pool)
{
	NORMAL.x = pool->p.x - pool->figure[CLS_F].pos.x;
	NORMAL.y = pool->p.y - pool->figure[CLS_F].pos.y;
	NORMAL.z = pool->p.z - pool->figure[CLS_F].pos.z;
	NORMAL.x /= X6;
	NORMAL.y /= X6;
	NORMAL.z /= X6;
}
