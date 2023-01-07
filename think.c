/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:53:19 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 22:16:10 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	specified_len_of_collone(t_data *dt, int line)
{
	int	j;

	j = 0;
	while (dt->tab[line][j])
		j++;
	return (j);
}

void	check_length_of_lignes(t_data *dt)
{
	int i = 0;
	int x = len_of_2tab_collone(dt);
	while (i < len_of_2tab_ligne(dt))
	{
		if (x != specified_len_of_collone(dt, i))
		{
			ft_printf("\033[0;31mError\nThe Length of Map should be Identic\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}