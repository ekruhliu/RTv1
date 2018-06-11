/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:21 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 12:24:21 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	init_light(t_pool *pool)
{
	LIGHT = malloc(sizeof(t_light) * 2);
	LIGHT[0].intensity = 0.6;
	LIGHT[0].pos.x = 6;
	LIGHT[0].pos.y = 0;
	LIGHT[0].pos.z = -6;
	LIGHT[1].intensity = 0.6;
	LIGHT[1].pos.x = -6;
	LIGHT[1].pos.y = 0;
	LIGHT[1].pos.z = -6;
	pool->amb_light = 0.0;
	pool->light_int = pool->amb_light;
	pool->light_counter = 2;
}

static	void	part_one(t_pool *pool)
{
	FIGURE[0].type = 4;
	FIGURE[0].pos.x = 0;
	FIGURE[0].pos.y = 0;
	FIGURE[0].pos.z = 0;
	FIGURE[0].green = 0;
	FIGURE[0].blue = 130;
	FIGURE[0].red = 190;
	FIGURE[0].dir.x = 0;
	FIGURE[0].dir.y = 1;
	FIGURE[0].dir.z = 0;
	FIGURE[0].radius = 1;
	FIGURE[0].tarnish = 1000;
	FIGURE[0].angle = 40;
	FIGURE[1].type = 2;
	FIGURE[1].pos.x = -8;
	FIGURE[1].pos.y = 0;
	FIGURE[1].pos.z = 8;
	FIGURE[1].dir.x = 0;
	FIGURE[1].dir.y = 1;
	FIGURE[1].dir.z = 0;
	FIGURE[1].radius = 1.8;
	FIGURE[1].red = 0;
	FIGURE[1].green = 255;
	FIGURE[1].blue = 0;
	FIGURE[1].tarnish = 100;
}

static	void	part_two(t_pool *pool)
{
	FIGURE[2].type = 2;
	FIGURE[2].pos.x = 8;
	FIGURE[2].pos.y = 0;
	FIGURE[2].pos.z = 8;
	FIGURE[2].dir.x = 0;
	FIGURE[2].dir.y = 1;
	FIGURE[2].dir.z = 0;
	FIGURE[2].radius = 1.8;
	FIGURE[2].red = 0;
	FIGURE[2].green = 0;
	FIGURE[2].blue = 255;
	FIGURE[2].tarnish = 100;
	FIGURE[3].pos.x = 0;
	FIGURE[3].pos.y = 0;
	FIGURE[3].pos.z = 0;
	FIGURE[3].radius = 0.4;
	FIGURE[3].green = 70;
	FIGURE[3].blue = 0;
	FIGURE[3].red = 255;
	FIGURE[3].tarnish = 100;
	FIGURE[3].type = 1;
}

void			scene_four(t_pool *pool)
{
	init_light(pool);
	FIGURE = malloc(sizeof(t_figure) * 5);
	pool->fig_counter = 5;
	part_one(pool);
	part_two(pool);
	FIGURE[4].type = 3;
	FIGURE[4].pos.x = 0;
	FIGURE[4].pos.y = -12;
	FIGURE[4].pos.z = 0;
	FIGURE[4].dir.x = 0;
	FIGURE[4].dir.y = -12;
	FIGURE[4].dir.z = 0;
	FIGURE[4].red = 255;
	FIGURE[4].blue = 255;
	FIGURE[4].green = 255;
	FIGURE[4].tarnish = 100;
}
