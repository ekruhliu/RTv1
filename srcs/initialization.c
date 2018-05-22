/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:41:29 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/11 13:41:30 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	part_one(t_pool *pool)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		ft_putstr("\033[1;31mError initializing SDL\n\e[m");
		exit(1);
	}
	WIN = SDL_CreateWindow("RTv1", WINDOW_IN, W, H, 0);
	if (!WIN)
	{
		ft_putstr("\033[1;31mError creating window\n\e[m");
		SDL_Quit();
		exit(1);
	}
}

static	void	part_two(t_pool *pool)
{
	RENDER_FLAG = SDL_RENDERER_ACCELERATED;
	RENDER = SDL_CreateRenderer(WIN, -1, RENDER_FLAG);
	if (!RENDER)
	{
		ft_putstr("\033[1;31mError creating renderer\n\e[m");
		SDL_DestroyWindow(WIN);
		SDL_Quit();
		exit(1);
	}
	SCREEN_TEX = SDL_CreateTexture(RENDER, TEX_IN, W, H);
	if (!SCREEN_TEX)
	{
		ft_putstr("\033[1;31mError creating texture\n\e[m");
		SDL_DestroyTexture(SCREEN_TEX);
		SDL_DestroyWindow(WIN);
		SDL_Quit();
		exit(1);
	}
}

static	void	part_three(t_pool *pool, char *argv)
{
	pool->eye = malloc(sizeof(t_eye));
	pool->viewport = malloc(sizeof(t_eye));
	pool->figure = malloc(sizeof(t_figure));
	pool->ray = malloc(sizeof(t_figure));
	pool->light = malloc(sizeof(t_light));
	pool->eye->eye_x = 0;
	pool->eye->eye_y = 0;
	pool->eye->eye_z = -20;
	pool->sdl->src_r.x = 0;
	pool->sdl->src_r.y = 0;
	pool->sdl->src_r.w = 800;
	pool->sdl->src_r.h = 800;
	pool->viewport->vp_x = 1;
	(ft_atoi(argv) == 1 ? pool->viewport->vp_y = 1 : 0);
	(ft_atoi(argv) == 2 ? pool->viewport->vp_y = 0 : 0);
	pool->viewport->vp_z = 1;
	pool->t1 = 0;
	pool->t2 = 0;
}

void			initialization(t_pool *pool, char *argv)
{
	part_one(pool);
	part_two(pool);
	part_three(pool, argv);
}
