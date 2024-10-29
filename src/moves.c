/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:58:36 by elteran           #+#    #+#             */
/*   Updated: 2024/10/29 19:30:34 by elteran          ###   ########.fr       */
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