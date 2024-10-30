/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:33 by elteran           #+#    #+#             */
/*   Updated: 2024/10/30 20:55:44 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ================ KEYS ================ */
# define KEY_ESC 65307
# define KEY_W 119       // 'W' key
# define KEY_A 97        // 'A' key
# define KEY_S 115       // 'S' key
# define KEY_D 100       // 'D' key
# define KEY_UP 65362    // Arrow Up
# define KEY_LEFT 65361  // Arrow Left
# define KEY_DOWN 65364  // Arrow Down
# define KEY_RIGHT 65363 // Arrow Right
# define KEY_ESC 65307   // Escape key
# define KEY_CLOSE_WIN 33 // This might vary, as it often depends on the windowing system setup


# define CLEAR "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"

# define PLAYER "textures/bear.xpm"
# define WALL "textures/tree.xpm"
# define COIN "textures/salmon.xpm"
# define FLOOR "textures/floor.xpm"
# define EXIT "textures/cave.xpm"

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_count
{
    int playercn;
    int coincn;
    int endcn;
           
} t_count;

typedef struct s_img
{
    int   *wall;
    int    *player;
    int   *floor;
    int    *coin;
    int    *exit;
    int		width;
    int		height;

}   t_img;

typedef struct s_map
{
    char    **map;
    int     height_map;
    int     width_map;
    int     x_p;
    int     y_p;
    void    *mlx;
    void    *win;
    t_img	*img;
    t_count *count;
    
} t_map;

// typedef struct s_data
// {
//     void    *mlx;
//     void    *win;
//     t_map   *map;
//     t_img	*img;
//     t_count *count;
    
// } t_data;

/*UTILS*/

void    free_map(char **map);
void    map_ext(const char *str, const char *to_find);

void	ms_error(char *str);

/*MAP*/

void    map_read(t_map *map, char *file);
// int     key_handler(int keycode, t_data *game);
// void    init(t_data *game);

void    put_sprites(t_map *mapp, int *i, int *j);
void	put_floor(t_map *mapp);
int     init_images(t_map *mapp);
void    ft_draw(t_map *mapp);
int     draw_map(t_map *mapp);
void	game_init(t_map *game);

/*CHECK*/

void	check_characters(t_map *mapp);
void	check_rectangular(t_map *mapp);

void	correct_character(t_map *data);
//void	correct_character(t_map *mapp);
void    map_check(t_map *mapp);
void    save_map(t_map *mapp, int fd);
void    map_size(t_map *mapp, char *file);
// extern int parsing(int b, char *map);

/*MOVES*/

void    position_P(t_map *data);
int     key_handler(int keycode, t_map *data);
int     x_pressed(t_map *mapp);


//temporal
//void print_map(char **map);
//void *init_map(int rows, int cols);
void	ft_maplloc(t_map *data, char *file);
#endif