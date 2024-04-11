/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:06 by elteran           #+#    #+#             */
/*   Updated: 2024/04/11 16:32:28 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*========UTILS==========*/

void map_size(t_data *mapp, char *file)
{
	int fd;
	char *line;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		 exit(EXIT_FAILURE);
	line = get_next_line(fd);
	mapp->map->width_map = ft_strlen(line) - 1;
	mapp->map->height_map = 0;
	while (line)
	{
		mapp->map->height_map++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
} 
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
	return ;
}

/*========MAP=========*/

// void	map_read(t_data *map, char *file)
// {
// 	int		fd;
// 	char	*cmap;

// 	map_ext(file, ".ber");
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		return ;
// 	close(fd);
// }

/*ESTA ES PARA INCIAR*/
// void init(t_data *game)
// {
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, (game->map->width_map * 32),
// 					(game->map->height_map * 32), "Letsgoyunpeiisback");
// 	mlx_loop(game->mlx);
// }

int key_handler(int keycode, t_data *game)
{
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
    // if (keycode == KEY_D || keycode == KEY_RIGHT)
    //     vars->player.pos.x += 1;
    // else if (keycode == KEY_S || keycode == KEY_LEFT)
    //     vars->player.pos.x -= 1;
    // else if (keycode == KEY_W || keycode == KEY_UP)
    //     vars->player.pos.y -= 1;
    // else if (keycode == KEY_S || keycode == KEY_DOWN)
    //     vars->player.pos.y += 1;
    return (0);
}
/* necesito saber las pocisiones */
/* necesito hacer los movimientos */
