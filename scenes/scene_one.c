/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:24:00 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 12:24:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_one(t_pool *pool)
{
	pool->figure = malloc(sizeof(t_figure) * 1);
	pool->fig_counter = 1;
	pool->figure[0].pos.x = 0;
	pool->figure[0].pos.y = 0;
	pool->figure[0].pos.z = 0;
	pool->figure[0].radius = 2.0;
	pool->figure[0].green = 0;
	pool->figure[0].blue = 0;
	pool->figure[0].red = 255;
	pool->figure[0].tarnish = 100;
	pool->figure[0].type = 1;

	// pool->figure[1].pos.x = 4;
	// pool->figure[1].pos.y = 0;
	// pool->figure[1].pos.z = 0;
	// pool->figure[1].radius = 2.0;
	// pool->figure[1].green = 0;
	// pool->figure[1].blue = 255;
	// pool->figure[1].red = 0;
	// pool->figure[1].tarnish = 100;
	// pool->figure[1].type = 1;

	// pool->figure[2].pos.x = 0;
	// pool->figure[2].pos.y = -2;
	// pool->figure[2].pos.z = 10;
	// pool->figure[2].radius = 6;
	// pool->figure[2].green = 62;
	// pool->figure[2].blue = 127;
	// pool->figure[2].red = 15;
	// pool->figure[2].tarnish = 100;
	// pool->figure[2].type = 1;
}
