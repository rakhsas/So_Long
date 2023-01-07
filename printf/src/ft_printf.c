/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:52:47 by rakhsas           #+#    #+#             */
/*   Updated: 2022/11/05 00:10:47 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_assign(va_list argptr, const char type)
{
	int	print_length;

	print_length = 0;
	if (type == 'c')
		print_length += ft_printchar(va_arg(argptr, int));
	else if (type == 's')
		print_length += ft_printstr(va_arg(argptr, char *));
	else if (type == 'p')
		print_length += ft_print_ptr(va_arg(argptr, TYPE));
	else if (type == 'd' || type == 'i')
		print_length += ft_printnbr(va_arg(argptr, int));
	else if (type == 'u')
		print_length += ft_print_unsigned(va_arg(argptr, unsigned int));
	else if (type == 'x' || type == 'X')
		print_length += ft_print_hex(va_arg(argptr, unsigned int), type);
	else if (type == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	argptr;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_assign(argptr, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(argptr);
	return (print_length);
}
