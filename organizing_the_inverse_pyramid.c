/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizing_the_inverse_pyramid.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:43:47 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/28 18:19:19 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_price	what_is_the_price(t_push_swap *ps)
{
	t_price	p;
	t_node	*t;
	t_node	*h;

	p.price_tail = 1;
	p.price_head = 1;
	h = ps->a->head;
	while ((h->index > ps->middle + ps->rltv_size_up
			|| h->index < ps->middle - ps->rltv_size_down) && h != NULL)
	{
		p.price_head++;
		h = h->prev;
	}
	t = ps->a->tail;
	while ((t->index > ps->middle + ps->rltv_size_up
			|| t->index < ps->middle - ps->rltv_size_down) && t != NULL)
	{
		p.price_tail++;
		t = t->next;
	}
	p.cheaper_h = h;
	p.cheaper_t = t;
	return (p);
}

void	defining_parts(t_push_swap *ps)
{
	ps->rltv_size_up = ps->size;
	ps->middle = ps->size / 2;
	if (ps->rltv_size_up <= 10)
		ps->rltv_size_up = 2;
	else if (ps->rltv_size_up <= 100)
		ps->rltv_size_up = ps->rltv_size_up / 8;
	else if (ps->rltv_size_up <= 500)
		ps->rltv_size_up = ps->rltv_size_up / 14;
	else
		ps->rltv_size_up = ps->rltv_size_up / 21;
	ps->rltv_size_down = ps->rltv_size_up;
	ps->piece = ps->rltv_size_up;
}

void	h_won(t_push_swap *ps, t_price p)
{
	int	i;

	i = p.cheaper_h->index;
	while (ps->a->head->value != p.cheaper_h->value)
		ra(ps);
	if (i >= ps->middle)
		ps->control_up++;
	else
		ps->control_down++;
	if (ps->control_up == ps->rltv_size_up)
		ps->rltv_size_up += ps->piece;
	if (ps->control_down == ps->rltv_size_down)
		ps->rltv_size_down += ps->piece;
	pb(ps);
	if (i < ps->middle)
		rb(ps);
}

void	t_won(t_push_swap *ps, t_price p)
{
	int	i;

	i = p.cheaper_t->index;
	while (ps->a->head->value != p.cheaper_t->value)
		rra(ps);
	if (p.cheaper_t->index >= ps->middle)
		ps->control_up++;
	else
		ps->control_down++;
	if (ps->control_up == ps->rltv_size_up)
		ps->rltv_size_up += ps->piece;
	if (ps->control_down == ps->rltv_size_down)
		ps->rltv_size_down += ps->piece;
	pb(ps);
	if (i < ps->middle)
		rb(ps);
}

void	creating_inverse_pyramid(t_push_swap *ps)
{
	t_price	p;

	ps->control_up = 0;
	ps->control_down = 0;
	while (ps->a->head->prev)
	{
		p = what_is_the_price(ps);
		if (p.price_head <= p.price_tail)
			h_won(ps, p);
		else
			t_won(ps, p);
	}
}
