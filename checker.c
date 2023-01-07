/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:00 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 21:43:21 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_e(char *c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (c[i])
	{
		if (c[i] == 'E')
			counter++;
		i++;
	}
	return (counter);
}

int	checker_p(char *c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (c[i])
	{
		if (c[i] == 'P')
			counter++;
		i++;
	}
	return (counter);
}

int	checker_c(char *c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (c[i])
	{
		if (c[i] == 'C')
			counter++;
		i++;
	}
	return (counter);
}

void	ft_check_i(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->tab[i])
	{
		if (dt->tab[i][0] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map");
			ft_printf(" Border should not contain a");
			ft_printf(" charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_j(t_data *dt)
{
	int	j;

	j = 0;
	while (dt->tab[0][j])
	{
		if (dt->tab[0][j] != '1')
		{
			ft_printf("\033[0;31mError\nThe Map Border should not contain a charater different to 1\033[0m");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}
