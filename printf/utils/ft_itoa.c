/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:39:26 by rakhsas           #+#    #+#             */
/*   Updated: 2022/11/03 18:50:04 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	ft_absolute(int num)
{
	long long	n;

	n = num;
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_length(int num)
{
	int			len;
	long long	sign;

	len = 1;
	sign = ft_absolute(num);
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	long long	sign;
	char		*str;
	int			i;
	int			len;
	int			l;

	sign = ft_absolute(num);
	len = ft_length(num);
	l = len;
	i = 0;
	if (num < 0)
		len = ++l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		str[i++] = '-';
	while (len > i)
	{
		str[len - 1] = (sign % 10) + '0';
		sign /= 10;
		len--;
	}
	str[l] = '\0';
	return (str);
}
