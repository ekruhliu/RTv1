/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:02:47 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/04/26 10:02:48 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "./libft/libft.h"
# include "./libSDL/SDL2.framework/Headers/SDL.h"
# include "./libSDL/SDL2_image.framework/Headers/SDL_image.h"

# define W 800
# define H 800
# define DEC_W 800 / 2
# define DEC_H 800 / 2
# define X pool->x
# define Y pool->y
# define WIN ST_SDL->win
# define RENDER_FLAG pool->render_flags
# define RENDER ST_SDL->rend
# define TEX_IN SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET
# define WINDOW_IN SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
# define KEY_STATE pool->keyboard_state
# define DONE ST_SDL->done
# define KEY_SCANCODE pool->event.key.keysym.scancode
# define EVENT_TYPE pool->sdl->event.type
# define CREATE_SURF SDL_CreateRGBSurface
# define ST_SDL pool->sdl
# define SCREEN_TEX pool->sdl->screen_tex
# define TEX_FMR_SRF SDL_CreateTextureFromSurface
# define REND_CPY SDL_RenderCopy

typedef	struct		s_eye
{
	double			eye_x;
	double			eye_y;
	double			eye_z;
}					t_eye;

typedef	struct		s_viewport
{
	double			vp_x;
	double			vp_y;
	double			vp_z;
}					t_viewport;

typedef struct		s_sdl
{
	SDL_bool		done;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Event		event;
	SDL_Rect		src_r;
	SDL_Texture		*screen_tex;
	int				*scene;
}					t_sdl;

typedef	struct		s_figure
{
	double			fig_x;
	double			fig_y;
	double			fig_z;
	double			radius;
	int				red;
	int				green;
	int				blue;
}					t_figure;

typedef	struct		s_ray
{
	double			ray_x;
	double			ray_y;
	double			ray_z;
}					t_ray;

typedef	struct		s_pool
{
	Uint32			render_flags;
	const Uint8		*keyboard_state;
	t_eye			*eye;
	t_viewport		*viewport;
	t_figure		*figure;
	t_sdl			*sdl;
	t_ray			*ray;
	double			t1;
	double			t2;
}					t_pool;

void			initialization(t_pool *pool);

#endif
