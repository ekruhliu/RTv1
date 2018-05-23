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

static	void	shmatok(t_pool *pool)
{
	pool->p_x = pool->eye->eye_x + (pool->closest_t * pool->ray->ray_x);
	pool->p_y = pool->eye->eye_y + (pool->closest_t * pool->ray->ray_y);
	pool->p_z = pool->eye->eye_z + (pool->closest_t * pool->ray->ray_z);
}

static	void	shmatok_2(t_pool *pool)
{
	pool->normal_x = pool->p_x - pool->sphere->fig_x;
	pool->normal_y = pool->p_y - pool->sphere->fig_y;
	pool->normal_z = pool->p_z - pool->sphere->fig_z;
	pool->normal_x /= (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
	pool->normal_y /= (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
	pool->normal_z /= (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2)));
}

static	void	find_r(t_pool *pool)
{
	double	x;

	x = X10 + X11 + X12;
	pool->r_x = 2 * pool->normal_x * x - pool->l_x;
	pool->r_y = 2 * pool->normal_y * x - pool->l_y;
	pool->r_z = 2 * pool->normal_z * x - pool->l_z;
}

static	int	create_shadows(t_pool *pool)
{
	int		sdw_sphere = -1;
	double	shadow_t;
	double	disc;
	double	k1;
	double	k2;
	double	k3;

	shadow_t = INFINITY;
	pool->x = pool->p_x - pool->sphere->fig_x;
	pool->y = pool->p_y - pool->sphere->fig_y;
	pool->z = pool->p_z - pool->sphere->fig_z;

	k1 = X16 + X17 + X18;
	k2 = 2 * (X19 + X20 + X21);
	k3 = (X22 + X23 + X24) - pow(pool->sphere->radius, 2);
	disc = pow(k2, 2) - (4 * k1 * k3);
	if (disc < 0)
	{
		pool->sdw_t1 = INFINITY;
		pool->sdw_t2 = INFINITY;
	}
	else
	{
		pool->sdw_t1 = (-k2 + sqrt(disc)) / (2 * k1);
		pool->sdw_t2 = (-k2 - sqrt(disc)) / (2 * k1);
	}
	if (pool->sdw_t1 > 1 && pool->sdw_t1 < INFINITY && pool->sdw_t1 < shadow_t)
	{
		shadow_t = pool->sdw_t1;
		sdw_sphere = 1;
	}
	if (pool->sdw_t2 > 1 && pool->sdw_t2 < INFINITY && pool->sdw_t2 < shadow_t)
	{
		shadow_t = pool->sdw_t2;
		sdw_sphere = 1;
	}
	// if (cls_sphere == -1)
	// 	return (0);
	return(shadow_t);
}

static	void	amb_light(t_pool *pool)
{
	if (pool->light->intensity_amb > 0.0)
		pool->light_int += pool->light->intensity_amb;
}

static	void	point_light(t_pool *pool)
{
	double scal;
	double scal_2;
	double max = INFINITY;

	if (pool->light->intensity > 0.0)
	{
		pool->l_x = pool->light->pos_x - pool->p_x;
		pool->l_y = pool->light->pos_y - pool->p_y;
		pool->l_z = pool->light->pos_z - pool->p_z;
		max = 1;
	}
	scal = X10 + X11 + X12;
	pool->shadow_t = create_shadows(pool);
	if (pool->shadow_t == -1)
		return ;
	if (scal > 0)
		pool->light_int += pool->light->intensity * scal / (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2))) * (sqrt(pow(pool->l_x, 2) + pow(pool->l_y, 2) + pow(pool->l_z, 2)));
	if (pool->sphere->tarnish != -1)
	{
		find_r(pool);
		pool->v_x = pool->ray->ray_x;
		pool->v_y = pool->ray->ray_y;
		pool->v_z = pool->ray->ray_z;
		pool->v_x *= -1;
		pool->v_y *= -1;
		pool->v_z *= -1;
		scal_2 = X13 + X14 + X15;
		if (scal_2 > 0)
			pool->light_int += pool->light->intensity * pow(scal_2 / (sqrt(pow(pool->r_x, 2) + pow(pool->r_y, 2) + pow(pool->r_z, 2))) * (sqrt(pow(pool->v_x, 2) + pow(pool->v_y, 2) + pow(pool->v_z, 2))), pool->sphere->tarnish);
	}
}

static	void	dir_light(t_pool *pool)
{
	double scal;
	double scal_2;

	if (pool->light->intensity_dir > 0.0)
	{
		pool->l_x = pool->light->dir_x;
		pool->l_y = pool->light->dir_y;
		pool->l_z = pool->light->dir_z;
	}
	scal = X10 + X11 + X12;
	pool->shadow_t = create_shadows(pool);
	if (pool->shadow_t == -1)
		return ;
	if (scal > 0)
		pool->light_int += pool->light->intensity * scal / (sqrt(pow(pool->normal_x, 2) + pow(pool->normal_y, 2) + pow(pool->normal_z, 2))) * (sqrt(pow(pool->l_x, 2) + pow(pool->l_y, 2) + pow(pool->l_z, 2)));
	if (pool->sphere->tarnish != -1)
	{
		find_r(pool);
		pool->v_x = pool->ray->ray_x;
		pool->v_y = pool->ray->ray_y;
		pool->v_z = pool->ray->ray_z;
		pool->v_x *= -1;
		pool->v_y *= -1;
		pool->v_z *= -1;
		scal_2 = X13 + X14 + X15;
		if (scal_2 > 0)
			pool->light_int += pool->light->intensity * pow(scal_2 / (sqrt(pow(pool->r_x, 2) + pow(pool->r_y, 2) + pow(pool->r_z, 2))) * (sqrt(pow(pool->v_x, 2) + pow(pool->v_y, 2) + pow(pool->v_z, 2))), pool->sphere->tarnish);
	}
}

static	void	create_light(t_pool *pool)
{
	pool->light_int = 0.0;
	amb_light(pool);
	point_light(pool);
	dir_light(pool);
}

int	render(t_pool *pool)
{
	int		cls_sphere = -1;
	double	disc;
	double	k1;
	double	k2;
	double	k3;
	unsigned int r = 0;
	unsigned int g = 0;
	unsigned int b = 0;

	pool->closest_t = INFINITY;
	pool->x = pool->eye->eye_x - pool->sphere->fig_x;
	pool->y = pool->eye->eye_y - pool->sphere->fig_y;
	pool->z = pool->eye->eye_z - pool->sphere->fig_z;

	k1 = X1 + X2 + X3;
	k2 = 2 * (X4 + X5 + X6);
	k3 = (X7 + X8 + X9) - pow(pool->sphere->radius, 2);
	disc = pow(k2, 2) - (4 * k1 * k3);
	if (disc < 0)
	{
		pool->t1 = INFINITY;
		pool->t2 = INFINITY;
	}
	else
	{
		pool->t1 = (-k2 + sqrt(disc)) / (2 * k1);
		pool->t2 = (-k2 - sqrt(disc)) / (2 * k1);
	}
	if (pool->t1 > 1 && pool->t1 < INFINITY && pool->t1 < pool->closest_t)
	{
		pool->closest_t = pool->t1;
		cls_sphere = 1;
	}
	if (pool->t2 > 1 && pool->t2 < INFINITY && pool->t2 < pool->closest_t)
	{
		pool->closest_t = pool->t2;
		cls_sphere = 1;
	}
	pool->sphere->color = (r << 16) + (g << 8) + b;
	if (cls_sphere == -1)
		return (pool->sphere->color);
	shmatok(pool);
	shmatok_2(pool);
	create_light(pool);

	if ((pool->sphere->red * pool->light_int) > 255)
		r = 255;
	else
		r = pool->sphere->red * pool->light_int;
	if ((pool->sphere->green * pool->light_int) > 255)
		g = 255;
	else
		g = pool->sphere->green * pool->light_int;
	if ((pool->sphere->blue * pool->light_int) > 255)
		b = 255;
	else
		b = pool->sphere->blue * pool->light_int;
	pool->sphere->color = (r << 16) + (g << 8) + b;
	return (pool->sphere->color);
}
