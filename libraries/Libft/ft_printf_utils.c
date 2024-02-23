/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:03:40 by parthur-          #+#    #+#             */
/*   Updated: 2023/10/03 20:26:50 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
	return (index);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	intlen(long int nbr)
{
	long int	l;
	int			i;

	l = (long int)nbr;
	i = 1;
	if (l < 0)
	{
		l = l * -1;
	}
	while (l > 9)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

static int	isnegative(int n)
{
	long int	l;
	char		*str;
	int			index;
	int			len;

	l = (long int)n;
	l = l * -1;
	len = intlen(l);
	index = 0;
	str = (char *)malloc(sizeof(char) * (intlen(l) + 2));
	if (str == NULL)
		return (0);
	str[0] = '-';
	while (l > 9)
	{
		str[(len - index)] = (l % 10) + 48;
		l = l / 10;
		index++;
	}
	str[(len - index)] = l + 48;
	str[index + 2] = '\0';
	ft_putstr(str);
	free(str);
	return (len + 1);
}

int	ft_itoa_printf(long int n)
{
	char				*str;
	long int			index;
	long int			len;

	len = intlen(n);
	index = 0;
	if (n < 0)
		return (isnegative(n));
	str = (char *)malloc(sizeof(char) * (intlen(n) + 1));
	if (str == NULL)
		return (0);
	while (n > 9)
	{
		str[(len - index) - 1] = (n % 10) + 48;
		n = n / 10;
		index++;
	}
	str[(len - index) - 1] = n + 48;
	str[index + 1] = '\0';
	ft_putstr(str);
	free(str);
	return (len);
}
