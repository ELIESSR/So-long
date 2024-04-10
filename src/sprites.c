/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:19 by elteran           #+#    #+#             */
/*   Updated: 2024/04/02 19:03:07 by elteran          ###   ########.fr       */
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
						flr->img->width, flr->img->height);
			j++;
		}
		i++;
	}
}

// void	put_sprites(t_data *images)
// {
//     if(== '1')
// 	mlx_put_image_to_window(images->mlx, images->win, images->img->wall, 
// 				images->img->width, images->img->height);
//     if(== 'P')
// 	mlx_put_image_to_window(images->mlx, images->win, images->img->character, 
// 				images->img->width, images->img->height);
// 	if(== 'E')
// 	mlx_put_image_to_window(images->mlx, images->win, images->img->exit, 
// 				images->img->width, imagen->img->height);
// }
// void *render_to_map(t_data *images)
// {
    
// }