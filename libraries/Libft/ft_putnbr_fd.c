/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:00:46 by parthur-          #+#    #+#             */
/*   Updated: 2023/06/01 16:21:43 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		l *= -1;
		write(fd, "-", 1);
	}
	if (l > 9)
	{
		ft_putnbr_fd((l / 10), fd);
		ft_putnbr_fd((l % 10), fd);
	}
	else
	{
		ft_putchar_fd((l + 48), fd);
	}
}
