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

static	void	init_light(t_pool *pool)
{
	pool->light = malloc(sizeof(t_light) * 2);
	pool->light[0].intensity = 0.2;
	pool->light[0].type = 1;
	pool->light[1].intensity = 0.8;
	pool->light[1].pos.x = 6;
	pool->light[1].pos.y = 1;
	pool->light[1].pos.z = -6;
	pool->light[1].type = 2;
	// pool->light[0].dir.x = 1;
	// pool->light[0].dir.y = 0;
	// pool->light[0].dir.z = 0;

	// pool->light[1].intensity = 0.4;
	// pool->light[1].pos.x = 3;
	// pool->light[1].pos.y = 0;
	// pool->light[1].pos.z = -4;
	// pool->light[1].dir.x = -1;
	// pool->light[1].dir.y = 0;
	// pool->light[1].dir.z = 0;
	pool->light_counter = 2;
}

static	void	part_one(t_pool *pool, char *argv)
{
	ST_SDL = malloc(sizeof(t_sdl));
	DONE = SDL_FALSE;
	initialization(pool);
	if (ft_atoi(argv) == 1)
		scene_one(pool);
	if (ft_atoi(argv) == 2)
		scene_two(pool);
	if (ft_atoi(argv) == 3)
		scene_three(pool);
	// if (ft_atoi(argv) == 4)
	// {
	// 	pool->figure = malloc(sizeof(t_figure) * 6);
	// }
	// if (ft_atoi(argv) == 5)
	// {
	// 	pool->figure = malloc(sizeof(t_figure) * 16);
	// }
	init_light(pool);
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
}

int				main(int argc, char **argv)
{
	t_pool	*pool;

	if (argc == 2 && argv[1])
	{
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
		ft_putstr("\033[1;31mERROR\n\e[m");
	return (0);
}
