/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_node_dlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:40:47 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:02 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*remove_node_dlist(t_node *node)
{
	t_node	*aux;

	aux = NULL;
	if (node->next == NULL)
	{
		node->prev->next = NULL;
		aux = node->prev;
		free(node);
		return (aux);
	}
	else if (node->prev == NULL)
	{
		node->next->prev = NULL;
		aux = node->next;
		free(node);
		return (aux);
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
	}
	return (aux);
}
