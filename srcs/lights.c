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

static	void	amb_light(t_pool *pool, int i)
{
	if (pool->light[i].intensity > 0.0)
		pool->light_int += pool->light[i].intensity;
}

static	void	find_r(t_pool *pool, double	n_dot_l)
{
	pool->r.x = 2 * pool->normal.x * n_dot_l - pool->l.x;
	pool->r.y = 2 * pool->normal.y * n_dot_l - pool->l.y;
	pool->r.z = 2 * pool->normal.z * n_dot_l - pool->l.z;
}

static	void	find_v(t_pool *pool)
{
	pool->v.x = pool->ray.x;
	pool->v.y = pool->ray.y;
	pool->v.z = pool->ray.z;
	pool->v.x *= -1;
	pool->v.y *= -1;
	pool->v.z *= -1;
}

void	create_light(t_pool *pool)
{
	double	n_dot_l;
	double	r_dot_v;
	int		i;

	pool->light_int = 0.0;
	i = -1;
	find_v(pool);
	while (++i < pool->light_counter)
	{
		if (pool->light[i].type == 1)
			amb_light(pool, i);
		else
		{
			pool->l.x = pool->light[i].pos.x - pool->p.x;
			pool->l.y = pool->light[i].pos.y - pool->p.y;
			pool->l.z = pool->light[i].pos.z - pool->p.z;
			
			create_shadow(pool);
			if (pool->sdw_figure != -1)
				continue ;
			n_dot_l = DOT(pool->normal, pool->l);
			if (n_dot_l > 0)
				pool->light_int += pool->light[i].intensity * n_dot_l / (X1 * X2);
			if (pool->figure[pool->cls_figure].tarnish != -1)
			{
				// // double x;

				// find_r(pool, n_dot_l);
				// pool->v.x = pool->ray.x * -1;
				// pool->v.y = pool->ray.y * -1;
				// pool->v.z = pool->ray.z * -1;
				// r_dot_v = DOT(pool->r, pool->v);
				// if (r_dot_v > 0)
				// 	pool->light_int += pool->light[i].intensity * pow(r_dot_v / (X3 * X4), pool->figure->tarnish); 
				find_r(pool, n_dot_l);
				r_dot_v = DOT(pool->r, pool->v);
				if (r_dot_v > 0)
					pool->light_int += pool->light[i].intensity * pow(r_dot_v / (X3 * X4), pool->figure->tarnish);
			}
			// if (pool->figure[pool->cls_figure].type != 3)
			// {
			// 	if (pool->figure[pool->cls_figure].tarnish != -1)
			// 	{
			// 		if (pool->figure[pool->cls_figure].tarnish != -1)
			// 		{
			// 			find_r(pool, n_dot_l);
			// 			r_dot_v = DOT(pool->r, pool->v);
			// 			if (r_dot_v > 0)
			// 				pool->light_int += pool->light[i].intensity * pow(r_dot_v / (X3 * X4), pool->figure->tarnish);
			// 		}
					// double x;

					// find_r(pool, n_dot_l);
					// pool->v.x = pool->ray.x * -1;
					// pool->v.y = pool->ray.y * -1;
					// pool->v.z = pool->ray.z * -1;
					// x = DOT(pool->r, pool->v);
					// if (x > 0)
					// 	pool->light_int += pool->light[i].intensity * pow(x / (X3 * X4), pool->figure->tarnish); 
				// }
			// }
		}
	}
}
