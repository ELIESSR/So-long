/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:19:25 by elteran           #+#    #+#             */
/*   Updated: 2024/03/15 17:48:54 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n[i] == '\0')
		return ((char *) h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len)
		{
			if (n[j + 1] == '\0')
				return ((char *) h + i);
			j++;
		}
		i++;
	}
	return (0);
}
