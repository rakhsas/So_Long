/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:00 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 15:34:01 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_e(t_data *dt)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == 'E')
			counter++;
		i++;
	}
	return (i);
}

int	checker_p(t_data *dt)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == 'P')
			counter++;
		i++;
	}
	return (i);
}

int	checker_c(t_data *dt)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == 'C')
			counter++;
		i++;
	}
	return (i);
}

int	checker_0(t_data *dt)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == '1')
			counter++;
		i++;
	}
	return (i);
}

int	checker_1(t_data *dt)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (dt->ptr[i])
	{
		if (dt->ptr[i] == '0')
			counter++;
		i++;
	}
	return (i);
}
