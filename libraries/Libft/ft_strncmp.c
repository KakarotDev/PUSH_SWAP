/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:43:39 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 16:23:26 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;

	index = 0;
	if (n <= 0)
		return (0);
	while (s1[index] != '\0' && s2[index] != '\0' && index < (n - 1))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	if (s1[index] == s2[index])
		return (0);
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
