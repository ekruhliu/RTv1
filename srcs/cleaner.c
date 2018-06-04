/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:41:37 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/05/16 13:41:38 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	cleaner(t_pool *pool)
{
	SDL_RenderClear(ST_SDL->rend);
	SDL_DestroyWindow(WIN);
	SDL_DestroyRenderer(ST_SDL->rend);
	SDL_DestroyTexture(SCREEN_TEX);
	SDL_Quit();
	free(pool->sdl);
	free(pool->eye);
	free(pool->viewport);
	free(pool->figure);
	free(pool->ray);
	free(pool);
}
