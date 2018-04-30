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

# define W 1024
# define H 768
# define WIN pool->win
# define RENDER_FLAG pool->render_flags
# define RENDER pool->rend
# define SCREEN_TEX pool->screen_tex
# define TEX_IN SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET
# define WINDOW_IN SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
# define KEY_STATE pool->keyboard_state
# define DONE pool->done
# define KEY_SCANCODE pool->event.key.keysym.scancode
# define EVENT_TYPE pool->event.type

typedef	struct		s_pool
{
	SDL_bool		done;
	SDL_Window		*win;
	Uint32			render_flags;
	SDL_Renderer	*rend;
	SDL_Texture		*screen_tex;
	const Uint8		*keyboard_state;
	SDL_Event		event;
}					t_pool;

void			initialization(t_pool *pool);

#endif
