/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:06 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 12:24:07 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	init_light(t_pool *pool)
{
	LIGHT = malloc(sizeof(t_light) * 1);
	LIGHT[0].intensity = 0.4;
	LIGHT[0].pos.x = 6;
	LIGHT[0].pos.y = 0;
	LIGHT[0].pos.z = -6;
	pool->amb_light = 0.1;
	pool->light_int = pool->amb_light;
	pool->light_counter = 1;
}

void			scene_two(t_pool *pool)
{
	init_light(pool);
	FIGURE = malloc(sizeof(t_figure) * 1);
	pool->fig_counter = 1;
	FIGURE[0].type = 2;
	FIGURE[0].pos.x = 0;
	FIGURE[0].pos.y = 0;
	FIGURE[0].pos.z = 0;
	FIGURE[0].dir.x = 0;
	FIGURE[0].dir.y = 1;
	FIGURE[0].dir.z = 0;
	FIGURE[0].radius = 1.5;
	FIGURE[0].red = 0;
	FIGURE[0].green = 255;
	FIGURE[0].blue = 0;
	FIGURE[0].tarnish = 100;
}
