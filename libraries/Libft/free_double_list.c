/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:43:17 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/03 22:42:41 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_list(t_node **head, t_node **tail)
{
	t_node	*curr;

	curr = *head;
	if (curr == NULL)
		return ;
	while (curr->prev)
	{
		curr = curr->prev;
		free(curr->next);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}
