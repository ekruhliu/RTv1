/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:00:03 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/05/16 14:00:03 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

// static	void	shmatok(t_pool *pool)
// {
// 	pool->p_x = pool->eye->eye_x + (pool->t1 * pool->ray->ray_x);
// 	pool->p_y = pool->eye->eye_y + (pool->t1 * pool->ray->ray_y);
// 	pool->p_z = pool->eye->eye_z + (pool->t1 * pool->ray->ray_z);
// }

// static	void	shmatok_2(t_pool *pool)
// {
// 	pool->normal_x = pool->p_x - pool->figure->fig_x / (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
// 	pool->normal_y = pool->p_y - pool->figure->fig_y / (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
// 	pool->normal_z = pool->p_z - pool->figure->fig_z / (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
// }

// static	void	find_l(t_pool *pool)
// {
// 	pool->l_x = pool->light->pos_x - pool->p_x;
// 	pool->l_y = pool->light->pos_y - pool->p_y;
// 	pool->l_z = pool->light->pos_z - pool->p_z;
// }

// static	void	find_r(t_pool *pool)
// {
// 	double	x;

// 	x = X10 + X11 + X12;
// 	pool->r_x = 2 * pool->normal_x * x - pool->l_x;
// 	pool->r_y = 2 * pool->normal_y * x - pool->l_y;
// 	pool->r_z = 2 * pool->normal_z * x - pool->l_z;
// }

// static	void	create_light(t_pool *pool, int shit)
// {
// 	pool->infin = 0.0;
// 	double n_dot;
// 	double r_dot;

// 	// if (pool->light->intensity_amb > 0)
// 	// 	pool->intensity += main.light[i1].intensivity;
// 	// else
// 	// {
// 		if (pool->light->intensity)
// 			find_l(pool);
// 		else
// 		{
// 			pool->l_x = pool->light->dir_x;
// 			pool->l_y = pool->light->dir_y;
// 			pool->l_z = pool->light->dir_z;
// 		}
// 		n_dot = X10 + X11 + X12;
// 		if (n_dot > 0)
// 			pool->infin += pool->light->intensity * n_dot / ((sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2))) * (sqrt(pow(pool->l_x, 2) + pow(pool->l_y, 2) + pow(pool->l_z, 2))));
// 		if (shit != -1)
// 		{
// 			find_r(pool);
// 			pool->v_x = pool->ray->ray_x * -1;
// 			pool->v_y = pool->ray->ray_y * -1;
// 			pool->v_z = pool->ray->ray_z * -1;
// 			int a = pool->r_x * pool->v_x;
// 			int b = pool->r_y * pool->v_y;
// 			int c = pool->r_z * pool->v_z;
// 			r_dot = a + b + c;
// 			if (r_dot > 0)
// 				pool->infin += pool->light->intensity * pow(r_dot / (((sqrt(pow(pool->r_x, 2) + pow(pool->r_y, 2) + pow(pool->r_z, 2))) * (sqrt(pow(pool->v_x, 2) + pow(pool->v_y, 2) + pow(pool->v_z, 2))))), shit);
// 		}
// 	// }
// }


int	render(t_pool *pool)
{
	double	k1;
	double	k2;
	double	k3;
	double	disk;
	int		shit;

	shit = -1;
	k1 = SQR_RAY_X + SQR_RAY_Y + SQR_RAY_Z;
	k2 = 2 * (X4 + X5 + X6);
	k3 = X7 + X8 + X9;
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
	// shmatok(pool);
	// shmatok_2(pool);
	// create_light(pool, shit);
	// int r = 0;
	// int g = 0;
	// int b = 0;
	// if (pool->figure->red * pool->infin > 255)
	// 	r = 255;
	// else
	// 	r = pool->figure->red * pool->infin;
	// if (pool->figure->green * pool->infin > 255)
	// 	g = 255;
	// else
	// 	g = pool->figure->green * pool->infin;
	// if (pool->figure->blue * pool->infin > 255)
	// 	b = 255;
	// else
	// 	b = pool->figure->blue * pool->infin;
	// pool->figure->color = (r << 16) + (g << 8) + (b);
	pool->figure->color = BIT_RED + BIT_GREEN + BIT_BLUE;
	return (pool->figure->color);
}
