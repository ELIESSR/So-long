/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:58:36 by elteran           #+#    #+#             */
/*   Updated: 2024/10/30 20:55:17 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void position_P(t_map *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->x_p = j;
                data->y_p = i;
                // printf("X = %d\n", data->x_p);
                // printf("Y = %d\n", data->y_p);
                // exit(EXIT_SUCCESS);
            }
            j++;
        }
        i++;
    }
}

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
