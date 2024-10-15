/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:18:49 by elteran           #+#    #+#             */
/*   Updated: 2024/05/06 13:54:59 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)dst == NULL && (unsigned char *)src == NULL)
		return (0);
	while (i < n)
	{
		*((char *) dst + i) = *((const char *) src + i);
		i++;
	}
	return (dst);
}
