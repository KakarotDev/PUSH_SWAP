/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:09:59 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 21:40:44 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *ps)
{
	if (ps->a->head == NULL)
		return ;
	ps->a->node = ps->a->head->prev;
	if (ps->a->head->prev->prev == NULL)
	{
		ps->a->tail = ps->a->head;
		ps->a->head = ps->a->node;
		ps->a->tail->prev = NULL;
		ps->a->head->next = NULL;
		ps->a->head->prev = ps->a->tail;
		ps->a->tail->next = ps->a->head;
	}
	else
	{
		if (ps->a->node == NULL)
			return ;
		ps->a->head->prev = ps->a->node->prev;
		ps->a->head->next = ps->a->node;
		ps->a->node->prev->next = ps->a->head;
		ps->a->node->prev = ps->a->head;
		ps->a->node->next = NULL;
		ps->a->head = ps->a->node;
	}
	ft_printf("sa\n");
}

void	pa(t_push_swap *ps)
{
	if (ps->b->head == NULL)
		return ;
	else
	{
		if (ps->b->head->prev)
			ps->b->node = ps->b->head->prev;
		if (ps->b->node->next)
			ps->b->node->next = NULL;
		if (ps->a->head == NULL)
		{
			init_double_list(&ps->a->tail, &ps->a->head, ps->b->head->value);
			free(ps->b->head);
		}
		else
		{
			ps->a->node = ps->a->head;
			ps->a->head = ps->b->head;
			ps->a->node->next = ps->a->head;
			ps->a->head->prev = ps->a->node;
		}
		ps->b->head = ps->b->node;
	}
	ft_printf("pa\n");
}

void	ra(t_push_swap *ps)
{
	if (ps->a->head == NULL || ps->a->tail == NULL)
		return ;
	ps->a->tail->prev = ps->a->head;
	ps->a->head->next = ps->a->tail;
	ps->a->node = ps->a->head->prev;
	ps->a->head->prev = NULL;
	ps->a->node->next = NULL;
	ps->a->tail = ps->a->head;
	ps->a->head = ps->a->node;
	ft_printf("ra\n");
}

void	rra(t_push_swap *ps)
{
	ps->a->head->next = ps->a->tail;
	ps->a->tail->prev = ps->a->head;
	ps->a->node = ps->a->tail->next;
	ps->a->tail->next = NULL;
	ps->a->node->prev = NULL;
	ps->a->head = ps->a->tail;
	ps->a->tail = ps->a->node;
	ft_printf("rra\n");
}
