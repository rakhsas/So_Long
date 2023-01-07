/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:31 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/07 22:10:23 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*opener(char *path)
{
	t_data	*dt;
	int		fd;

	dt = malloc(sizeof(t_data));
	if (!dt)
		return (NULL);
	fd = open(path, O_RDWR);
	dt->ptr = NULL;
	while (1)
	{
		dt->str = get_next_line(fd);
		if (!dt->str)
			break ;
		dt->ptr = join_str(dt->ptr, dt->str);
	}
	return (dt);
}

int	len_of_2tab_ligne(t_data *dt)
{
	int	i;

	i = 0;
	while (dt->tab[i])
		i++;
	return (i);
}

int	len_of_2tab_collone(t_data *dt)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (dt->tab[i][j])
		j++;
	return (j);
}

void	borders_checker(t_data *dt)
{
	ft_check_i(dt);
	ft_check_j(dt);
}

int	main(int ac, char **av)
{
	t_data	*dt;

	if (ac == 2)
	{
		dt = opener(av[1]);
		check_errno1(dt);
		dt->tab = ft_split(dt->ptr, '\n');
		borders_checker(dt);
		check_length_of_lignes(dt);
	}
}
