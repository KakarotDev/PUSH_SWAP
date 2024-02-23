/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:45:03 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/20 20:08:12 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index != -1)
	{
		if (s[index] == (char)c)
		{
			return ((char *)&s[index]);
		}
		index--;
	}
	if (c == '\0')
	{
		return ((char *)&s[ft_strlen(s)]);
	}
	return (NULL);
}
