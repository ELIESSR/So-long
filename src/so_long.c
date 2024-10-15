/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:06 by elteran           #+#    #+#             */
/*   Updated: 2024/10/15 19:19:04 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	map_read(t_map *mapp, char *file)
{
	ft_printf("map read\n");
	int		fd;

 	//map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd == -1)
		ms_error("FILE");
	printf("CORRECTO\n");
	
	// map_size(mapp, file);
	ft_maplloc(mapp, file);
	map_check(mapp);
	printf("todo bien\n");
	
	close(fd);
}

void	ft_maplloc(t_map *data, char *file)
{
	int		fd;
	char	*gnl;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->height_map + 1));
	//if (!data->map)
	while (i < data->height_map)
	{
		gnl = get_next_line(fd);
		//if (!gnl)
		data->map[i] = ft_strdup(gnl);
		// if (!data->map[i])
		data->map[i][data->width_map] = '\0';
		i++;
		free(gnl);
	}
	data->map[i] = 0;
	close(fd);
}


// int key_handler(int keycode, t_data *game)
// {
// 	if(keycode == KEY_ESC)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(EXIT_SUCCESS);
// 	}
//     // if (keycode == KEY_D || keycode == KEY_RIGHT)
//     //     vars->player.pos.x += 1;
//     // else if (keycode == KEY_S || keycode == KEY_LEFT)
//     //     vars->player.pos.x -= 1;
//     // else if (keycode == KEY_W || keycode == KEY_UP)
//     //     vars->player.pos.y -= 1;
//     // else if (keycode == KEY_S || keycode == KEY_DOWN)
//     //     vars->player.pos.y += 1;
//     return (0);
// }
/* necesito saber las pocisiones */
/* necesito hacer los movimientos */

int main(int ac, char *argv[])
{
	// t_data game;
	t_map  mapp;
	
	//game = malloc(sizeof(t_data));
	if (ac != 2)
		ms_error("Bad arguments\n");
	else
	{
		printf( GREEN "entro al else\n");
		//game->mlx = mlx_init();
		printf("inicio Sla ventana \n");
		printf("argumento 01 es : %s \n", argv[1]);
		map_size(&mapp, argv[1]);
		map_read(&mapp, argv[1]);

 		mapp.mlx = mlx_init();
		
		mapp.win = mlx_new_window(mapp.mlx, (mapp.width_map * 64),
					(mapp.height_map * 64), "Letsgoyunpeiisback");
		if (!init_images(&mapp))
		{
            fprintf(stderr, "Error al inicializar las imágenes\n");
            return 1;
		}
		mlx_loop_hook(mapp.mlx, draw_map, &mapp);
		mlx_loop(mapp.mlx);
	}
	return (0);
}
