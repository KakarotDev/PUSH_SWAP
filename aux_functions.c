/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:50:52 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/28 18:21:15 by parthur-         ###   ########.fr       */
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

void	if_we_have_two_or_less(t_push_swap *ps)
{
	if (ps->size < 2)
	{
		free_stacks(ps);
		exit(0);
	}
	else
	{
		if (ps->a->head->value > ps->a->tail->value)
			sa(ps);
		else
		{
			free_stacks(ps);
			exit(0);
		}
	}
}

void	is_it_already_organized(t_push_swap *ps)
{
	int		i;

	i = 1;
	ps->a->node = ps->a->head;
	while (i == ps->a->node->index && ps->a->node->prev)
	{
		i++;
		ps->a->node = ps->a->node->prev;
	}
	if (i == ps->size)
	{
		free_stacks(ps);
		exit(0);
	}
}

void	error(t_push_swap *ps)
{
	ft_printf("Erro\n");
	free_stacks(ps);
	exit(1);
}
