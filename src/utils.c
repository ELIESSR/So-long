
#include "../so_long.h"

void	ms_error(char *str)
{
	ft_putstr_fd(RED "ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(CLEAR, 2);
	exit(EXIT_FAILURE);
}
void free_map(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(EXIT_FAILURE);
}

void	map_ext(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (str[i + j + 1] == '\0' && to_find[j + 1] == '\0')
				 exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}

void	game_init(t_data *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map->width_map * 32),
					(game->map->height_map * 32), "Letsgoyunpeiisback");
	put_floor(game);
	put_sprites(game);
	mlx_loop(game->mlx);
}
int map_width(int w, char *file)
{
	int		fd;
	char	*line;
	
	printf("va a leer\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ms_error("ERROR_FILE");
	printf("ningun error al leer\n");
	line = get_next_line(fd);
	w = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return(w);
}

int map_height(int h, char *file)
{
	int fd;
	char *line;
	int i;

	i = 0;
	printf("va a leer\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ms_error("ERROR_FILE");
	printf("ningun error al leer\n");
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
		free(line);
	}
	h += i;
	close(fd);
	return(h);
}
// void	map_size(/* t_data *mapp */ char *file)
// {
// 	int		fd;
// 	int		height;
// 	int		width;
// 	char	*line;

// 	printf("va a leer\n");
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		ms_error("ERROR_FILE");
// 	printf("ningun error al leer\n");
// 	line = get_next_line(fd);
// 	width = ft_strlen(line) - 1;
// 	printf("el ancho es %d\n", width);
// 	free(line);
// 	height = 0;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		height++;
// 		free(line);
// 	}
// 	printf("el alto es %d\n", height);
// 	close(fd);
// /* 	mapp->map->height_map = height; */
// 	printf("el alto es %d\n", height);
// /* 	mapp->map->width_map += width; */
// 	printf("el coño de su madre\n");
// 	/* 
// 	map->main_char = 0;
// 	map->exit = 0;
// 	map->items = 0; */
// 	// char	*gnl;
// 	// int		fd;
// 	// int		strlen;
// 	// fd = open(file, O_RDONLY);
// 	// gnl = get_next_line(fd);
// 	// if (!gnl)
// 	// {
// 	// 	write(2, "\n\nERROR_READ_MAP\n\n", 19);
// 	// 	exit(EXIT_FAILURE);
// 	// }
// 	// strlen = ft_strlen(gnl) - 1;
// 	// mapp->map->width_map = strlen;
// 	// mapp->map->height_map = 0;
// 	// while (gnl)
// 	// {
// 	// 	if (strlen != mapp->map->width_map)
// 	// 	{
// 	// 		write(2, "\n\nMAP_SIZE_ERROR\n\n", 19);
// 	// 		exit(EXIT_FAILURE);
// 	// 	}
// 	// 	mapp->map->height_map++;
// 	// 	free(gnl);
// 	// 	gnl = get_next_line(fd);
// 	// }
// 	// gnl = 0;
// 	// close(fd);
// }