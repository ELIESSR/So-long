/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:06 by elteran           #+#    #+#             */
/*   Updated: 2024/04/12 16:57:21 by elteran          ###   ########.fr       */
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
		 ms_error("FILE");
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

void	map_read(t_data *map, char *file)
{
	int		fd;
	char	*line;
	// int i = 0;

	map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ms_error("FILE");
	line = get_next_line(fd);
	// ft_printf("%s\n" ,line[i]);
	// while (line[i])
	// {
	// 	ft_printf("%s\n" ,line[i]);
	// 	line = get_next_line(fd);
	// 	free(line);
	// 	i ++;
	// }
	map_size(map, file);
	map_check(map);
	close(fd);
}

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

int main(int ac, char *argv[])
{
	t_data *game;
	// int 	i = 0;
	// int		fd = open(*argv, O_RDONLY); 
	// char	*line = get_next_line(fd);
	
	game = ft_calloc(1, sizeof(t_data));
	if (ac != 2)
		ms_error("Bad arguments\n");
	else
	{
		// while (line[i])
		// {
		// 	ft_printf("%s\n" ,line[i]);
		// 	line = get_next_line(fd);
		// 	free(line);
		// 	i ++;
		// }
		map_read(game, argv[1]);
		game_init(game);
	}
	return (0);
}
