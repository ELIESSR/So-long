/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:21:14 by elteran           #+#    #+#             */
/*   Updated: 2024/11/14 22:12:31 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

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

void move_right(t_map *data)
{
    if (data->map[data->y_p][data->x_p + 1] == '0' || 
        data->map[data->y_p][data->x_p + 1] == 'C')
    {
        if(data->map[data->y_p][data->x_p + 1] == 'C')
        {
            data->coincn--;
			printf(GREEN"\n---------------------\nREMAINING SALMON : %i\n---------------------\n\n"CLEAR, data->coincn);
		}
        data->map[data->y_p][data->x_p] = '0';
        data->map[data->y_p][data->x_p + 1] = 'P';
        data->x_p++;
        data->moves++;
        printf("Number of movements : %d\n", data->moves);
    }
	else if (data->map[data->y_p][data->x_p + 1] == 'E' && data->coincn == 0)
        ms_win(data);
	// {
	// 	mlx_clear_window(data->mlx, data->win);
	// 	printf(GREEN"\n\n-------------------YOU WIN-------------------\n\n\n"CLEAR);
	// 	exit(EXIT_FAILURE);
	// }
}

void move_left(t_map *data)
{  
    if (data->map[data->y_p][data->x_p - 1] == '0' || 
        data->map[data->y_p][data->x_p - 1] == 'C')
    {
        if(data->map[data->y_p][data->x_p - 1] == 'C')
		{
            data->coincn--;
			printf(GREEN"\n---------------------\nREMAINING SALMON : %i\n---------------------\n\n"CLEAR, data->coincn);
        }
        data->map[data->y_p][data->x_p] = '0';
        data->map[data->y_p][data->x_p - 1] = 'P';
        data->x_p--;
        data->moves++;
        printf("Number of movements : %d\n", data->moves);
    }
	else if (data->map[data->y_p][data->x_p - 1] == 'E' && data->coincn == 0)
	    ms_win(data);
}
void move_up(t_map *data)
{
    if (data->map[data->y_p - 1][data->x_p] == '0' || 
        data->map[data->y_p - 1][data->x_p] == 'C')
    {
        if(data->map[data->y_p - 1][data->x_p] == 'C')
        {
            data->coincn--;
			printf(GREEN"\n---------------------\nREMAINING SALMON : %i\n---------------------\n\n"CLEAR, data->coincn);
        }
		data->map[data->y_p][data->x_p] = '0';
        data->map[data->y_p - 1][data->x_p] = 'P';
        data->x_p--;
        data->moves++;
        printf("Number of movements : %d\n", data->moves);
    }
	else if (data->map[data->y_p - 1][data->x_p] == 'E' && data->coincn == 0)
	    ms_win(data);
}

void move_down(t_map *data)
{
    if (data->map[data->y_p + 1][data->x_p] == '0' || 
        data->map[data->y_p + 1][data->x_p] == 'C')
    {
        if(data->map[data->y_p + 1][data->x_p] == 'C')
        {
            data->coincn--;
			printf(GREEN"\n---------------------\nREMAINING SALMON : %i\n---------------------\n\n"CLEAR, data->coincn);
        }
		data->map[data->y_p][data->x_p] = '0';
        data->map[data->y_p + 1][data->x_p] = 'P';
        data->y_p++;
        data->moves++;
        printf("Number of movements : %d\n", data->moves);
    }
	else if (data->map[data->y_p + 1][data->x_p] == 'E' && data->coincn == 0)
	    ms_win(data);
}
