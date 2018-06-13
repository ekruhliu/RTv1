/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_standart_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 05:06:42 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/06/07 05:06:43 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static	void	part_one(t_pool *pool, int i, char **tmp_2)
{
	if (i > 3 || i < 3)
	{
		ft_putstr("\033[1;31mERROR\n\e[m");
		exit(1);
	}
	FIGURE[0].pos.x = ft_atoi(tmp_2[0]);
	FIGURE[0].pos.y = ft_atoi(tmp_2[1]);
	FIGURE[0].pos.z = ft_atoi(tmp_2[2]);
}

static	void	part_two(char **tmp_2)
{
	int		n;

	n = -1;
	while (tmp_2[++n])
		ft_strdel(&tmp_2[n]);
	free(tmp_2);
}

void			check_standart_input(t_pool *pool)
{
	int		i;
	char	*tmp;
	char	**tmp_2;

	i = 0;
	tmp = NULL;
	tmp_2 = NULL;
	get_next_line(0, &tmp);
	tmp_2 = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	while (tmp_2[i])
		i++;
	if (i == 0)
	{
		part_two(tmp_2);
		return ;
	}
	part_one(pool, i, tmp_2);
	i = -1;
	while (tmp_2[++i])
		ft_strdel(&tmp_2[i]);
	free(tmp_2);
}
