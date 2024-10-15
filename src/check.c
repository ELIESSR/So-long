/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:49:15 by elteran           #+#    #+#             */
/*   Updated: 2024/06/25 23:05:29 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*======CHECK========*/

// void	correct_character(t_map *mapp)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (mapp->map[i] != NULL)
// 	{
// 		j = 0;
// 		while(mapp->map[i][j])
// 		{
// 			printf("caracter j : %s \n", mapp->map[j]);
// 			if (mapp->map[i][j] != 'P' && mapp->map[i][j] != '0' && 
// 					mapp->map[i][j] != '1' && mapp->map[i][j] != 'C' && 
// 					mapp->map[i][j] != 'E')
// 				ms_error("character error");
// 			else{
// 				printf("biiaobvr\n");		
// 				j++;
// 			}
// 		}
// 		printf("pemne");
// 		i++;
// 	}
	
// }
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
			printf("caracter j : %s \n", data->map[j]);
			if (data->map[j][i] != '1' && data->map[j][i] != '0'
				&& data->map[j][i] != 'P' && data->map[j][i] != 'E'
				&& data->map[j][i] != 'C')
			{
				write(2, "\n\nCHAR_ERROR\n\n", 15);
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("biiaobvfhddkdkkgfgjhgdr\n");	
				i++;
			}
		}
		printf("pemne\n");
		j++;
	}
}

void	check_characters(t_map *mapp)
{
	int i;
	int j;
	t_count cnt;
	cnt.playercn = 0;
	cnt.endcn = 0;
	cnt.coincn = 0;

	i = 0;
	printf("vamo a conta \n");
	while (mapp->map[i])
	{
		
		printf("vamo a conta 1 \n");
		j = 0;
		while (mapp->map[i][j])
		{
			printf("vamo a conta 2  \n");
			if (mapp->map[i][j] == 'P')
				cnt.playercn++;
			if (mapp->map[i][j] == 'E')
				cnt.endcn++;
			if (mapp->map[i][j] == 'C')
				cnt.coincn++;
			j++;
		}
		i++;
	}
	if (cnt.coincn < 1 || cnt.playercn != 1 || 
					cnt.endcn != 1)
		ms_error("BAD_CHARACTER");
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
		i++;
	}
}

void map_size(t_map *mapp, char *file)
{
	char *gnl;
	int fd;
	int len;

	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s \n", gnl);
	if (!gnl)
	{
		write(2, "\n\nERROR_READ_MAP\n\n", 19);
		close(fd);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(gnl) - 1;
	printf("len es :%d \n", len);
	mapp->width_map = len;
	ft_printf("whidth map es :%d \n", mapp->width_map);
	mapp->height_map = 0;
	while (gnl)
	{
    	mapp->height_map++;
		printf("%d \n", mapp->height_map);
    	free(gnl);
	    gnl = get_next_line(fd);
	    // if (gnl && ft_strlen(gnl) - 1 != mapp->width_map)
		// {
		// 	write(2, "\n\nMAP_SIZE_ERROR\n\n", 19);
		// 	free(gnl);
        // 	close(fd);
        // 	exit(EXIT_FAILURE);
    	// }
	}
	free(gnl);
	close(fd);
}

void map_check(t_map *mapp)
{
	// t_count cnt;
	
	// cnt.coincn = 0;
	// cnt.endcn = 0;
	// cnt.playercn = 0;
	
	correct_character(mapp);
	printf("aAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	check_characters(mapp);//cuantos caracteres hay
	check_rectangular(mapp);
}
