/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:10:11 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/22 22:29:57 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	const char	*p_src;
	char		*p_dest;

	index = 0;
	p_src = src;
	p_dest = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		p_dest[index] = p_src[index];
		index++;
	}
	return (dest);
}
