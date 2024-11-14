/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:06 by elteran           #+#    #+#             */
/*   Updated: 2024/11/14 17:49:10 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*IMPORTANTE*/
//tengo que arreglar map_ext
//arreglar check_rectangular
//comprobar si es jugable

void	map_read(t_map *mapp, char *file)
{
	int		fd;

 	//map_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ms_error("FILE");
	ft_maplloc(mapp, file);
	map_check(mapp);
	
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
	if (!data->map)
	{
		free(data);
		close(fd);
	}
	while (i < data->height_map)
	{
		gnl = get_next_line(fd);
		if (!gnl)
		{
			free(gnl);
			free(data);
			close(fd);
		}
		data->map[i] = ft_strdup(gnl);
		//if (!data->map[i])
		data->map[i][data->width_map] = '\0';
		i++;
		free(gnl);
	}
	data->map[i] = 0;
	close(fd);
}

int main(int ac, char *argv[])
{
	t_map	mapp;

	mapp.moves = 0;
	if (ac != 2)
		ms_error("BAD_ARGUMENTS!\n");
	else
	{
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
		printf("Number of movements : %d\n", mapp.moves);
		mlx_loop_hook(mapp.mlx, draw_map, &mapp);
		mlx_hook(mapp.win, KEY_CLOSE_WIN, 0, x_pressed, &mapp);
		mlx_key_hook(mapp.win, key_handler, &mapp);
		mlx_loop(mapp.mlx);
	}
	return (0);
}
