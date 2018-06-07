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

void	check_standart_input(t_pool *pool)
{
	int		i;
	char	*tmp;
	char	**tmp_2;

	i = 0;
	tmp = NULL;
	tmp_2 = NULL;
	get_next_line(0, &tmp);
	tmp_2 = ft_strsplit(tmp, ' ');
	while (tmp_2[i])
		i++;
	if (i == 0)
		return ;
	if (i > 3 || i < 3)
	{
		ft_putstr("\033[1;31mERROR\n\e[m");
		exit(1);
	}
	FIGURE[0].pos.x = ft_atoi(tmp_2[0]);
	FIGURE[0].pos.y = ft_atoi(tmp_2[1]);
	FIGURE[0].pos.z = ft_atoi(tmp_2[2]);
	i = -1;
	while (tmp_2[++i])
		free(tmp_2[i]);
	free(tmp);
}
