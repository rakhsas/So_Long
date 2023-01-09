/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:31 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/09 20:37:31 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *opener(t_data *dt, char *path)
{
	int		fd;
	char *str;

	fd = open(path, O_RDWR);
	while (1)
	{
		dt->map->str = get_next_line(fd);
		if (!dt->map->str)
			break ;
		str = join_str(str, dt->map->str);
	}
	return (str);
}
void	check_path(char **map, int i , int j ,t_data *dt)
{
//cas de base
	if(i < 0 || j < 0 || i >= dt->map->len_vert || j >= dt->map->len_hori || map[i][j]  == '1' )// map[i] [j] == 'E')
		return ;
	map[i][j] = '1';
	check_path(dt->map->c_tab, i + 1 , j, dt);
	check_path(dt->map->c_tab, i - 1 , j, dt);
	check_path(dt->map->c_tab, i , j + 1, dt);
	check_path(dt->map->c_tab, i , j - 1, dt);
}
void	check_path2(char **map, int i , int j ,t_data *dt)
{
//cas de base
	if(i < 0 || j < 0 || i >= dt->map->len_vert || j >= dt->map->len_hori || map[i][j]  == '1'||  map[i] [j] == 'E')
		return ;
	map[i][j] = '1';
	check_path(dt->map->c2_tab, i + 1 , j, dt);
	check_path(dt->map->c2_tab, i - 1 , j, dt);
	check_path(dt->map->c2_tab, i , j + 1, dt);
	check_path(dt->map->c2_tab, i , j - 1, dt);
}

int	main(int ac, char **av)
{
	t_data *dt;

	if (ac == 2)
	{
		dt = malloc(sizeof(t_data));
		dt->map = ft_calloc(sizeof(t_map), 1);
		dt->map->ptr = ft_strdup("");
		dt->map->ptr = opener(dt, av[1]);
		say_hello(dt);
		dt->map->tab = ft_split(dt->map->ptr, '\n');
		dt->map->c_tab = ft_split(dt->map->ptr, '\n');
		dt->map->c2_tab =ft_split(dt->map->ptr, '\n');
		ft_positon_player(dt);
		borders_checker(dt);
		dt->cp_count_c = 0;
		check_path(dt->map->c_tab, dt->p_pos_i, dt->p_pos_j, dt);
		// printf("%d\t%d\n", checker_chars_c_tab(dt, 'C'), dt->count_c);
		if (checker_chars_c_tab(dt->map->c_tab, 'C') != 0)
		{
			ft_printf("\033[0;31mError\nThe map Is Invalid\033[0m");
			exit(EXIT_FAILURE);
		}
		check_path2(dt->map->c2_tab, dt->p_pos_i, dt->p_pos_j, dt);
		if (checker_chars_c_tab(dt->map->c2_tab, 'E') != 1)
		{
			ft_printf("\033[0;31mError\nThe map Is Invalid0000\033[0m");
			exit(EXIT_FAILURE);
		}
		// check_c_tab
		// chek_e
		// check_path(c_2)
		// checck_c2_tab
		// int i = 0;
		// int j = 0;
		// while(dt->map->c_tab[i])
		// {
		// 	j = 0;
		// 	while (dt->map->c_tab[i][j])
		// 	{
		// 		ft_printf("%c", dt->map->c_tab[i][j]);
		// 		j++;
		// 	}
		// 	i++;
		// }

	}
}
