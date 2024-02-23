/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:14:46 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/20 19:58:56 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*p_s;

	index = 0;
	p_s = (unsigned char *)s;
	while (index < n)
	{
		if (p_s[index] == (unsigned char)c)
		{
			return ((void *)&p_s[index]);
		}
		index++;
	}
	return (NULL);
}
