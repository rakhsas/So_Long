/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:17:24 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/08 13:27:55 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// char	*error_line(int i)
// {
// 	char **t = NULL;
// 	t[0] = "The Map should not begin with a New Line";
// 	t[1] = "The Map should not contain successive New Line";
// 	t[2] = "The Map should not end with a New Line";
// 	t[3] = "The Map should not contain more then One Exit and at least one";
// 	t[4] = "The Map should not contain more then One Player and at least one";
// 	t[5] = "The Map should contain an C";
// 	t[6] = "The Map should not contain characters different to C, E, P, 0, 1";
// 	t[7] = "The Map Border should not contain a charater different to 1";
// 	return t[i];
// }
// void ft_error(int	i)
// {
// 	ft_printf("\033[0;31m%s\033[0m", error_line(i));
// 	exit(EXIT_FAILURE);
// }