/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:50:49 by parthur-          #+#    #+#             */
/*   Updated: 2023/11/29 22:03:43 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpchr(const char *s, int c, int index)
{
	if (s[index] == (char)c)
	{
		return ((char *)&s[index]);
	}
	return (NULL);
}
