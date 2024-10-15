
#include "../so_long.h"

void	ms_error(char *str)
{
	ft_putstr_fd(RED "ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}
void free_map(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(EXIT_FAILURE);
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

// void	game_init(t_data *game)
// {
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, (game->map->width_map * 32),
// 					(game->map->height_map * 32), "Letsgoyunpeiisback");
// 	put_floor(game);
// 	put_sprites(game);
// 	mlx_loop(game->mlx);
// }
