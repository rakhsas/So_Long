/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:31 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/08 18:47:49 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *opener(t_data *dt, char *path)
{
	int		fd;
	char *str;

	fd = open(path, O_RDWR);
	dt->map->ptr = NULL;
	while (1)
	{
		dt->map->str = get_next_line(fd);
		if (!dt->map->str)
			break ;
		str = join_str(str, dt->map->str);
	}
	return str;
}
void	check_path(char **map, int i , int j ,t_data *dt)
{
//cas de base
	if(i < 0 || j < 0 || map[i][j]  == '1')
		return;
	map[i][j] = '1';
	check_path(dt->map->c_tab, i + 1 , j ,dt);
	check_path(dt->map->c_tab, i - 1 , j  ,dt);
	check_path(dt->map->c_tab, i , j + 1 ,dt);
	check_path(dt->map->c_tab, i , j - 1 ,dt);
}

int	main(int ac, char **av)
{
	t_data *dt;

	if (ac == 2)
	{
		dt = malloc(sizeof(t_data));
		dt->map = malloc(sizeof(t_map));
		dt->map->ptr = opener(dt, av[1]);

		say_hello(dt);
		dt->map->tab = ft_split(dt->map->ptr, '\n');
		dt->map->c_tab = ft_split(dt->map->ptr, '\n');
		dt->map->c2_tab =ft_split(dt->map->ptr, '\n');
		borders_checker(dt);
		ft_positon_player(dt);
		printf("%d\t%d\n", dt->p_pos_i, dt->p_pos_j);
		check_path(dt->map->c_tab, dt->p_pos_i, dt->p_pos_j, dt);
		// ft_printf("%d", len_of_2tab_ligne(dt));

	}
}
