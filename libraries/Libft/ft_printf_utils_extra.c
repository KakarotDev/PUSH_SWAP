/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:22:39 by parthur-          #+#    #+#             */
/*   Updated: 2023/10/03 20:34:15 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

char	*inverts(char *str)
{
	int		len;
	char	temp;
	int		i;

	i = 0;
	temp = '\0';
	len = ft_strlen_printf(str) - 1;
	while (i < (ft_strlen_printf(str) / 2))
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		len--;
		i++;
	}
	return (str);
}

int	ft_strlen_printf(const char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	ft_putaddress(unsigned long p)
{
	char			str[18];
	char			*hexa_numbers;
	int				i;
	int				len;
	char			*str2;

	i = 0;
	len = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	hexa_numbers = "0123456789abcdef";
	while (p > 0)
	{
		str[i] = hexa_numbers[p % 16];
		p /= 16;
		i++;
	}
	str[i] = '\0';
	str2 = str;
	str2 = inverts(str2);
	len += write(1, "0x", 2);
	ft_putstr(str);
	len += ft_strlen_printf(str);
	return (len);
}

int	ft_puthexa(unsigned long p, char ch)
{
	char			str[22];
	char			*hexa_numbers;
	int				i;
	unsigned long	len;
	char			*str2;

	i = 0;
	len = 0;
	hexa_numbers = "0123456789abcdef";
	if (p == 0)
		return (write(1, "0", 1));
	while (p != 0)
	{
		str[i] = hexa_numbers[p % 16];
		p /= 16;
		i++;
	}
	str[i] = '\0';
	str2 = str;
	str2 = inverts(str2);
	if (ch == 'X')
		str2 = ft_toupper_printf(str2);
	ft_putstr(str);
	len = ft_strlen_printf(str);
	return (len);
}
