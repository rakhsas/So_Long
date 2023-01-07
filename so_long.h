/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:52:39 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 14:31:07 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_data
{
	int				win_x;
	int				win_y;
	void			*win_ptr;
	void			*mlx_ptr;
	char			*ptr;
	char			*str;
}	t_data;

#define BUFFER_SIZE 10

int		check_n(char *save);
void	*ft_memove(void *dst, const void *src, size_t len);
char	*join_str(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*get_line(char *save);
char	*get_free(char *buff);
char	*get_save(char *save);
//	Checker Map FIles
int		checker_e(t_data *dt);
int		checker_p(t_data *dt);
int		checker_c(t_data *dt);
int		checker_0(t_data *dt);
int		checker_1(t_data *dt);
#endif
