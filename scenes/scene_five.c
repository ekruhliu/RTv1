/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:26 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 12:24:27 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	init_light(t_pool *pool)
{
	LIGHT = malloc(sizeof(t_light) * 2);
	LIGHT[0].intensity = 0.5;
	LIGHT[0].pos.x = 0;
	LIGHT[0].pos.y = 20;
	LIGHT[0].pos.z = 0;
	LIGHT[1].intensity = 0.5;
	LIGHT[1].pos.x = 0;
	LIGHT[1].pos.y = -5;
	LIGHT[1].pos.z = -20;
	pool->amb_light = 0.1;
	pool->light_int = pool->amb_light;
	pool->light_counter = 2;
}

static	void	part_one(t_pool *pool)
{
	FIGURE[0].pos.x = -5;
	FIGURE[0].pos.y = 5;
	FIGURE[0].pos.z = 5;
	FIGURE[0].radius = 2.0;
	FIGURE[0].green = 0;
	FIGURE[0].blue = 0;
	FIGURE[0].red = 255;
	FIGURE[0].tarnish = 100;
	FIGURE[0].type = 1;
	FIGURE[1].pos.x = 5;
	FIGURE[1].pos.y = 5;
	FIGURE[1].pos.z = 5;
	FIGURE[1].radius = 2.0;
	FIGURE[1].green = 0;
	FIGURE[1].blue = 0;
	FIGURE[1].red = 255;
	FIGURE[1].tarnish = 100;
	FIGURE[1].type = 1;
}

static	void	part_two(t_pool *pool)
{
	FIGURE[2].pos.x = 0;
	FIGURE[2].pos.y = 0;
	FIGURE[2].pos.z = 0;
	FIGURE[2].radius = 2.0;
	FIGURE[2].green = 0;
	FIGURE[2].blue = 0;
	FIGURE[2].red = 255;
	FIGURE[2].tarnish = 100;
	FIGURE[2].type = 1;
	FIGURE[3].pos.x = -3;
	FIGURE[3].pos.y = -5;
	FIGURE[3].pos.z = -3;
	FIGURE[3].radius = 2.0;
	FIGURE[3].green = 0;
	FIGURE[3].blue = 0;
	FIGURE[3].red = 255;
	FIGURE[3].tarnish = 100;
	FIGURE[3].type = 1;
}

static	void	part_three(t_pool *pool)
{
	FIGURE[4].pos.x = 3;
	FIGURE[4].pos.y = -5;
	FIGURE[4].pos.z = -3;
	FIGURE[4].radius = 2.0;
	FIGURE[4].green = 0;
	FIGURE[4].blue = 0;
	FIGURE[4].red = 255;
	FIGURE[4].tarnish = 100;
	FIGURE[4].type = 1;
	FIGURE[5].type = 3;
	FIGURE[5].pos.x = 0;
	FIGURE[5].pos.y = -7;
	FIGURE[5].pos.z = 0;
	FIGURE[5].dir.x = 0;
	FIGURE[5].dir.y = -7;
	FIGURE[5].dir.z = 0;
	FIGURE[5].red = 0;
	FIGURE[5].blue = 150;
	FIGURE[5].green = 95;
	FIGURE[5].tarnish = 100;
}

void			scene_five(t_pool *pool)
{
	init_light(pool);
	FIGURE = malloc(sizeof(t_figure) * 7);
	pool->fig_counter = 7;
	part_one(pool);
	part_two(pool);
	part_three(pool);
	FIGURE[6].type = 3;
	FIGURE[6].pos.x = 0;
	FIGURE[6].pos.y = 0;
	FIGURE[6].pos.z = 10;
	FIGURE[6].dir.x = 0;
	FIGURE[6].dir.y = 0;
	FIGURE[6].dir.z = 10;
	FIGURE[6].red = 0;
	FIGURE[6].blue = 150;
	FIGURE[6].green = 95;
	FIGURE[6].tarnish = 100;
}
