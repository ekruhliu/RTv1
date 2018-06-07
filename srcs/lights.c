/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:57:30 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 18:57:30 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	amb_light(t_pool *pool)
{
	if (pool->amb_light > 0.0)
		LIGHT_INT = pool->amb_light;
}

static	void	find_r(t_pool *pool, double n_dot_l)
{
	pool->r.x = 2 * pool->normal.x * n_dot_l - pool->l.x;
	pool->r.y = 2 * pool->normal.y * n_dot_l - pool->l.y;
	pool->r.z = 2 * pool->normal.z * n_dot_l - pool->l.z;
}

static	void	find_v(t_pool *pool)
{
	pool->v = pool->ray;
	pool->v.x *= -1;
	pool->v.y *= -1;
	pool->v.z *= -1;
	amb_light(pool);
}

static	void	find_l(t_pool *pool, int i)
{
	pool->l.x = LIGHT[i].pos.x - pool->p.x;
	pool->l.y = LIGHT[i].pos.y - pool->p.y;
	pool->l.z = LIGHT[i].pos.z - pool->p.z;
}

void			create_light(t_pool *pool)
{
	double	n_dot_l;
	double	r_dot_v;
	int		i;

	LIGHT_INT = 0.0;
	i = -1;
	find_v(pool);
	while (++i < pool->light_counter)
	{
		find_l(pool, i);
		create_shadow(pool);
		if (pool->sdw_figure != -1)
			continue ;
		n_dot_l = DOT(pool->normal, pool->l);
		(n_dot_l > 0 ? LIGHT_INT += X19 : 0);
		if (FIGURE[pool->cls_figure].type != 3)
		{
			if (FIGURE[pool->cls_figure].tarnish != -1)
			{
				find_r(pool, n_dot_l);
				r_dot_v = DOT(pool->r, pool->v);
				(r_dot_v > 0 ? LIGHT_INT += X20 : 0);
			}
		}
	}
}
