/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:30:31 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 02:11:00 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_push_swap *ps)
{
	if (ps->b->head == NULL)
		return ;
	ps->b->node = ps->b->head->prev;
	if (ps->b->node == NULL)
		return ;
	ps->b->head->prev = ps->b->node->prev;
	ps->b->head->next = ps->b->node;
	ps->b->node->prev->next = ps->b->head;
	ps->b->node->prev = ps->b->head;
	ps->b->node->next = NULL;
	ps->b->head = ps->b->node;
	ft_printf("sb\n");
}

void	pb(t_push_swap *ps)
{
	if (ps->a->head == NULL)
		return ;
	else
	{
		ps->a->node = ps->a->head->prev;
		ps->a->node->next = NULL;
		if (ps->b->head == NULL)
		{
			init_double_list_b(&ps->b->tail, &ps->b->head, ps->a->head->value,
				ps->a->head->index);
			free(ps->a->head);
		}
		else
		{
			ps->b->node = ps->b->head;
			ps->b->head = ps->a->head;
			ps->b->node->next = ps->b->head;
			ps->b->head->prev = ps->b->node;
		}
		ps->a->head = ps->a->node;
	}
	ft_printf("pb\n");
}

void	rb(t_push_swap *ps)
{
	ps->b->tail->prev = ps->b->head;
	ps->b->head->next = ps->b->tail;
	ps->b->node = ps->b->head->prev;
	ps->b->head->prev = NULL;
	ps->b->node->next = NULL;
	ps->b->tail = ps->b->head;
	ps->b->head = ps->b->node;
	ft_printf("rb\n");
}

void	rrb(t_push_swap *ps)
{
	ps->b->head->next = ps->b->tail;
	ps->b->tail->prev = ps->b->head;
	ps->b->node = ps->b->tail->next;
	ps->b->tail->next = NULL;
	ps->b->node->prev = NULL;
	ps->b->head = ps->b->tail;
	ps->b->tail = ps->b->node;
	ft_printf("rrb\n");
}
