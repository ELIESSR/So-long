/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:19 by elteran           #+#    #+#             */
/*   Updated: 2024/04/11 18:01:55 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_floor(t_data *flr)
{
	int i;
	int j;

	i = 0;
	while(flr->map->map[i])
	{
		j = 0; 
		while(flr->map->map[i][j])
		{
			mlx_put_image_to_window(flr->mlx, flr->win, flr->img->floor, 
						i * 32, j * 32);
			j++;
		}
		i++;
	}
}

void	put_sprites(t_data *mapp)
{	
	int i;
	int j;

	i = 0;
	while (mapp->map->map[i])
    {
		j = 0;
		while(mapp->map->map[i][j])
		{
			if(mapp->map->map[i][j] == '1')
			mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->wall, 
						i * 32, j * 32);
			if(mapp->map->map[i][j] == 'P')
			mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->player, 
						i * 32, j * 32);
			if(mapp->map->map[i][j] == 'E')
			mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->exit, 
						i * 32, j *32);
			if(mapp->map->map[i][j] == 'C')
			mlx_put_image_to_window(mapp->mlx, mapp->win, mapp->img->coin, 
						i * 32, j * 32);
			j++;
		}
		i++;
	}
}
// void *render_to_map(t_data *images)
// {
    
// }