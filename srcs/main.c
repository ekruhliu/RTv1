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

static	void	init_struct(t_pool *pool)
{
	pool->eye = malloc(sizeof(t_eye));
	pool->viewport = malloc(sizeof(t_eye));
	pool->figure = malloc(sizeof(t_figure));
	pool->ray = malloc(sizeof(t_figure));
	pool->eye->eye_x = 0;
	pool->eye->eye_y = 0;
	pool->eye->eye_z = -20;
	ST_SDL->scene_surf = CREATE_SURF(0, H, W, 32, 0, 0, 0, 0);
	pool->scene = ST_SDL->scene_surf->pixels;
	pool->sdl->src_r.x = 0;
	pool->sdl->src_r.y = 0;
	pool->sdl->src_r.w = 1024;
	pool->sdl->src_r.h = 768;
	pool->viewport->vp_x = 1;
	pool->viewport->vp_y = 1;
	pool->viewport->vp_z = 1;
}

static	void	init_figure(t_pool *pool)
{
	pool->figure->fig_x = 0;
	pool->figure->fig_y = 0;
	pool->figure->fig_z = 0;
	pool->figure->radius = 1;
	pool->figure->red = 255;
	pool->figure->green = 0;
	pool->figure->blue = 0;
	pool->t1 = 0;
	pool->t2 = 0;
}

static	void	render_figure(t_pool *pool)
{
	double infinity;

	infinity = 2147483647;
	if (pool->t1 > 1 && pool->t1 < infinity)
		infinity = t1;
	if (pool->t2 > 1 && pool->t2 < infinity)
		infinity = t2;
} 

static	void	create_figure(t_pool *pool)
{
	int x;
	int y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pool->ray->ray_x = x * pool->viewport->vp_x / DEC_W;
			pool->ray->ray_y = y * pool->viewport->vp_y / DEC_H;
			pool->ray->ray_z = 1;
			x++;
		}
		y++;
	}
}

int				main(int argc, char **argv)
{
	t_pool	*pool;

	if (argc == 2 && argv[1])
	{
		pool = malloc(sizeof(t_pool));
		ST_SDL = malloc(sizeof(t_sdl));
		DONE = SDL_FALSE;
		initialization(pool);
		init_struct(pool);
		init_figure(pool);
		create_figure(pool);
		while (!DONE)
		{
			SDL_SetRenderDrawColor(ST_SDL->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
			SDL_RenderPresent(ST_SDL->rend);
			SDL_RenderClear(ST_SDL->rend);
			KEY_STATE = SDL_GetKeyboardState(NULL);
			SDL_PollEvent(&ST_SDL->event);
			(KEY_STATE[SDL_SCANCODE_ESCAPE]) ? DONE = SDL_TRUE : (0);
			(EVENT_TYPE == SDL_QUIT) ? DONE = SDL_TRUE : (0);
		}
		SDL_DestroyWindow(WIN);
		SDL_DestroyRenderer(ST_SDL->rend);
		SDL_FreeSurface(ST_SDL->scene_surf);
		SDL_DestroyTexture(ST_SDL->scene_tex);
		SDL_Quit();
		free(pool->sdl);
		free(pool->eye);
		free(pool->viewport);
		free(pool->figure);
		free(pool->ray);
		free(pool);
	}
	else
		ft_putstr("\033[1;31mERROR\n\e[m");
	return (0);
}
