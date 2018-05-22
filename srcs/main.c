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

static	void	init_sphere(t_pool *pool, char *argv)
{
	pool->figure->fig_x = 0;
	pool->figure->fig_y = 0;
	pool->figure->fig_z = 0;
	(ft_atoi(argv) == 1 ? pool->figure->radius = 2.5 : 0);
	(ft_atoi(argv) == 2 ? pool->figure->radius = 1.5 : 0);
	pool->figure->red = 0;
	pool->figure->green = 0;
	pool->figure->blue = 0;
	(ft_atoi(argv) == 1 ? pool->figure->red = 255 : 0);
	(ft_atoi(argv) == 2 ? pool->figure->green = 255 : 0);
	pool->figure->shit = 500;
	pool->light->intensity_amb = 0.2;
	pool->light->intensity = 0.5;
	pool->light->pos_x = 0;
	pool->light->pos_y = 5;
	pool->light->pos_z = 0;
	pool->light->intensity_dir = 0.1;
	pool->light->dir_x = 0;
	pool->light->dir_y = -1;
	pool->light->dir_z = 0;
}

static	void	part_one(t_pool *pool, char *argv)
{
	ST_SDL = malloc(sizeof(t_sdl));
	DONE = SDL_FALSE;
	initialization(pool, argv);
	init_sphere(pool, argv);
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
			pool->ray->ray_x = (x - DEC_W) * pool->viewport->vp_x / W;
			pool->ray->ray_y = (DEC_H - y) * pool->viewport->vp_y / H;
			pool->ray->ray_z = 1;
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
