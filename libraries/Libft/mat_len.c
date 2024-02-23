/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:09:58 by parthur-          #+#    #+#             */
/*   Updated: 2023/11/09 19:12:45 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	matrix_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		i++;
	return (i);
}