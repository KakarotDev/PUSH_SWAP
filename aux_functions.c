/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:50:52 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 22:03:19 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_double_list_b(t_node **tail, t_node **head, int content, int index)
{
	t_node	*new;

	new = new_dnode(content);
	*tail = new;
	*head = new;
	(*tail)->index = index;
	(*head)->index = index;
}

void	where_is_the_one(t_push_swap *ps)
{
	if (ps->a->head->index != 1)
	{
		while (ps->b->head->index != 1)
			rrb(ps);
		pa(ps);
		sa(ps);
		pb(ps);
		if (ps->b->head->index < ps->middle)
			rb(ps);
	}
}
