/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:27:54 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 18:04:20 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	front(char const *s1, char const *set)
{
	int			set_len;
	int			index;
	char const	*str;

	str = NULL;
	index = 0;
	set_len = ft_strlen(set) - 1;
	while (set_len >= 0)
	{
		if (set[set_len] == s1[(index)])
		{
			set_len = ft_strlen(set) - 1;
			index++;
		}	
		else
			set_len--;
	}
	return (index);
}

static int	back(char const *s1, char const *set)
{
	int			set_len;
	int			index;
	char const	*str;

	str = NULL;
	index = ft_strlen(s1) - 1;
	set_len = ft_strlen(set) - 1;
	while (set_len >= 0)
	{
		if (set[set_len] == s1[(index)])
		{
			set_len = ft_strlen(set) - 1;
			index--;
		}	
		else
			set_len--;
	}
	return (index + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		size;
	char	*str;

	if (!s1)
		return (NULL);
	start = front(s1, set);
	size = back(s1, set);
	str = ft_substr(s1, start, (size - start));
	return (str);
}
