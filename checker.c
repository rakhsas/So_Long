/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:00 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/09 20:34:15 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_chars(t_data *dt, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->map->ptr[i])
	{
		if (dt->map->ptr[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
int	checker_chars_c_tab(char **tab, char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}


void	ft_check_i(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->map->tab[i])
	{
		if (dt->map->tab[i][0] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map Border should not contain a charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_ilen(dt);
}
void	ft_check_ilen(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->map->tab[i])
	{
		if (dt->map->tab[i][dt->map->len_hori - 1] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map Border should not contain a charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_j(t_data *dt)
{
	int	j;

	j = 0;
	while (dt->map->tab[0][j])
	{
		if (dt->map->tab[0][j] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map Border should not contain a charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	ft_check_jlen(dt);
}
void	ft_check_jlen(t_data *dt)
{
	int	j;

	j = 0;

	while (dt->map->tab[dt->map->len_vert][j])
	{
		if (dt->map->tab[dt->map->len_vert][j] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map Border should not contain a charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}


void	borders_checker(t_data *dt)
{
	dt->map->len_hori = len_of_2tab_collone(dt);
	ft_check_i(dt);
	dt->map->len_vert = vert_len(dt);
	ft_check_j(dt);
	check_length_of_lignes(dt);
}