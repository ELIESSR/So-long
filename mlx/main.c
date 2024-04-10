
# include <stdio.h>
# include <mlx.h>
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;

	c1 = c;
	while (*s != '\0' && *s != c1)
		s++;
	if (*s == c1)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}


char	*ft_strdup_gnl(const char *s1)
{
	char		*dup;
	size_t		i;
	size_t		slengh;

	i = 0;
	slengh = ft_strlen_gnl(s1);
	dup = malloc(sizeof(char) * slengh + 1);
	if (dup == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	lens;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	lens = ft_strlen_gnl(s);
	if (len > lens - start)
		len = lens - start;
	if (start >= lens)
		return (ft_strdup_gnl(""));
	sub = malloc(sizeof(char) * (lens + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
char	*read_line(int fd, char *strs)
{
	char	*aux;
	char	*copy;
	int		rb;

	rb = 1;
	aux = (char *)malloc(sizeof(char) * (4 + 1));
	if (!aux)
		return (NULL);
	while (!strs || (!ft_strchr(strs, '\n') && rb > 0))
	{
		rb = read(fd, aux, 4);
		if (rb == -1)
		{
			free(aux);
			free(strs);
			return (NULL);
		}
		aux[rb] = '\0';
		copy = strs;
		strs = ft_strjoin_gnl(strs, aux);
		free(copy);
	}
	free(aux);
	return (strs);
}
char	*ft_printer(char **s)
{
	char	*r;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s) && (*s)[i] == '\n')
		i++;
	r = ft_substr_gnl(*s, 0, i);
	*s = ft_substr_gnl(*s, i, ft_strlen_gnl((const char *)*s));
	if (!*s)
		free(*s);
	free(aux);
	if (!r[0])
	{
		free(r);
		r = NULL;
	}
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*result;

	if (fd < 0 || 4 <= 0)
		return (NULL);
	aux = read_line(fd, aux);
	if (!aux || !aux[0])
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	result = ft_printer(&aux);
	return (result);
}

// int parsing(int b; char *map)
// {

// 	b = open("su.ber", O_RDONLY);
// 	map = get_next_line(b);
// 	while (map)
// 	{
// 		printf("%s", map);
// 		map = get_next_line(b);
// 	} 
// 	close (b);
// 	return (0);
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img2;
	char	*relative_path = "./wall.xpm";
	void	*relative_path2 = "./floor.xpm";
	int		img_width = 32;
	int		img_height = 32;
	int		j;
	int		i;
	// int 	size_x = 2000;
	// int		size_y = 1000;
	int		b;
	char	*map;
	int 	h;
	int		g;

	g = 1;
	h = 0;
	b = open("su.ber", O_RDONLY);
	map = get_next_line(b);
	while (map != '\0')
	{
		printf("%s", map);
		map = get_next_line(b);
	} 
	close (b);

	mlx = mlx_init();
	i = 0;
	while(map[i])
	{
		j = 0; 
		while(map)
		{
			mlx_put_image_to_window(mlx, mlx_win, relative_path2, 
						img_width, img_height);
			j++;
		}
		i++;
	}
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width, &img_height);



	// Verifica si la imagen se cargó correctamente
	// if (!img)
	// {
	// 	printf("Error al cargar la imagen.\n");
	// 	return (1);
	// }
	// while (i <= size_x)
	// {
	// 	if (map[h] == '1')
	// 	{
	// 		mlx_put_image_to_window(mlx, mlx_win, img, i * 20 , j * 20);
	// 		h++;
	// 		i++;
	// 	}
	// 	if (map[h] == '0')
	// 	{
	// 		mlx_put_image_to_window(mlx, mlx_win, img2, i * 20 , j * 20);
	// 		h++;
	// 		i++;
	// 	}
	// 	if (map[j] == '1')
	// 	{
	// 		mlx_put_image_to_window(mlx, mlx_win, img, i * 20 , j * 20);
	// 		h++;
	// 		i++;
	// 	}
	// 	if (map[j] == '0')
	// 	{
	// 		mlx_put_image_to_window(mlx, mlx_win, img2, i * 20 , j * 20);
	// 		h++;
	// 		i++;
	// 	}
	// }
	
	// while (i <= size_x)// Muestra la imagen en la ventana
	// {
	// 	mlx_put_image_to_window(mlx, mlx_win, img, i * 20 , j * 20);
	
	// 	// if(i + 1 == size_x || j <= size_y)
	// 	// {
	// 	// 	i = 0;
	// 	// 	j++; 
	// 	// }
	// 	i++; 
	// }
	// // Permite que la ventana sea visible
	mlx_loop(mlx);
	return (0);
}
