/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:44:36 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 16:20:14 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int nbr)
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

static char	*isnegative(int n)
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
		return (NULL);
	str[0] = '-';
	while (l > 9)
	{
		str[(len - index)] = (l % 10) + 48;
		l = l / 10;
		index++;
	}
	str[(len - index)] = l + 48;
	str[index + 2] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long int	l;
	char		*str;
	int			index;
	int			len;

	l = (long int)n;
	len = intlen(l);
	index = 0;
	if (l < 0)
		return (isnegative(n));
	str = (char *)malloc(sizeof(char) * (intlen(l) + 1));
	if (str == NULL)
		return (NULL);
	while (l > 9)
	{
		str[(len - index) - 1] = (l % 10) + 48;
		l = l / 10;
		index++;
	}
	str[(len - index) - 1] = l + 48;
	str[index + 1] = '\0';
	return (str);
}
