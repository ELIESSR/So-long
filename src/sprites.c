/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:19 by elteran           #+#    #+#             */
/*   Updated: 2024/10/15 19:18:45 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	put_floor(t_map *mapp)
// {
// 	int i;
// 	int j;
// 	t_data game;
// 	t_img flr;

// 	i = 0;
// 	while(mapp->map[i])
// 	{
// 		j = 0; 
// 		while(mapp->map[i][j])
// 		{
// 			mlx_put_image_to_window(game.mlx, game.win, flr.floor, 
// 						i * 100, j * 100);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int init_images(t_map *mapp)
{
	int i = mapp->width_map;
	int j = mapp->height_map;
    // Implementación para inicializar las imágenes en mapp->img
    mapp->img = malloc(sizeof(t_img));
    if (!mapp->img) return 0;

    mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx, "textures/tree.xpm", &i, &j);
    mapp->img->floor = mlx_xpm_file_to_image(mapp->mlx, "textures/floor.xpm", &i, &j);
    mapp->img->player = mlx_xpm_file_to_image(mapp->mlx, "textures/bear.xpm", &i, &j);
    mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx, "textures/cave.xpm", &i, &j);
    mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx, "textures/salmon.xpm", &i, &j);

    if (!mapp->img->wall || !mapp->img->player || !mapp->img->exit || !mapp->img->coin) {
        printf("Error al cargar las imágenes\n");
       	exit(EXIT_FAILURE);
    }
    return 1; // Devuelve 1 si tiene éxito, 0 en caso de error
}
void	put_sprites(t_map *mapp, int *i, int  *j)
{
	if (!mapp || !mapp->map)
	{
        printf("Error: mapp o mapp->map es nulo\n");
        exit(EXIT_FAILURE);
    }
	if (*i < 0 || *j < 0 || *i >= mapp->height_map || *j >= mapp->width_map)
	{
        printf("Error: índice fuera de los límites (i=%ls, j=%ls)\n", i, j);
		exit(EXIT_FAILURE);
	}
	  printf("put_sprites: mapp->map[%d][%d] = %c\n", *i, *j, mapp->map[*i][*j]);
	if(mapp->map[*i][*j] == '1')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->wall, 
			(*j) * 64, (*i) * 64);
	else if(mapp->map[*i][*j] == '0')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->floor,
			(*j) * 64, (*i) * 64);
	else if(mapp->map[*i][*j] == 'P')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->player,
			(*j) * 64, (*i) * 64);
	else if(mapp->map[*i][*j] == 'E')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->exit,
			(*j) * 64, (*i) * 64);
	else if(mapp->map[*i][*j] == 'C')
		mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->coin, 
			(*j) * 64, (*i) * 64);
	ft_printf("mamaguebo piso\n");
}

void ft_draw(t_map *mapp)
{
	int j;
	int i;

	i = 0;
    while (i < mapp->height_map)
	{
        j = 0;
        while (j < mapp->width_map)
		{
            put_sprites(mapp, &i, &j);            
			j++;
            printf("la j es = %d\n", j);
        }
        i++;
        printf("la i es = %d\n", i);
    }
}

int	draw_map(t_map *mapp)
{
	ft_draw(mapp);
	// if (/*mapp->count == 0 &&*/ mapp->count->playercn == 1 && mapp->count->endcn == 1)
	// {
	// 	mlx_clear_window(mapp->mlx, mapp->win);
	// 	printf("\n\n-------------------YOU WIN-------------------\n\n\n");
	// 	exit(EXIT_FAILURE);
	// }
	return (0);
}
