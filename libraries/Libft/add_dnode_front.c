/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dnode_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:43:29 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/02 18:17:49 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_dnode_front(t_node **tail, t_node *new)
{
	if (*tail == NULL)
		*tail = new;
	else
	{
		(*tail)->prev = new;
		new->next = *tail;
		*tail = new;
	}
}
