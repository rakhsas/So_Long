/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:54:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 19:09:33 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	vert_len(t_data	*dt)
{
	int i = 0;
	int j = 0;
	while (i[dt->ptr])
	{
		if (i[dt->ptr] == '\n')
			j++;
		i++;
	}
	return (j);
}
void	check_newline(t_data *dt)
{
	int	i;

	i = 0;
	if (dt->ptr[0] == '\n')
	{
		ft_printf("\033[0;31mThe Map should not begin with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == '\n')
		{
			if (dt->ptr[i + 1] == '\n')
			{
				ft_printf("\033[0;31mThe Map should not contain successive New Line\033[0m");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	int a = ft_strlen(dt->ptr);
	if (dt->ptr[a - 1] == '\n')
	{
		ft_printf("\033[0;31mError\nThe Map should not end with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
}


void	checker(char *dt)
{
	if (checker_e(dt) > 1 || checker_e(dt) == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should not contain more then One Exit and at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_p(dt) > 1 || checker_p(dt) == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should not contain more then One Playerand at least one\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_c(dt) == 0)
	{
		ft_printf("\033[0;31mError\nThe Map should contain an C\033[0m");
		exit(EXIT_FAILURE);
	}
}

void	check_errno1(t_data *dt)
{
	int i = 0;

	while (dt->ptr[i])
	{
		if (dt->ptr[i] != 'E' && dt->ptr[i] != 'C' && dt->ptr[i] != 'P' && dt->ptr[i] != '1' && dt->ptr[i] != '0' && dt->ptr[i] != '\n')
		{
			ft_printf("\033[0;31mError\nThe Map should not contain characters different to C, E, P, 0, 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	checker(dt->ptr);
	check_newline(dt);
}
