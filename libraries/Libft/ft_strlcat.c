/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:51:41 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/23 15:26:11 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	size_of_copy;

	if ((!dst || !src) && size == 0)
		return (0);
	i = 0;
	k = ft_strlen(src);
	j = ft_strlen(dst);
	size_of_copy = size - j - 1;
	if (size <= ft_strlen(dst))
		return (k + size);
	while (i < size_of_copy && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + k);
}
