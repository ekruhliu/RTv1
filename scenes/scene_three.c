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

void	scene_three(t_pool *pool)
{
	pool->figure = malloc(sizeof(t_figure) * 1);
	pool->fig_counter = 1; //6

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
	pool->figure[0].angle = 50;

	// pool->figure[1].type = 3;
	// pool->figure[1].pos.x = 0;
	// pool->figure[1].pos.y = -4;
	// pool->figure[1].pos.z = 1;
	// pool->figure[1].dir.x = 0;
	// pool->figure[1].dir.y = -4;
	// pool->figure[1].dir.z = 1;
	// pool->figure[1].red = 0;
	// pool->figure[1].blue = 0;
	// pool->figure[1].green = 210;
	// pool->figure[1].tarnish = 100;

	// pool->figure[0].pos.x = 0;//-4;
	// pool->figure[0].pos.y = 0;//-2;
	// pool->figure[0].pos.z = 0;
	// pool->figure[0].radius = 2.5;
	// pool->figure[0].green = 0;
	// pool->figure[0].blue = 130;
	// pool->figure[0].red = 190;
	// pool->figure[0].tarnish = 100;
	// pool->figure[0].type = 1;

	// pool->figure[1].pos.x = 4;
	// pool->figure[1].pos.y = -2;
	// pool->figure[1].pos.z = 0;
	// pool->figure[1].radius = 2.0;
	// pool->figure[1].green = 70;
	// pool->figure[1].blue = 0;
	// pool->figure[1].red = 240;
	// pool->figure[1].tarnish = 100;
	// pool->figure[1].type = 1;

	// // pool->figure[2].pos.x = 0;
	// // pool->figure[2].pos.y = -2;
	// // pool->figure[2].pos.z = 10;
	// // pool->figure[2].radius = 6;
	// // pool->figure[2].green = 62;
	// // pool->figure[2].blue = 127;
	// // pool->figure[2].red = 15;
	// // pool->figure[2].tarnish = 100;
	// // pool->figure[2].type = 1;

	// pool->figure[2].type = 3;
	// pool->figure[2].pos.x = 0;
	// pool->figure[2].pos.y = -2;
	// pool->figure[2].pos.z = 5;
	// pool->figure[2].dir.x = 0;
	// pool->figure[2].dir.y = 0;
	// pool->figure[2].dir.z = 1;
	// pool->figure[2].red = 210;
	// pool->figure[2].blue = 0;
	// pool->figure[2].green = 0;
	// pool->figure[2].tarnish = 1000;

	// pool->figure[3].type = 3;
	// pool->figure[3].pos.x = 0;
	// pool->figure[3].pos.y = 4;
	// pool->figure[3].pos.z = 1;
	// pool->figure[3].dir.x = 0;
	// pool->figure[3].dir.y = 4;
	// pool->figure[3].dir.z = 1;
	// pool->figure[3].red = 0;
	// pool->figure[3].blue = 210;
	// pool->figure[3].green = 0;
	// pool->figure[3].tarnish = 1000;

	// pool->figure[4].type = 3;
	// pool->figure[4].pos.x = 0;
	// pool->figure[4].pos.y = -4;
	// pool->figure[4].pos.z = 5;
	// pool->figure[4].dir.x = 0;
	// pool->figure[4].dir.y = -4;
	// pool->figure[4].dir.z = 1;
	// pool->figure[4].red = 0;
	// pool->figure[4].blue = 0;
	// pool->figure[4].green = 210;
	// pool->figure[4].tarnish = 1000;
}

