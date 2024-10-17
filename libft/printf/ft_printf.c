/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elteran <elteran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:55 by elteran           #+#    #+#             */
/*   Updated: 2024/05/06 14:07:47 by elteran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	format_specifier(va_list args, char str)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += (ft_putchar(va_arg(args, int)));
	else if (str == 's')
		i += (ft_putstr(va_arg(args, char *)));
	else if (str == 'p')
		i += (ft_putstr("0x") + hexa_re (va_arg(args, unsigned long),
					"0123456789abcdef"));
	else if (str == 'd')
		i += (ft_putnbr(va_arg(args, int)));
	else if (str == 'i')
		i += (ft_putnbr(va_arg(args, int)));
	else if (str == 'u')
		i += (ft_putunbr(va_arg(args, unsigned int)));
	else if (str == 'x')
		i += (hexa_re(va_arg (args, unsigned int), "0123456789abcdef"));
	else if (str == 'X')
		i += (hexa_re(va_arg (args, unsigned int), "0123456789ABCDEF"));
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		print;

	va_start(args, str);
	i = 0;
	print = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				print += write(1, "%%", 1);
			else
				print += format_specifier(args, str[i]);
		}
		else
			print += write(1, str + i, 1);
		i++;
	}
	va_end(args);
	return (print);
}
