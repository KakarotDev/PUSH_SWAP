/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_before_dlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:56 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:30 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert_before_dlist(t_node *curr, t_node *before)
{
	before->next = curr;
	before->prev = curr->prev;
	if (curr->prev != NULL)
		curr->prev->next = before;
	curr->prev = before;
}
