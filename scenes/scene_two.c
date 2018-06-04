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

void	scene_two(t_pool *pool)
{
	pool->figure = malloc(sizeof(t_figure) * 1);
	pool->fig_counter = 1;
	pool->figure[0].type = 2;

	pool->figure[0].pos.x = 0;
	pool->figure[0].pos.y = 0;
	pool->figure[0].pos.z = 0;
	pool->figure[0].dir.x = 0;
	pool->figure[0].dir.y = 1;
	pool->figure[0].dir.z = 0;
	pool->figure[0].radius = 1.5;
	pool->figure[0].red = 0;
	pool->figure[0].green = 255;
	pool->figure[0].blue = 0;
	pool->figure[0].tarnish = 100;
}
