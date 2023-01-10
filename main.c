/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:31 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/10 12:44:03 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*opener(t_data *dt, char *path)
{
	int		fd;
	char	*str;

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

void	check_path(char **map, int i, int j, t_data *dt)
{
	if (i < 0 || j < 0 || i >= dt->map->len_vert
		|| j >= dt->map->len_hori || map[i][j] == '1')
		return ;
	map[i][j] = '1';
	check_path(dt->map->c_tab, i + 1, j, dt);
	check_path(dt->map->c_tab, i - 1, j, dt);
	check_path(dt->map->c_tab, i, j + 1, dt);
	check_path(dt->map->c_tab, i, j - 1, dt);
}

void	check_path2(char **map, int i, int j, t_data *dt)
{
	if (i < 0 || j < 0 || i >= dt->map->len_vert
		|| j >= dt->map->len_hori || map[i][j] == 'E' || map[i][j] == '1')
		return ;
	map[i][j] = '1';
	check_path2(dt->map->c2_tab, i + 1, j, dt);
	check_path2(dt->map->c2_tab, i - 1, j, dt);
	check_path2(dt->map->c2_tab, i, j + 1, dt);
	check_path2(dt->map->c2_tab, i, j - 1, dt);
}

void	f_initialize(t_data *dt)
{
	dt->img->img_x = 50;
	dt->img->img_y = 50;
	dt->img->win_x = dt->map->len_hori *dt->img->img_x;
	dt->img->win_y = dt->map->len_hori *dt->img->img_y;
}
void ft_images(t_data *dt)
{
	printf("fasfsad");
	int	i;
	int	j;

	i = 0;
	while (dt->map->tab[i])
	{
		j = 0;
		while (dt->map->tab[i][j])
		{
			if (dt->map->tab[i][j] == '1')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/brique.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, i * 50, j * 50);
			}
			else if (dt->map->tab[i][j] == '0')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/way.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, i * 50, j * 50);
			}
			else if (dt->map->tab[i][j] == 'E')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/door.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, i * 50, j * 50);
			}
			else if (dt->map->tab[i][j] == 'P')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/.bihi", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, i * 50, j * 50);
			}
			j++;
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	t_data	*dt;

	if (ac == 2)
	{
		dt = malloc(sizeof(t_data));
		dt->map = ft_calloc(sizeof(t_map), 1);
		dt->img = ft_calloc(sizeof(t_img), 1);
		dt->map->ptr = ft_strdup("");
		dt->map->ptr = opener(dt, av[1]);
		say_hello(dt);
		dt->cp_count_c = 0;
		check_path(dt->map->c_tab, dt->p_pos_i, dt->p_pos_j, dt);
		if (checker_chars_c_tab(dt->map->c_tab, 'C') != 0
			|| checker_chars_c_tab(dt->map->c_tab, 'E') != 0)
		{
			ft_printf("\033[0;31mError\nThe map Is Invalid\033[0m");
			exit(EXIT_FAILURE);
		}
		check_path2(dt->map->c2_tab, dt->p_pos_i, dt->p_pos_j, dt);
		if (checker_chars_c_tab(dt->map->c2_tab, 'C') != 0)
		{
			ft_printf("\033[0;31mError\nThe map Is Invalid\033[0m");
			exit(EXIT_FAILURE);
		}

		f_initialize(dt);
		printf("%d\t%d", dt->img->win_x, dt->img->win_y);
		dt->mlx_ptr = mlx_init();
		dt->win_ptr = mlx_new_window(dt->mlx_ptr, dt->img->win_x, dt->img->win_y, "so_long");
		//ft_images(dt);
		mlx_loop(dt->mlx_ptr);
	}
}
