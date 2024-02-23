/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:23:29 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 19:18:36 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		index;
	char		*duplicate;
	size_t		len;

	index = 0;
	len = ft_strlen(s);
	duplicate = (char *)malloc(len + 1 * sizeof(char));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	while (s[index] != '\0')
	{
		duplicate[index] = s[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
