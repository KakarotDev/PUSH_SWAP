/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:52:28 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/23 14:57:12 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		index;
	const char	*p_src;
	char		*p_dest;

	index = 0;
	p_dest = (char *)dest;
	p_src = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest <= src)
	{
		while (index < n)
		{
			p_dest[index] = p_src[index];
			index++;
		}
		return (dest);
	}
		index = n;
	while (index > 0)
	{
		p_dest[index -1] = p_src[index -1];
		index--;
	}
	return (dest);
}
