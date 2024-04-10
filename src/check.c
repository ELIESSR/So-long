/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:15 by elteran           #+#    #+#             */
/*   Updated: 2024/04/10 15:23:54 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*======CHECK========*/

void	correct_character(t_data *mapp)
{
	int i;
	int j;

	i = 0;
	while (mapp->map->map[i])
	{
		j = 0;
		while (mapp->map->map[i][j])
		{
			if (mapp->map->map[i][j] != 'P' || mapp->map->map[i][j] != '0' || 
					mapp->map->map[i][j] != '1' || mapp->map->map[i][j] != 'C' || 
					mapp->map->map[i][j] != 'E' || mapp->map->map[i][j] != '\n')
				// free_map(mapp->map->map);
				show_error("si 1");
			j++;
		}
		i++;
	}
	
}

void	check_characters(t_data *mapp)
{
	int i;
	int j;

	i = -1;
	correct_character(mapp);
	while (mapp->map->map[i])
	{
		j = -1;
		while (mapp->map->map[i][j])
		{
			if (mapp->map->map[i][j] == 'P')
				mapp->count->player++;
			if (mapp->map->map[i][j] == 'E')
				mapp->count->end++;
			if (mapp->map->map[i][j] == 'C')
				mapp->count->coin++;
			j++;
		}
		i++;
	}
	if (mapp->count->coin < 1 || mapp->count->player != 1 || 
					mapp->count->end != 1)
		// free_map(mapp->map->map);
		show_error("si");
}


void	check_rectangular(char **map, int y, int x)
{
	int 	i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (ft_strlen(map[i]) != x)
				/* free_map(map); */
				show_error("NO ES UNO");
			if ((i == 0 || i == y - 1) && map[i][j] != '1')
				/*free_map(map);  */
				show_error("NO ES UNO");
			else if ((j == 0 || j == x - 1) && map[i][j] != '1')
				/* free_map(map); */
				show_error("NO ES UNO");
			j++;
		}
		i++;
	}
}

void map_check(t_data *mapp)
{
	mapp->count->coin = 0;
	mapp->count->end = 0;
	mapp->count->player = 0;

	check_characters(mapp);//cuantos caracteres hay
	check_rectangular(mapp->map->map, mapp->map->width_map, mapp->map->height_map);
}
