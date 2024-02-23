/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizing_the_pyramid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 00:55:37 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 04:37:27 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_price	looking_for_the_winner(t_push_swap *ps, int i)
{
	t_price	p;
	t_node	*t;
	t_node	*h;

	p.price_head = 0;
	p.price_tail = 0;
	t = ps->b->tail;
	h = ps->b->head;
	while (t->index != i)
	{
		p.price_tail++;
		t = t->next;
	}
	while (h->index != i)
	{
		p.price_head++;
		h = h->prev;
	}
	p.cheaper_h = h;
	p.cheaper_t = t;
	return (p);
}

void	final_h_won(t_push_swap *ps, int i)
{
	while (ps->b->head->index != i)
		rb(ps);
	pa(ps);
}

void	final_t_won(t_push_swap *ps, int i)
{
	while (ps->b->head->index != i)
		rrb(ps);
	pa(ps);
}

void	h_and_t_game(t_push_swap *ps)
{
	int		i;
	t_price	p;

	i = ps->size -1;
	while (ps->b->head->prev)
	{
		p = looking_for_the_winner(ps, i);
		if (p.price_head < p.price_tail)
			final_h_won(ps, i);
		else
			final_t_won(ps, i);
		i--;
	}
	pa(ps);
	rra(ps);
	sa(ps);
	ra(ps);
}
