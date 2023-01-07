/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:52:39 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 22:10:09 by rakhsas          ###   ########.fr       */
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
	char			**tab;
}	t_data;

#define BUFFER_SIZE 10

int		check_n(char *save);
void	*ft_memove(void *dst, const void *src, size_t len);
char	*join_str(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*get_line(char *save);
char	*get_free(char *buff);
char	*get_save(char *save);
int	checker_c(char *c);
//	Checker Map FIles
int		checker_e(char *dt);
int		checker_p(char *dt);
// border checker
void		ft_check_i(t_data *dt);
void	ft_check_j(t_data *dt);
void	borders_checker(t_data *dt);

void	check_newline(t_data *dt);
int		vert_len(t_data	*dt);
void	check_errno1(t_data *dt);
int		len_of_2tab_ligne(t_data *dt);
int		len_of_2tab_collone(t_data *dt);
void	check_length_of_lignes(t_data *dt);
#endif
