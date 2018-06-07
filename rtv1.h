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
# define FIGURE pool->figure
# define NORMAL pool->normal
# define COORD pool->coord
# define RAD pool->cone_radiana
# define VAR pool->var
# define CLS_F pool->cls_figure
# define LIGHT pool->light
# define LIGHT_INT pool->light_int
# define RED pool->figure[pool->cls_figure].red
# define GREEN pool->figure[pool->cls_figure].green
# define BLUE pool->figure[pool->cls_figure].blue
# define COLORS (pool->red << 16) + (pool->green << 8) + pool->blue
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
# define RADIUS FIGURE[i].radius
# define DOT(x1, x2) ((x1.x * x2.x) + (x1.y * x2.y) + (x1.z * x2.z))
# define X1 (sqrt(pow(NORMAL.x, 2) + pow(NORMAL.y, 2) + pow(NORMAL.z, 2)))
# define X2 (sqrt(pow(pool->l.x, 2) + pow(pool->l.y, 2) + pow(pool->l.z, 2)))
# define X3 (sqrt(pow(pool->r.x, 2) + pow(pool->r.y, 2) + pow(pool->r.z, 2)))
# define X4 (sqrt(pow(pool->v.x, 2) + pow(pool->v.y, 2) + pow(pool->v.z, 2)))
# define X5 (sqrt(pow(copy_2.x, 2) + pow(copy_2.y, 2) + pow(copy_2.z, 2)))
# define X6 (sqrt(pow(NORMAL.x, 2) + pow(NORMAL.y, 2) + pow(NORMAL.z, 2)))
# define X8 (sqrt(pow(VAR->x4.x, 2) + pow(VAR->x4.y, 2) + pow(VAR->x4.z, 2)))
# define X9 DOT(cyl, FIGURE->dir)
# define X10 DOT(COORD, FIGURE->dir)
# define X11 DOT(cone, FIGURE[i].dir)
# define X12 DOT(COORD, FIGURE[i].dir)
# define X13 pow(FIGURE[CLS_F].dir.x, 2)
# define X14 pow(FIGURE[CLS_F].dir.y, 2)
# define X15 pow(FIGURE[CLS_F].dir.z, 2)
# define X16 (VAR->x2.x * FIGURE[CLS_F].dir.x)
# define X17 (VAR->x2.y * FIGURE[CLS_F].dir.y)
# define X18 (VAR->x2.z * FIGURE[CLS_F].dir.z)
# define X19 (LIGHT[i].intensity * n_dot_l) / (X1 * X2)
# define X20 LIGHT[i].intensity * pow(r_dot_v / (X3 * X4), FIGURE->tarnish)

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
	double			intensity;
	t_vector		pos;
}					t_light;

typedef	struct		s_variable
{
	double		x1;
	t_vector	x2;
	t_vector	x3;
	t_vector	x4;
	t_vector	x5;
	double		x6;
	double		x7;
	double		x8;
}					t_variable;

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
	int				cls_figure;
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
	double			cone_radiana;
	double			amb_light;
	t_variable		*var;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}					t_pool;

void				initialization(t_pool *pool);
void				cleaner(t_pool *pool);
int					render(t_pool *pool);
void				scene_one(t_pool *pool);
void				scene_two(t_pool *pool);
void				scene_three(t_pool *pool);
void				scene_four(t_pool *pool);
void				scene_five(t_pool *pool);
void				intersect_shadow_sphere(t_pool *pool, int i);
void				create_shadow(t_pool *pool);
void				create_light(t_pool *pool);
void				intersect_ray_sphere(t_pool *pool, int i);
int					ret_color(t_pool *pool);
double				dot(t_vector arg_1, t_vector arg_2);
void				intersect_ray_cylinder(t_pool *pool, int i);
void				intersect_shadow_cylinder(t_pool *pool, int i);
void				intersect_ray_plane(t_pool *pool, int i);
void				intersect_ray_cone(t_pool *pool, int i);
void				intersect_shadow_cone(t_pool *pool, int i);
void				intersect_shadow_plane(t_pool *pool, int i);
void				intersect_ray_figures(t_pool *pool, int i);
void				intersect_shadow_figures(t_pool *pool, int i);
void				find_normal_sphere(t_pool *pool);
void				find_normal_cylinder(t_pool *pool);
void				find_normal_plane(t_pool *pool);
void				find_normal_cone(t_pool *pool);
void				go_ahead(t_pool *pool);
void				go_back(t_pool *pool);
void				go_right(t_pool *pool);
void				go_left(t_pool *pool);
void				check_standart_input(t_pool *pool);

#endif
