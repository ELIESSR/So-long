/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:51:01 by elteran           #+#    #+#             */
/*   Updated: 2024/03/15 17:41:59 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	counter(int n)
{
	int	count;

	if (!n)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				c;
	char			*str;

	str = malloc(sizeof(char) * counter(n) + 1);
	if (!str)
		return (0);
	num = n;
	c = counter(n) - 1;
	str[c + 1] = '\0';
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = num * (-1);
	}
	while (num > 0)
	{
		str[c] = '0' + num % 10;
		num = num / 10;
		c--;
	}
	return (str);
}
