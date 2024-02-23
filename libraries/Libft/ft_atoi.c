/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:08:53 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/02 20:01:59 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			sing;
	long int	result;

	result = 0;
	sing = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == 45)
	{
		sing = -1;
		nptr++;
	}
	else if (*nptr == 43)
	{
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (result * sing);
}
