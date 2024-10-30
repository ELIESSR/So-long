/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:58:36 by elteran           #+#    #+#             */
/*   Updated: 2024/10/30 21:56:46 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int	x_pressed(t_map *mapp)
{
	mlx_destroy_window(mapp->mlx, mapp->win);
	exit(EXIT_SUCCESS);
}

int key_handler(int keycode, t_map *data)
{
	if(keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
    if (keycode == KEY_D || keycode == KEY_RIGHT)
       move_right(data);
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        move_left(data);
    else if (keycode == KEY_W || keycode == KEY_UP)
       move_up(data);
    else if (keycode == KEY_S || keycode == KEY_DOWN)
       move_down(data);
    return (0);
}