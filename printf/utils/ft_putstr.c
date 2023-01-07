/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:52:24 by rakhsas           #+#    #+#             */
/*   Updated: 2022/11/03 18:06:24 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(char *str)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(str);
	while (len > index)
	{
		ft_putchar(index[str]);
		index++;
	}
}
