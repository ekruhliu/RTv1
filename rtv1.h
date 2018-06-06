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
# define RADIUS pool->figure[i].radius
# define DOT(x_1, x_2) ((x_1.x * x_2.x) + (x_1.y * x_2.y) + (x_1.z * x_2.z))
# define X1 (sqrt(pow(pool->normal.x, 2) + pow(pool->normal.y, 2) + pow(pool->normal.z, 2)))
# define X2 (sqrt(pow(pool->l.x, 2) + pow(pool->l.y, 2) + pow(pool->l.z, 2)))
# define X3 (sqrt(pow(pool->r.x, 2) + pow(pool->r.y, 2) + pow(pool->r.z, 2)))
# define X4 (sqrt(pow(pool->v.x, 2) + pow(pool->v.y, 2) + pow(pool->v.z, 2)))
# define X5 (sqrt(pow(copy_2.x, 2) + pow(copy_2.y, 2) + pow(copy_2.z, 2)))

// # define X6 (sqrt(pow(x_2.x, 2) + pow(x_2.y, 2) + pow(x_2.z, 2)))
// # define X7 (sqrt(pow(pool->figure[pool->cls_figure].dir.x, 2) + pow(pool->figure[pool->cls_figure].dir.y, 2) + pow(pool->figure[pool->cls_figure].dir.z, 2)))
# define X8 (sqrt(pow(x_4.x, 2) + pow(x_4.y, 2) + pow(x_4.z, 2)))
// # define X8 pool->y * pool->y
// # define X9 pool->z * pool->z
// # define BIT_RED (pool->figure->red << 16)
// # define BIT_GREEN (pool->figure->green << 8)
// # define BIT_BLUE (pool->figure->blue)
// # define X10 pool->normal_x * pool->l_x
// # define X11 pool->normal_y * pool->l_y
// # define X12 pool->normal_z * pool->l_z
// # define X13 pool->r_x * pool->v_x
// # define X14 pool->r_y * pool->v_y
// # define X15 pool->r_z * pool->v_z
// # define X16 pool->l_x * pool->l_x
// # define X17 pool->l_y * pool->l_y
// # define X18 pool->l_z * pool->l_y
// # define X19 pool->x * pool->l_x
// # define X20 pool->y * pool->l_y
// # define X21 pool->z * pool->l_z
// # define X22 pool->x * pool->x
// # define X23 pool->y * pool->y
// # define X24 pool->z * pool->z
// # define X25
// # define X26
// # define X27
// # define X28
// # define X29
// # define X30

typedef	struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

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
	t_vector		pos;
	t_vector		dir;
	double			radius;
	double			angle;
	int				tarnish;
	int				red;
	int				green;
	int				blue;
	int				type;
}					t_figure;

typedef struct		s_light
{
	// double			intensity_amb;
	int				type;
	double			intensity;
	t_vector		pos;
	t_vector		dir;
}					t_light;

typedef	struct		s_pool
{
	Uint32			render_flags;
	const Uint8		*keyboard_state;
	t_vector		cam;
	t_vector		viewport;
	t_vector		ray;
	t_figure		*figure;
	t_sdl			*sdl;
	t_light			*light;
	double			closest_t;
	double			shadow_t;
	int				sdw_figure;
	int 			cls_figure;
	t_vector		coord;
	double			light_int;
	double			t1;
	double			t2;
	double			sdw_t1;
	double			sdw_t2;
	t_vector		p;
	t_vector		l;
	t_vector		r;
	t_vector		v;
	t_vector		normal;
	int				fig_counter;
	int				light_counter;
}					t_pool;

void				initialization(t_pool *pool);
void				cleaner(t_pool *pool);
int					render(t_pool *pool);
void				scene_one(t_pool *pool);
void				scene_two(t_pool *pool);
void				scene_three(t_pool *pool);
void				intersect_shadow_sphere(t_pool *pool, int i);
void				create_shadow(t_pool *pool);
void				create_light(t_pool *pool);
void				intersect_ray_sphere(t_pool *pool, int i);
int					ret_color(t_pool *pool);
double				dot(t_vector arg_1, t_vector arg_2);
void				intersect_ray_cylinder(t_pool *pool, int i);
void				sintersect_shadow_cylinder(t_pool *pool, int i);
int					intersect_ray_plane(t_pool *pool, int i);
void				intersect_ray_cone(t_pool *pool, int i);
void				intersect_shadow_cone(t_pool *pool, int i);

#endif
