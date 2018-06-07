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
	LIGHT = malloc(sizeof(t_light) * 1);
	LIGHT[0].intensity = 0.6;
	LIGHT[0].pos.x = 6;
	LIGHT[0].pos.y = 0;
	LIGHT[0].pos.z = -6;
	pool->amb_light = 0.1;
	pool->light_int = pool->amb_light;
	pool->light_counter = 1;
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
	FIGURE[0].angle = 70;
}

void			scene_three(t_pool *pool)
{
	init_light(pool);
	FIGURE = malloc(sizeof(t_figure) * 2);
	pool->fig_counter = 2;
	part_one(pool);
	FIGURE[1].type = 3;
	FIGURE[1].pos.x = 0;
	FIGURE[1].pos.y = -3;
	FIGURE[1].pos.z = 0;
	FIGURE[1].dir.x = 0;
	FIGURE[1].dir.y = -3;
	FIGURE[1].dir.z = 0;
	FIGURE[1].red = 0;
	FIGURE[1].blue = 0;
	FIGURE[1].green = 150;
	FIGURE[1].tarnish = 100;
}
