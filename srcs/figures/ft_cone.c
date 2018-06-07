/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:46:18 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/06 12:46:18 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../rtv1.h"

void	intersect_ray_cone(t_pool *pool, int i)
{
	double		x1;
	double		x2;
	double		x3;
	double		discriminant;
	t_vector	cone;

	cone = pool->ray;
	COORD.x = pool->cam.x - FIGURE[i].pos.x;
	COORD.y = pool->cam.y - FIGURE[i].pos.y;
	COORD.z = pool->cam.z - FIGURE[i].pos.z;
	RAD = tan((FIGURE[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(RAD, 2)) * pow(X11, 2);
	x2 = 2 * (DOT(cone, COORD) - (1 + pow(RAD, 2)) * (X11 * (X12)));
	x3 = DOT(COORD, COORD) - (1 + pow(RAD, 2)) * pow(X12, 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	intersect_shadow_cone(t_pool *pool, int i)
{
	double		x1;
	double		x2;
	double		x3;
	double		discriminant;
	t_vector	cone;

	cone = pool->l;
	COORD.x = pool->p.x - FIGURE[i].pos.x;
	COORD.y = pool->p.y - FIGURE[i].pos.y;
	COORD.z = pool->p.z - FIGURE[i].pos.z;
	RAD = tan((FIGURE[i].angle / 2) * 3.14 / 180);
	x1 = DOT(cone, cone) - (1 + pow(RAD, 2)) * pow(X11, 2);
	x2 = 2 * (DOT(cone, COORD) - (1 + pow(RAD, 2)) * (X11 * (X12)));
	x3 = DOT(COORD, COORD) - (1 + pow(RAD, 2)) * pow(X12, 2);
	discriminant = pow(x2, 2) - (4 * x1 * x3);
	if (discriminant < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	pool->sdw_t1 = (-x2 + sqrt(discriminant)) / (2 * x1);
	pool->sdw_t2 = (-x2 - sqrt(discriminant)) / (2 * x1);
}

void	find_normal_cone(t_pool *pool)
{
	VAR = malloc(sizeof(t_variable));
	VAR->x2.x = pool->p.x - FIGURE[CLS_F].pos.x;
	VAR->x2.y = pool->p.y - FIGURE[CLS_F].pos.y;
	VAR->x2.z = pool->p.z - FIGURE[CLS_F].pos.z;
	VAR->x6 = (sqrt(pow(VAR->x2.x, 2) + pow(VAR->x2.y, 2) + pow(VAR->x2.z, 2)));
	VAR->x7 = (sqrt(X13 + X14 + X15));
	VAR->x8 = (X16 + X17 + X18);
	VAR->x1 = (VAR->x8 / (VAR->x6 * VAR->x7));
	VAR->x3.x = VAR->x1 * FIGURE[CLS_F].dir.x;
	VAR->x3.y = VAR->x1 * FIGURE[CLS_F].dir.y;
	VAR->x3.z = VAR->x1 * FIGURE[CLS_F].dir.z;
	VAR->x4.x = VAR->x2.x - VAR->x3.x;
	VAR->x4.y = VAR->x2.y - VAR->x3.y;
	VAR->x4.z = VAR->x2.z - VAR->x3.z;
	VAR->x5.x = (VAR->x2.y * VAR->x4.z) - (VAR->x2.z * VAR->x4.y);
	VAR->x5.y = (VAR->x2.x * VAR->x4.z) - (VAR->x2.z * VAR->x4.x);
	VAR->x5.z = (VAR->x2.x * VAR->x4.y) - (VAR->x2.y * VAR->x4.x);
	VAR->x4.x = (VAR->x5.y * VAR->x2.z) - (VAR->x5.z * VAR->x2.y);
	VAR->x4.y = (VAR->x5.z * VAR->x2.x) - (VAR->x5.x * VAR->x2.z);
	VAR->x4.z = (VAR->x5.x * VAR->x2.y) - (VAR->x5.y * VAR->x2.x);
	NORMAL.x = VAR->x4.x / (X8);
	NORMAL.y = VAR->x4.y / (X8);
	NORMAL.z = VAR->x4.z / (X8);
	free(VAR);
}
