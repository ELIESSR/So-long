/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:33 by elteran           #+#    #+#             */
/*   Updated: 2024/04/11 16:33:40 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ================ KEYS ================ */
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define ON_DESTROY 17

#define CLEAR "\x1b[0m"
#define RED "\x1b[31m"
 
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct s_map
{
    char    **map;
    int     height_map;
    int     width_map;
    
} t_map;

typedef struct s_count
{
    int player;
    int coin;
    int end;
           
} t_count;

typedef struct s_img
{
    void    *wall;
    void    *character;
    void    *floor;
    void    *coin;
    void    *exit;
    int		width;
    int		height;

}   t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_img	*img;
    t_count *count;
    
} t_data;

/*UTILS*/

void    free_map(char **map);
void    map_ext(const char *str, const char *to_find);

void	ms_error(char *str);

/*MAP*/

void    map_read(t_map *map, char *file);
int     key_handler(int keycode, t_data *game);
void    init(char *si, t_data *map);

/*CHECK*/

void    check_rectangular(char **map, int y, int x);
void    map_size(t_data *map, char *file);
void	check_characters(t_data *mapp);
void	correct_character(t_data *mapp);
void    map_check(t_data *mapp);
// extern int parsing(int b, char *map);

#endif