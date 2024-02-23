/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:08:04 by parthur-          #+#    #+#             */
/*   Updated: 2023/10/20 23:16:38 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_variable(char *variable)
{
	free(variable);
	return (NULL);
}

char	*adjust_pointer(char *str)
{
	int		i;
	int		j;
	char	*start_pointer;
	char	*new_str;

	i = 0;
	j = 0;
	start_pointer = str;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	if (j == 0 || j == 1)
		return (free_variable(str));
	new_str = ft_calloc((j), sizeof(char));
	j--;
	while (j >= 0)
		new_str[j--] = str[i--];
	free(start_pointer);
	return (new_str);
}

char	*make_line(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (result == NULL)
		return (NULL);
	result[i + 1] = '\0';
	while (j <= i)
	{
		result[j] = str[j];
		j++;
	}
	return (result);
}

char	*read_line(int fd, char *line, ssize_t bytesread)
{
	static char		*templine[FD_MAX];
	char			*buffer;

	if (templine[fd] == NULL)
		templine[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (bytesread != 0)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1 || (bytesread == 0 && templine[fd][0] == '\0'))
		{
			templine[fd] = free_variable(templine[fd]);
			return (free_variable(buffer));
		}
		templine[fd] = ft_strjoin_gnl(templine[fd], buffer);
		if (ft_strchr(templine[fd], '\n'))
			break ;
	}
	line = make_line(templine[fd]);
	templine[fd] = adjust_pointer(templine[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	ssize_t	bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	line = NULL;
	bytesread = 1;
	line = read_line(fd, line, bytesread);
	return (line);
}
