/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:33:38 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/28 18:20:12 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movements(t_push_swap *ps, int judge)
{
	if (judge == 1)
	{
		while (ps->a->head->index < 4)
			rra(ps);
	}
	if (judge == 2)
	{
		while (ps->a->head->index < 4)
			ra(ps);
	}
	if (ps->b->head)
	{
		if (ps->a->head->index > ps->b->head->index)
		{
			pb(ps);
			sb(ps);
		}
		else
			pb(ps);
	}
	else
		pb(ps);
}

int	who_wins(t_push_swap *ps)
{
	int	price_h;
	int	price_t;

	price_h = 0;
	price_t = 0;
	ps->a->node = ps->a->head;
	while (ps->a->node->index < 4)
	{
		price_h++;
		ps->a->node = ps->a->node->prev;
	}
	ps->a->node = ps->a->tail;
	while (ps->a->node->index < 4)
	{
		price_t++;
		ps->a->node = ps->a->node->next;
	}
	if (price_t < price_h)
		return (1);
	else
		return (2);
}

void	under_four(t_push_swap *ps)
{
	if (ps->a->tail->index == 3)
	{
		if (ps->a->head->index != 1)
			sa(ps);
	}
	else
	{
		if (ps->a->tail->next->index == 3)
			rra(ps);
		else
			ra(ps);
		if (ps->a->head->index != 1)
			sa(ps);
	}
}

void	under_six(t_push_swap *ps)
{
	int	i;
	int	champion;

	i = ps->size;
	champion = 0;
	if (ps->size < 4)
		under_four(ps);
	else
	{
		while (i != 3)
		{
			champion = who_wins(ps);
			movements(ps, champion);
			i--;
		}
		under_four(ps);
		pa(ps);
		ra(ps);
		pa(ps);
		ra(ps);
	}
}
