/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:54:49 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 15:42:11 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	check_newline(t_data *dt)
{
	if (dt->ptr[0] == '\n')
	{
		ft_printf("\033[0;31mThe Map should not begin with a New Line\033[0m");
		exit(EXIT_FAILURE);
	}
	while (dt->ptr[i] == '\n')
	{
		if (dt->ptr[i + 1] == '\n')
		{
			ft_printf("\033[0;31mThe Map should not contain successive New Line\033[0m");
			exit(EXIT_FAILURE);
		}
	}
}

void	checker(t_data *dt)
{
	if (checker_e(dt->ptr) > 1)
	{
		ft_printf("\033[0;31mThe Map should not contain more then One Exit\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_p(dt->ptr) > 1)
	{
		ft_printf("\033[0;31mThe Map should not contain more then One Player\033[0m");
		exit(EXIT_FAILURE);
	}
	else if (checker_c(dt->ptr) == 0)
	{
		ft_printf("\033[0;31mThe Map should not contain more then One Player\033[0m");
		exit(EXIT_FAILURE);
	}
}

void	check_errno1(t_data *dt)
{
	int i = 0;

	while (dt->ptr[i])
	{
		if (dt->ptr[i] != 'E' && dt->ptr[i] != 'C' && dt->ptr[i] != 'C' && dt->ptr[i] != '1' && dt->ptr[i] != '0' && dt->ptr[i] != 'P')
		{
			ft_printf("\033[0;31mThe Map should not contain characters different to C, E, P, 0, 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	checker(dt->ptr);
}
