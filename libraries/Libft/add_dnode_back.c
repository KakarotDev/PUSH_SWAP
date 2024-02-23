/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dnode_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:43:48 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/01 21:01:42 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_dnode_back(t_node **head, t_node *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		(*head)->next = new;
		new->prev = *head;
		*head = new;
	}
}
