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

static	void	part_one(t_pool *pool, char *argv)
{
	ST_SDL = malloc(sizeof(t_sdl));
	DONE = SDL_FALSE;
	initialization(pool);
	if (ft_atoi(argv) == 1)
	{
		scene_one(pool);
		ft_putstr("\033[1;34mAdd figure position in format: X Y Z\n\e[m");
		ft_putstr("\033[1;34mOr press ENTER to add default position\n\e[m");
		check_standart_input(pool);
	}
	if (ft_atoi(argv) == 2)
		scene_two(pool);
	if (ft_atoi(argv) == 3)
		scene_three(pool);
	if (ft_atoi(argv) == 4)
		scene_four(pool);
	if (ft_atoi(argv) == 5)
		scene_five(pool);
	ST_SDL->scene = malloc(sizeof(int) * (W * H));
}

static	void	part_two(t_pool *pool)
{
	int y;
	int x;
	int i;

	y = 0;
	i = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pool->ray.x = (x - DEC_W) * pool->viewport.x / W;
			pool->ray.y = (DEC_H - y) * pool->viewport.y / H;
			pool->ray.z = 1;
			ST_SDL->scene[i] = render(pool);
			x++;
			i++;
		}
		y++;
	}
}

static	void	part_three(t_pool *pool)
{
	SDL_UpdateTexture(SCREEN_TEX, NULL, ST_SDL->scene, W * 4);
	SDL_SetRenderDrawColor(ST_SDL->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	REND_CPY(RENDER, SCREEN_TEX, NULL, NULL);
	SDL_RenderPresent(ST_SDL->rend);
	SDL_RenderClear(ST_SDL->rend);
	KEY_STATE = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&ST_SDL->event);
	(KEY_STATE[SDL_SCANCODE_ESCAPE]) ? DONE = SDL_TRUE : (0);
	(EVENT_TYPE == SDL_QUIT) ? DONE = SDL_TRUE : (0);
	(KEY_STATE[SDL_SCANCODE_W]) ? go_ahead(pool) : 0;
	(KEY_STATE[SDL_SCANCODE_S]) ? go_back(pool) : 0;
	(KEY_STATE[SDL_SCANCODE_D]) ? go_right(pool) : 0;
	(KEY_STATE[SDL_SCANCODE_A]) ? go_left(pool) : 0;
}

int				main(int argc, char **argv)
{
	t_pool	*pool;

	if (argc == 2 && argv[1])
	{
		if (ft_atoi(argv[1]) > 5 || ft_atoi(argv[1]) < 1)
		{
			ft_putstr("\033[1;31mERROR\n\e[m");
			return (0);
		}
		pool = malloc(sizeof(t_pool));
		part_one(pool, argv[1]);
		while (!DONE)
		{
			part_two(pool);
			part_three(pool);
		}
		cleaner(pool);
	}
	else
		ft_putstr("\033[1;31mERROR! NO ARGUMENT!\n\e[m");
	return (0);
}
