/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:50:24 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 19:16:08 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char			*space;
	size_t					t_size;

	t_size = nmemb * size;
	if (size != 0)
	{
		if ((t_size / size) != nmemb)
			return (NULL);
	}
	space = malloc(nmemb * size);
	if (space == NULL)
		return (NULL);
	ft_bzero(space, size * nmemb);
	return ((void *)space);
}
