/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:19 by elteran           #+#    #+#             */
/*   Updated: 2024/11/14 19:22:17 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int init_images(t_map *mapp)
{
	int i = mapp->width_map;
	int j = mapp->height_map;
    // Implementación para inicializar las imágenes en mapp->img
    mapp->img = malloc(sizeof(t_img));
    if (!mapp->img) 
		return 0;

    mapp->img->wall = mlx_xpm_file_to_image(mapp->mlx, "textures/tree.xpm", &i, &j);
    mapp->img->floor = mlx_xpm_file_to_image(mapp->mlx, "textures/floor.xpm", &i, &j);
    mapp->img->player = mlx_xpm_file_to_image(mapp->mlx, "textures/bear.xpm", &i, &j);
    mapp->img->player_left = mlx_xpm_file_to_image(mapp->mlx, "textures/bear_left.xpm", &i, &j);
    mapp->img->exit = mlx_xpm_file_to_image(mapp->mlx, "textures/cave.xpm", &i, &j);
    mapp->img->coin = mlx_xpm_file_to_image(mapp->mlx, "textures/salmon.xpm", &i, &j);

    if (!mapp->img->wall || !mapp->img->player || !mapp->img->exit || !mapp->img->coin)
       	ms_error("BAD_SPRITES");
    return 1; // Devuelve 1 si tiene éxito, 0 en caso de error
}
void	put_sprites(t_map *mapp, int *i, int  *j)
{
	if (!mapp || !mapp->map)
	{
        exit(EXIT_FAILURE);
    }
	if (*i < 0 || *j < 0 || *i >= mapp->height_map || *j >= mapp->width_map)
	{
    	exit(EXIT_FAILURE);
	}
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
	position_P(mapp);
}

int ft_draw(t_map *mapp)
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
        }
        i++;
    }
	return  (0);
}

// int	draw_map(t_map *mapp)
// {
// 	ft_draw(mapp);
// 	return (0);
// }
