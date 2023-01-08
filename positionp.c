/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:02:06 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/08 18:48:54 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_positon_player(t_data *dt)
{
	int i = 0;
	int j = 0;
	dt->p_pos_i = i;
	dt->p_pos_j = j;
	while(dt->map->tab[i])
	{
		while (dt->map->tab[i][j])
		{
			if (dt->map->tab[i][j] == 'P')
			{
				dt->p_pos_i = i;
				dt->p_pos_j = j;
			}
			j++;
		}
		i++;
	}

}