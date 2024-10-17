/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:51:49 by elteran           #+#    #+#             */
/*   Updated: 2024/05/06 14:07:45 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*read_line(int fd, char *strs)
{
	char	*aux;//reserva el espacio de memoria de la linea donde se guarda lo leido.
	char	*copy;//sirve de variable auxiliar para la variable estatica (strstat). guarda los datos de la variable estatica antes de actualizarla.
	int		rb;//para llevar el control del file descriptor (fd). Va a tener el valor de los bytes que se hayan leido.

	rb = 1;
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	while (!strs || (!ft_strchr(strs, '\n') && rb > 0))
	{
		// Leer del descriptor de archivo fd al búfer  auxiliar 
		rb = read(fd, aux, BUFFER_SIZE);
		if (rb == -1)
		{
			free(aux);
			free(strs);
			return (NULL);
		}
		aux[rb] = '\0';
		copy = strs;/*referencia a la cadena actual antes de la concatenacion*/
		strs = ft_strjoin_gnl(strs, aux);/*concatena con la linea existente*/
		free(copy);/*se libera la memoria de la cadena anterior*/
	}
	free(aux);
	return (strs);
}
//La funcion se encarga de leer el fichero. 
//Lee la linea y la guarda en la variable estatica.

char	*ft_printer(char **s)
{
	char	*r;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	// Buscar el índice del primer salto de línea o el final de la cadena
	while (*s && (*s)[i] && (*s)[i] != '\n')
		i++;
	// Avanzar después del salto de línea si se encontró uno
	if ((*s) && (*s)[i] == '\n')
		i++;
	r = ft_substr_gnl(*s, 0, i);
	// Actualizar la cadena original para excluir la línea extraída
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
//la función tiene la intención de modificar la cadena original (*s)
//y, por lo tanto, necesita recibir una referencia al puntero original.
//En C, cuando pasas una variable a una función, se pasa por valor,
//lo que significa que la función trabaja con una copia de la variable.
//Sin embargo, cuando pasas un puntero a una función,
//la función puede modificar el contenido al que apunta el puntero. 
//////////////////////////////////////////////////
//la funcion sirve para tomar 
//todos los valores de la cadena 
//hasta el salto de linea o el nulo.
//**s = se usa un doble puntero para 
//poder modificar una cadena sin generar una copia.

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		// Llamar a read_line para leer la línea del descriptor de archivo y actualizar aux
	aux = read_line(fd, aux);
	if (!aux || !aux[0])
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	// Llamar a ft_printer para extraer la primera línea y actualizar aux
	result = ft_printer(&aux);
	 // Devolver la primera línea extraída
	return (result);
}
//Esta funcion toma el fd y crea una variable strstat para reservar el espacio de memoria,
//leer y actualizar la linea, y una variable result, 
//donde va a tomar los valores del archivo hasta el salto de linea o el nulo.
