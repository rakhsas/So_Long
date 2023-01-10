/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:31:42 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/10 15:23:20 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_of_2tab_ligne(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->map->tab[i])
		i++;
	return (i);
}

int	len_of_2tab_collone(t_data *dt)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (dt->map->tab[i][j])
		j++;
	return (j);
}

int	vert_len(t_data	*dt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i[dt->map->ptr])
	{
		if (i[dt->map->ptr] == '\n')
			j++;
		i++;
	}
	return (j);
}
