/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:49 by parthur-          #+#    #+#             */
/*   Updated: 2023/10/03 20:26:42 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_u(long int number)
{
	long int	negative;
	long int	result;

	if (number < 0)
	{
		negative = 4294967296 + (number);
		result = ft_itoa_printf(negative);
	}
	else
	{
		result = ft_itoa_printf(number);
	}
	return (result);
}

int	dispatcher(char ch, va_list list)
{
	int		i;
	char	*str;

	i = 0;
	if (ch == 'c')
		i = ft_putchar(va_arg(list, int));
	if (ch == 's')
	{
		str = va_arg(list, char *);
		if (str == NULL)
			return (write(1, "(null)", 6));
		i = ft_putstr(str);
	}
	if (ch == 'd' || ch == 'i')
		i = ft_itoa_printf(va_arg(list, int));
	if (ch == 'p')
		i = ft_putaddress(va_arg(list, unsigned long));
	if (ch == 'x' || ch == 'X')
		i = ft_puthexa(va_arg(list, unsigned int), ch);
	if (ch == 'u')
		i = print_u(va_arg(list, int));
	if (ch == '%')
		i = write(1, &ch, 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	argument_pointer;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(argument_pointer, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			while (str[i + 1] == ' ')
				i++;
			len += dispatcher(str[i + 1], argument_pointer);
			i += 2;
		}
		else
			len += (write(1, &str[i++], 1) || 1);
	}
	va_end(argument_pointer);
	return (len);
}
