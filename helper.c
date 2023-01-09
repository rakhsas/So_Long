/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:54:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/10 00:55:25 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newline(t_data *dt)
{
	int	i;

	i = 0;
	if (dt->map->ptr[0] == '\n')
	{
		ft_printf("\033[0;31mError\nThe Map ");
		ft_printf("should not begin with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
	while (dt->map->ptr[i])
	{
		if (dt->map->ptr[i] == '\n')
		{
			if (dt->map->ptr[i + 1] == '\n')
			{
				ft_printf("\033[0;31mError\nThe Map should not contain successive New Line\033[0m");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	int a = ft_strlen(dt->map->ptr);
	if (dt->map->ptr[a - 1] == '\n')
	{
		ft_printf("\033[0;31mError\nThe Map should not end with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
}

void	checker(t_data *dt)
{
	dt->count_c = checker_chars(dt, 'C');
	dt->count_p = checker_chars(dt, 'P');
	dt->count_e = checker_chars(dt, 'E');
	if (dt->count_e > 1 || dt->count_e == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should not ");
		ft_printf("contain more then One Exit and at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (dt->count_p > 1 || dt->count_p == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should not");
		ft_printf(" contain more then One Player and at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (dt->count_c == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should contain at least One Collectible\033[0m");
		exit(EXIT_FAILURE);
	}
}

void say_hello(t_data *dt)
{
	int i = 0;

	while (dt->map->ptr[i])
	{
		if (dt->map->ptr[i] != 'E' && dt->map->ptr[i] != 'C' && dt->map->ptr[i] != 'P' && dt->map->ptr[i] != '1' && dt->map->ptr[i] != '0' && dt->map->ptr[i] != '\n')
		{

			ft_printf("\033[0;31mError\nThe Map should not contain characters different to C, E, P, 0, 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	checker(dt);
	check_newline(dt);
	dt->map->tab = ft_split(dt->map->ptr, '\n');
	dt->map->c_tab = ft_split(dt->map->ptr, '\n');
	dt->map->c2_tab = ft_split(dt->map->ptr, '\n');
	ft_positon_player(dt);
	borders_checker(dt);
}
