/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_figures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:58:17 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/04 18:58:17 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	intersect_ray_figures(t_pool *pool, int i)
{
	(pool->figure[i].type == 1 ? intersect_ray_sphere(pool, i) : 0);
	(pool->figure[i].type == 2 ? intersect_ray_cylinder(pool, i) : 0);
	(pool->figure[i].type == 3 ? intersect_ray_plane(pool, i) : 0);
	(pool->figure[i].type == 4 ? intersect_ray_cone(pool, i) : 0);
}

void	intersect_shadow_figures(t_pool *pool, int i)
{
	(pool->figure[i].type == 1 ? intersect_shadow_sphere(pool, i) : 0);
	(pool->figure[i].type == 2 ? intersect_shadow_cylinder(pool, i) : 0);
	(pool->figure[i].type == 3 ? intersect_ray_plane(pool, i) : 0); //shadow
	(pool->figure[i].type == 4 ? intersect_shadow_cone(pool, i) : 0);
}
