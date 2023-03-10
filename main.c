/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:31 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/12 13:11:15 by rakhsas          ###   ########.fr       */
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
	dt->img->win_x = dt->map->len_hori * dt->img->img_x;
	dt->img->win_y = (dt->map->len_vert + 1) * dt->img->img_y;
}

void ft_images(t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	while (dt->map->tab[i])
	{
		j = 0;
		while (dt->map->tab[i][j])
		{
			if (dt->map->tab[i][j] == 'C')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/col.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, j * 50, i * 50);
			}
			else if (dt->map->tab[i][j] == '0')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bc.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, j * 50, i * 50);
			}
			else if (dt->map->tab[i][j] == 'E')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/door.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, j * 50, i * 50);
			}
			else if (dt->map->tab[i][j] == 'P')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bihi.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, j * 50, i * 50);
			}
			else if (dt->map->tab[i][j] == '1')
			{
				dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/wa.xpm", &dt->img->img_x, &dt->img->img_y);
				mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, j * 50, i * 50);
			}
			j++;
		}
		i++;
	}
}
void	ft_exit(t_data *dt)
{
	printf("\033[32mCongratulations !!\tYou did %d moves\033[0m", dt->move);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	exit(EXIT_SUCCESS);
}
void	move_up(t_data *dt, int	x)
{
	if (dt->map->tab[x - 1][dt->p_pos_j] != '1' && dt->map->tab[x - 1][dt->p_pos_j] != 'E')
	{
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bihi.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, (x - 1) * 50);
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bc.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, x * 50);
		if (dt->map->tab[x - 1][dt->p_pos_j] == 'C')
		{
			dt->count_c--;
			dt->map->tab[x - 1][dt->p_pos_j] = '0';
		}
		dt->p_pos_i -= 1;
		dt->move++;
	}
	if (dt->map->tab[x - 1][dt->p_pos_j] == 'E' )
	{
		if (dt->count_c == 0)
			ft_exit(dt);
		else
			printf("pas encore collecter les C %d\n ", dt->count_c);
	}
}

void	move_down(t_data *dt, int	x)
{
	if (dt->map->tab[x + 1][dt->p_pos_j] != '1' && dt->map->tab[x + 1][dt->p_pos_j] != 'E')
	{
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bihi.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, (x + 1) * 50);
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bc.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, x * 50);
		if (dt->map->tab[x + 1][dt->p_pos_j] == 'C')
		{
			dt->count_c--;
			dt->map->tab[x + 1][dt->p_pos_j] = '0';
		}
		dt->p_pos_i += 1;
		dt->move++;
	}
	if (dt->map->tab[x + 1][dt->p_pos_j] == 'E')
	{
		if(dt->count_c == 0)
			ft_exit(dt);
		else
			printf("pas encore collecter les C %d\n ", dt->count_c);
	}
}

void	move_right(t_data *dt, int	x)
{
	if (dt->map->tab[x][dt->p_pos_j + 1] != '1' && dt->map->tab[x][dt->p_pos_j + 1] != 'E')
	{
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bihi.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, (dt->p_pos_j + 1) * 50, x * 50);
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bc.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, x * 50);
		if (dt->map->tab[x][dt->p_pos_j + 1] == 'C')
		{
			dt->count_c--;
			dt->map->tab[x][dt->p_pos_j + 1] = '0';
		}
		dt->p_pos_j += 1;
		dt->move++;
	}
	if (dt->map->tab[x][dt->p_pos_j + 1] == 'E' )
	{
		if(dt->count_c == 0)
			ft_exit(dt);
		else
			printf("pas encore collecter les C %d\n ", dt->count_c);
	}
}
void	move_left(t_data *dt, int	x)
{
	if (dt->map->tab[x][dt->p_pos_j - 1] != '1' && dt->map->tab[x][dt->p_pos_j - 1] != 'E')
	{
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bihi.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, (dt->p_pos_j - 1) * 50, x * 50);
		dt->img->img_ptr = mlx_xpm_file_to_image(dt->mlx_ptr, "./images/bc.xpm", &dt->img->img_x, &dt->img->img_y);
		mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->img_ptr, dt->p_pos_j * 50, x * 50);
		if (dt->map->tab[x][dt->p_pos_j - 1] == 'C')
		{
			dt->count_c--;
			dt->map->tab[x][dt->p_pos_j - 1] = '0';
		}
		dt->p_pos_j -= 1;
		dt->move++;
	}
	if (dt->map->tab[x][dt->p_pos_j - 1] == 'E')
	{
		if(dt->count_c == 0)
			ft_exit(dt);
		else
			printf("pas encore collecter les C %d\n ", dt->count_c);
	}
}
int    h_key(int key, t_data *dt)
{
	if (key == 126 || key == 13)
		move_up(dt, dt->p_pos_i);
	else if (key == 124 || key == 2)
		move_right(dt, dt->p_pos_i);
	else if (key == 123 || key == 0)
		move_left(dt, dt->p_pos_i);
	else if (key == 125 || key == 1)
		move_down(dt, dt->p_pos_i);
	else if (key == 53)
	{
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
		exit(EXIT_SUCCESS);
	}
	ft_printf("you still have %d collectibles\n", dt->count_c);
	return(0);
}
int	check_extention(char *str, char *ss)
{
	int	i = 0;
	i = ft_strlen(str) - 4;
	int j = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] != ss[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
int mouse()
{
	exit(0);
}
int	main(int ac, char **av)
{
	t_data	*dt;

	if (ac == 2)
	{
		if (!check_extention(av[1], ".ber"))
			return (0);
		dt = malloc(sizeof(t_data));
		dt->map = ft_calloc(sizeof(t_map), 1);
		dt->img = ft_calloc(sizeof(t_img), 1);
		dt->map->ptr = ft_strdup("");
		dt->map->ptr = opener(dt, av[1]);
		say_hello(dt);
		dt->cp_count_c = 0;
		dt->move = 0;
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
		// printf("%d\t%d", dt->img->win_x, dt->img->win_y);
		dt->mlx_ptr = mlx_init();
		dt->win_ptr = mlx_new_window(dt->mlx_ptr, dt->img->win_x, dt->img->win_y, "so_long");
		ft_images(dt);
		mlx_key_hook(dt->win_ptr, h_key, dt);
		mlx_hook(dt->win_ptr, 17, 0, mouse, dt);
		mlx_loop(dt->mlx_ptr);
	}
}
