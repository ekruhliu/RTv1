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

# define W 1000
# define H 1000
# define DEC_W 1000 / 2
# define DEC_H 1000 / 2
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
# define X1 pool->ray->ray_x * pool->ray->ray_x
# define X2 pool->ray->ray_y * pool->ray->ray_y
# define X3 pool->ray->ray_z * pool->ray->ray_z
# define X4 pool->x * pool->ray->ray_x
# define X5 pool->y * pool->ray->ray_y
# define X6 pool->z * pool->ray->ray_z
# define X7 pool->x * pool->x
# define X8 pool->y * pool->y
# define X9 pool->z * pool->z
# define BIT_RED (pool->figure->red << 16)
# define BIT_GREEN (pool->figure->green << 8)
# define BIT_BLUE (pool->figure->blue)
# define X10 pool->normal_x * pool->l_x
# define X11 pool->normal_y * pool->l_y
# define X12 pool->normal_z * pool->l_z
# define X13 pool->r_x * pool->v_x
# define X14 pool->r_y * pool->v_y
# define X15 pool->r_z * pool->v_z

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
	int				color;
	int				shit;
}					t_figure;

typedef	struct		s_ray
{
	double			ray_x;
	double			ray_y;
	double			ray_z;
}					t_ray;

typedef struct		s_light
{
	double			intensity_amb;
	double			intensity;
	double			pos_x;
	double			pos_y;
	double			pos_z;
	double			intensity_dir;
	double			dir_x;
	double			dir_y;
	double			dir_z;
}					t_light;

typedef	struct		s_pool
{
	Uint32			render_flags;
	const Uint8		*keyboard_state;
	t_eye			*eye;
	t_viewport		*viewport;
	t_figure		*figure;
	t_sdl			*sdl;
	t_ray			*ray;
	t_light			*light;
	double			closest_t;
	double			x;
	double			y;
	double			z;
	double			light_int;
	double			t1;
	double			t2;
	double			p_x;
	double			p_y;
	double			p_z;
	double			l_x;
	double			l_y;
	double			l_z;
	double			r_x;
	double			r_y;
	double			r_z;
	double			v_x;
	double			v_y;
	double			v_z;
	double			normal_x;
	double			normal_y;
	double			normal_z;
}					t_pool;

void				initialization(t_pool *pool, char *argv);
void				cleaner(t_pool *pool);
int					render(t_pool *pool);

#endif
