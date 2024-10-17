/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:02 by elteran           #+#    #+#             */
/*   Updated: 2024/05/06 14:07:46 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s && s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			r += write(1, "-2", 2);
			n = 147483648;
		}
		else
		{
			r += ft_putchar('-');
			n = -n;
		}
	}
	if (n > 9)
		r += ft_putunbr(n / 10);
	r += ft_putchar(n % 10 + 48);
	return (r);
}

int	ft_putunbr(unsigned int n)
{
	int	u;

	u = 0;
	if (n > 9)
		u += ft_putunbr(n / 10);
	u += ft_putchar(n % 10 + 48);
	return (u);
}

int	hexa_re(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += hexa_re((n / 16), hex);
	i += write(1, hex + (n % 16), 1);
	return (i);
}
