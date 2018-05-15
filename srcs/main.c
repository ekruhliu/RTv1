/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c                                             :+:      :+:    :+:   */
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
	pool->sdl->src_r.x = 0;
	pool->sdl->src_r.y = 0;
	pool->sdl->src_r.w = 800;
	pool->sdl->src_r.h = 800;
	pool->viewport->vp_x = 1;
	pool->viewport->vp_y = 1;
	pool->viewport->vp_z = 1;
}

static	void	init_figure(t_pool *pool)
{
	pool->figure->fig_x = 0;
	pool->figure->fig_y = 0;
	pool->figure->fig_z = 0;
	pool->figure->radius = 3;
	pool->figure->red = 255;
	pool->figure->green = 0;
	pool->figure->blue = 0;
	pool->t1 = 0;
	pool->t2 = 0;
}

static	int	render_figure(t_pool *pool)
{
	double k1;
	double k2;
	double k3;
	double disk;

	int shit = -1;

	double x1 = pool->ray->ray_x * pool->ray->ray_x;
	double x2 = pool->ray->ray_y * pool->ray->ray_y;
	double x3 = pool->ray->ray_z * pool->ray->ray_z;
	k1 = x1 + x2 + x3;
	double x4 = ((pool->eye->eye_x - pool->figure->fig_x) * pool->ray->ray_x);
	double x5 = ((pool->eye->eye_y - pool->figure->fig_y) * pool->ray->ray_y);
	double x6 = ((pool->eye->eye_z - pool->figure->fig_z) * pool->ray->ray_z);
	k2 = 2 * (x4 + x5 + x6);
	double x7 = ((pool->eye->eye_x - pool->figure->fig_x) * (pool->eye->eye_x - pool->figure->fig_x)) - (pool->figure->radius * pool->figure->radius);
	double x8 = ((pool->eye->eye_y - pool->figure->fig_y) * (pool->eye->eye_y - pool->figure->fig_y)) - (pool->figure->radius * pool->figure->radius);
	double x9 = ((pool->eye->eye_z - pool->figure->fig_z) * (pool->eye->eye_z - pool->figure->fig_z)) - (pool->figure->radius * pool->figure->radius);
	k3 = x7 + x8 + x9;
	disk = k2 * k2 - 4 * k1 * k3;
	if (disk < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	pool->t1 = (-k2 + sqrt(disk)) / (2 * k1);
	pool->t2 = (-k2 - sqrt(disk)) / (2 * k1);
	if (pool->t1 > 1 && pool->t1 < INFINITY)
	{
		pool->t1 = INFINITY;
		shit = 1;
	}
	if (pool->t2 > 1 && pool->t2 < INFINITY)
	{
		pool->t2 = INFINITY;
		shit = 1;
	}
	if (shit == -1)
		return (0);
	return ((pool->figure->red << 16) + (pool->figure->green << 8) + (pool->figure->blue));
} 

static	void	create_figure(t_pool *pool, int x, int y)
{
	pool->ray->ray_x = x * pool->viewport->vp_x / W;
	pool->ray->ray_y = y * pool->viewport->vp_y / H;
	pool->ray->ray_z = 1;
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
		int y;
		int x;
		int i;

		y = 0;
		i = 0;
		ST_SDL->scene = malloc(sizeof(int) * (W * H));
		while (!DONE)
		{
			while (y < H)
			{
				x = 0;
				while (x < W)
				{
					create_figure(pool, x - DEC_W, DEC_H - y);
					ST_SDL->scene[i] = render_figure(pool);
					x++;
					i++;
				}
				y++;
			}
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
	else
		ft_putstr("\033[1;31mERROR\n\e[m");
	return (0);
}
