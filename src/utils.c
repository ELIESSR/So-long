
#include "../so_long.h"

void	ms_error(char *str)
{
	ft_putstr_fd(RED "ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}

void ms_win(t_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	printf(GREEN"\n\n-------------------YOU WIN-------------------\n\n\n"CLEAR);
	exit(EXIT_FAILURE);
}

void free_map(char **map, char *str)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	ms_error(str);
}

void	map_ext(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (str[i + j + 1] == '\0' && to_find[j + 1] == '\0')
				 exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}