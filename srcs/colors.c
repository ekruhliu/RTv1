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
	RED * pool->light_int > 255 ? pool->red = 255 : 0;
	RED * pool->light_int <= 255 ? pool->red = RED * pool->light_int : 0;
	GREEN * pool->light_int > 255 ? pool->green = 255 : 0;
	GREEN * pool->light_int <= 255 ? pool->green = GREEN * pool->light_int : 0;
	BLUE * pool->light_int > 255 ? pool->blue = 255 : 0;
	BLUE * pool->light_int <= 255 ? pool->blue = BLUE * pool->light_int : 0;
	return (COLORS);
}
