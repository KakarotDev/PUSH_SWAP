/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:07:50 by parthur-          #+#    #+#             */
/*   Updated: 2023/11/09 19:12:16 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mat_len(char const *s, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (s[index] == c && s[index] != '\0')
		index++;
	if (index == (int)ft_strlen(s))
		return (0);
	while (s[index] != '\0')
	{
		if (s[index] == c && s[index + 1] != c
			&& index != (int)ft_strlen(s) - 1)
			count++;
		index++;
	}
	if (ft_strlen(s) > 0)
		count++;
	return (count);
}

static void	free_mat(char **mat, int mat_size)
{
	int	index;

	index = 0;
	if (mat == NULL)
		return ;
	while (index < mat_size)
	{
		free(mat[index]);
		index++;
	}
	free(mat);
}

static char	*ft_strichr(const char *s, int c, int index)
{
	if (s[index] == (char)c)
	{
		return ((char *)&s[index]);
	}
	return (NULL);
}

static char	**mat_creator(char const *s, char c, int mat_size)
{
	int		i;
	int		start;
	char	**mat;
	int		mat_i;

	start = 0;
	i = 0;
	mat_i = 0;
	mat = (char **)malloc(sizeof(char *) * (mat_size + 1));
	if (mat == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s) && mat_size != 0 && mat_i < mat_size)
	{	
		while (ft_strichr(s, c, i) != NULL && i < (int)ft_strlen(s))
		{
			i++;
			start++;
		}
		while (ft_strichr(s, c, i) == NULL && i < (int)ft_strlen(s))
			i++;
		mat[mat_i] = ft_substr(s, start, i - start);
		mat_i++;
		start = i;
	}
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	int		size;

	if (s == NULL)
		return (NULL);
	size = mat_len(s, c);
	matriz = mat_creator(s, c, size);
	if (matriz == NULL)
	{
		free_mat(matriz, size);
		return (NULL);
	}
	matriz[size] = NULL;
	return (matriz);
}
