#include "so_long.h"
int	opener(char *path)
{
	int fd = open(path, O_RDWR);
	return (fd);
}
int main (int ac, char **av)
{
	t_data *dt;
	if (!dt = malloc(sizeof(t_data)))
		return (NULL);
	int fd = open("basic.ber", O_RDWR);
	while (1)
	{
		dt->str = get_next_line(fd);
		if (!dt->str)
			break;
		dt->ptr = join_str(dt->ptr, dt->str);
	}
	ft_printf("%s", dt->ptr);
}
