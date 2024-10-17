/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:17 by elteran           #+#    #+#             */
/*   Updated: 2024/06/03 18:34:12 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
//La funcion mide la longitud del string

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	c1;

	c1 = c;
	while (*s != '\0' && *s != c1)
		s++;
	if (*s == c1)
		return ((char *)s);
	return (NULL);
}
//La funcion busca c en la cadena s

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
//Reserva (con malloc(3)) y devuelve una nueva string, 
//formada por la concatenación de ’s1’ y ’s2’.

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
//Reserva (con malloc(3)) y devuelve una substring de la string ’s’. 
//La substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.

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
//La función asigna suficiente memoria para una copia de la cadena s1,
//realiza la copia y devuelve un puntero a ella.
//útil en situaciones donde necesitas trabajar con una copia independiente de la cadena  original.
