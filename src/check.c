/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:15 by elteran           #+#    #+#             */
/*   Updated: 2024/11/14 16:44:54 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	correct_character(t_map *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'P' && data->map[j][i] != 'E'
				&& data->map[j][i] != 'C')
				ms_error("CHAR_ERROR!");
			else
			{
				i++;
			}
		}
		j++;
	}
}

void	check_characters(t_map *mapp)
{
	int i;
	int j;

	i = 0;
	while (mapp->map[i])
	{
		j = 0;
		while (mapp->map[i][j])
		{
			if (mapp->map[i][j] == 'P')
				mapp->playercn++;
			if (mapp->map[i][j] == 'E')
				mapp->endcn++;
			if (mapp->map[i][j] == 'C')
				mapp->coincn++;
			j++;
		}
		i++;
	}
	printf(GREEN"\n---------------------\nSALMON : %i\n---------------------\n\n"CLEAR, mapp->coincn);
	if (mapp->coincn < 1 || mapp->playercn != 1 || 
					mapp->endcn != 1)
		ms_error("BAD_CHARACTER!");
}


void	check_rectangular(t_map *mapp)
{
	int 	i;
	int		j;
	
	i = 0;
	while (mapp->map[i])
	{
		j = 0;
		while(mapp->map[i][j])
		{
			if (ft_strlen(mapp->map[i]) != mapp->width_map)
				ms_error("IT IS NOT RECTANGULAR");
			else if ((i == 0 || i == mapp->height_map - 1) && mapp->map[i][j] != '1')
				ms_error("BAD TOP OR BOTTOM");
			else if ((j == 0 || j == mapp->width_map - 1) && mapp->map[i][j] != '1')
				ms_error("BAD LATERAL");
			j++;
		}
		if (ft_strlen(mapp->map[0]) != ft_strlen(mapp->map[i]))
			free_map(mapp->map, "map pupu");
		i++;
	}
}

void	map_size(t_map *mapp, char *file)
{
	char *gnl;
	int fd;
	int len;

	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
	{
		write(2, "\n\nERROR_READ_MAP!\n\n", 19);
		close(fd);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(gnl) - 1;
	mapp->width_map = len;
	mapp->height_map = 0;
	while (gnl)
	{
    	mapp->height_map++;
    	free(gnl);
	    gnl = get_next_line(fd);
	}
	free(gnl);
	close(fd);
}

void	map_check(t_map *mapp)
{
	mapp->playercn = 0;
	mapp->endcn = 0;
	mapp->coincn = 0;

	correct_character(mapp);
	check_characters(mapp);
	check_rectangular(mapp);	
}
