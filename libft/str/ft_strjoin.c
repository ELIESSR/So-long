/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:45:11 by elteran           #+#    #+#             */
/*   Updated: 2024/04/05 19:00:49 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	result = (char *) malloc (i + j + 1);
	if (!result)
		return (0);
	ft_strlcpy (result, s1, i + j + 1);
	ft_strlcat (result, s2, i + j + 1);
	return (result);
}
