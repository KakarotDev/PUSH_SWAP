/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_after_dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:43:07 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:39 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert_after_dlist(t_node *curr, t_node *after)
{
	after->next = curr->next;
	after->prev = curr;
	if (curr->next != NULL)
		curr->next->prev = after;
	curr->next = after;
}
