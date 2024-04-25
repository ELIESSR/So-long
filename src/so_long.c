/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:06 by elteran           #+#    #+#             */
/*   Updated: 2024/04/24 19:04:08 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*========UTILS==========*/

// void map_size(t_data *mapp, char *file)
// {
// 	int fd;
// 	char *line;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		 ms_error("FILE");
// 	line = get_next_line(fd);
// 	mapp->map->width_map = ft_strlen(line) - 1;
// 	mapp->map->height_map = 0;
// 	while (line)
// 	{
// 		mapp->map->height_map++;
// 		line = get_next_line(fd);
// 		free(line);
// 	}
// 	close(fd);
// } 

void	map_malloc(t_data *m, int h, int w)
{
	int	i;
	int j;

	printf("el coño de su madre\n");
	m->map->map = (char **)malloc(sizeof(int ) * h);
	printf("el coño de su madre\n");
	i = -1;
	while (i < h)
	{
		printf("el coño de su madre\n");
		m->map->map = malloc(sizeof(int *) * w);
		i++;
	}
	i = -1;printf("el coño de su madre\n");
	while (i < h)
	{
		j = -1;
		while (j < w)
		{
			printf("el coño de su madre\n");
			m->map->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	map_read(t_data *map, char *file)
{
	printf("map read\n");
	int h;
	int w;
	int		fd;

/* 	map_ext(file, ".ber"); */
	h = 0;
	w = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ms_error("FILE");
	printf("pudo leer sin error\n");
	printf("no tiene el tamaño\n");
	w = map_width(w, file);
	printf("w es %d\n", w);
	h = map_height(h, file);
	printf("h es %d\n", h);
	map_malloc(map, h, w);
	printf("reservo el espacio de memoria\n");
	map_check(map, h, w);
	printf("todo bien\n");
	
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
	
	game = malloc(sizeof(t_data));
	if (ac != 2)
		ms_error("Bad arguments\n");
	else
	{
		printf( GREEN "entro al else\n");
		game->mlx = mlx_init();
		printf("inicio la ventana \n");
		map_read(game, argv[1]);
		printf("tiene el mapa\n");

/* 		game_init(&game); */
		game->win = mlx_new_window(game->mlx, (game->map->width_map * 32),
					(game->map->height_map * 32), "Letsgoyunpeiisback");
		put_floor(game);

		mlx_loop(game->mlx);
	}
	return (0);
}
