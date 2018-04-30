/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:02:28 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/26 10:02:29 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int	main(int argc, char **argv)
{
	t_pool	*pool;

	if (argc > 1 && argv[1])
	{
		pool = malloc(sizeof(t_pool));
		pool->done = SDL_FALSE;
		initialization(pool);
		while (!DONE)
		{
			SDL_SetRenderDrawColor(pool->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderPresent(pool->rend);
			SDL_RenderClear(pool->rend);
			KEY_STATE = SDL_GetKeyboardState(NULL);
			SDL_PollEvent(&pool->event);
			(KEY_STATE[SDL_SCANCODE_ESCAPE]) ? DONE = SDL_TRUE : (0);
			(EVENT_TYPE == SDL_QUIT) ? DONE = SDL_TRUE : (0);
		}
		SDL_DestroyWindow(WIN);
		SDL_DestroyRenderer(pool->rend);
		SDL_DestroyTexture(pool->screen_tex);
		SDL_Quit();
	}
}
