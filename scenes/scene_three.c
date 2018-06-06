/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:12 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 12:24:12 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	init_light(t_pool *pool)
{
	pool->light = malloc(sizeof(t_light) * 1);
	pool->light[0].intensity = 0.6;
	pool->light[0].pos.x = 6;
	pool->light[0].pos.y = 0;
	pool->light[0].pos.z = -6;
	pool->amb_light = 0.1;
	pool->light_int = pool->amb_light;
	pool->light_counter = 1;
}

static	void	part_one(t_pool *pool)
{
	pool->figure[0].type = 4;
	pool->figure[0].pos.x = 0;
	pool->figure[0].pos.y = 0;
	pool->figure[0].pos.z = 0;
	pool->figure[0].green = 0;
	pool->figure[0].blue = 130;
	pool->figure[0].red = 190;
	pool->figure[0].dir.x = 0;
	pool->figure[0].dir.y = 1;
	pool->figure[0].dir.z = 0;
	pool->figure[0].radius = 1;
	pool->figure[0].tarnish = 1000;
	pool->figure[0].angle = 70;
}

void	scene_three(t_pool *pool)
{
	init_light(pool);
	pool->figure = malloc(sizeof(t_figure) * 2);
	pool->fig_counter = 2;
	part_one(pool);
	pool->figure[1].type = 3;
	pool->figure[1].pos.x = 0;
	pool->figure[1].pos.y = -3;
	pool->figure[1].pos.z = 0;
	pool->figure[1].dir.x = 0;
	pool->figure[1].dir.y = -3;
	pool->figure[1].dir.z = 0;
	pool->figure[1].red = 0;
	pool->figure[1].blue = 0;
	pool->figure[1].green = 150;
	pool->figure[1].tarnish = 100;
}

