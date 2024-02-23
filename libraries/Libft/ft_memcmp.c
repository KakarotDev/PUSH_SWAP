/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:50:37 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/20 19:58:51 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	index = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (index < (n - 1))
	{
		if (p_s1[index] != p_s2[index])
			return (p_s1[index] - p_s2[index]);
		index++;
	}
	if (p_s1[index] == p_s2[index])
		return (0);
	else
		return (p_s1[index] - p_s2[index]);
}
