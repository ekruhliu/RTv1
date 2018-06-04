/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:57:20 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 18:57:21 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		ret_color(t_pool *pool)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = 0;
	g = 0;
	b = 0;
	if ((pool->figure[pool->cls_figure].red * pool->light_int) > 255)
		r = 255;
	else
		r = pool->figure[pool->cls_figure].red * pool->light_int;
	if ((pool->figure[pool->cls_figure].green * pool->light_int) > 255)
		g = 255;
	else
		g = pool->figure[pool->cls_figure].green * pool->light_int;
	if ((pool->figure[pool->cls_figure].blue * pool->light_int) > 255)
		b = 255;
	else
		b = pool->figure[pool->cls_figure].blue * pool->light_int;
	return ((r << 16) + (g << 8) + b);
}
