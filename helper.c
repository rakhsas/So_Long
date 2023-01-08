/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:54:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/08 18:43:31 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newline(t_data *dt)
{
	int	i;

	i = 0;
	if (dt->map->ptr[0] == '\n')
	{
		ft_printf("\033[0;31mThe Map should not begin with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
	while (dt->map->ptr[i])
	{
		if (dt->map->ptr[i] == '\n')
		{
			if (dt->map->ptr[i + 1] == '\n')
			{
				ft_printf("\033[0;31mThe Map should not contain successive New Line\033[0m");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	int a = ft_strlen(dt->map->ptr);
	if (dt->map->ptr[a - 1] == '\n')
	{
		ft_printf("\033[0;31mThe Map should not end with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
}


void	checker(t_data *dt)
{
	if (checker_chars(dt, 'E') > 1 || checker_chars(dt, 'E') == 0)
	{
		ft_printf("\033[0;31mThe Map should not contain more then One Exit and at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_chars(dt, 'P') > 1 || checker_chars(dt, 'P') == 0)
	{
		ft_printf("\033[0;31mThe Map should not contain more then One Player and at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_chars(dt, 'C') == 0)
	{
		ft_printf("\033[0;31mThe Map should contain at least One Collectible\033[0m");
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
			ft_printf("\033[0;31mThe Map should not contain characters different to C, E, P, 0, 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	checker(dt);
	check_newline(dt);
}
