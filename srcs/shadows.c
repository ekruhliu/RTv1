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

void	create_shadow(t_pool *pool)
{
	int		i;

	i = -1;
	pool->shadow_t = INFINITY;
	pool->sdw_figure = -1;
	while (++i < pool->fig_counter)
	{
		intersect_shadow_figures(pool, i);
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
