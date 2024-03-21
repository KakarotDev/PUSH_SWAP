/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:31:27 by parthur-          #+#    #+#             */
/*   Updated: 2024/03/11 20:06:31 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_push_swap *ps)
{
	create_index(ps);
	is_it_already_organized(ps);
	if (ps->size <= 2)
		if_we_have_two_or_less(ps);
	else if (ps->size < 6)
		under_six(ps);
	else
	{
		defining_parts(ps);
		creating_inverse_pyramid(ps);
		where_is_the_one(ps);
		h_and_t_game(ps);
	}
	free_stacks(ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (argc < 2)
		exit(0);
	ps = malloc(sizeof(t_push_swap));
	ps->a = malloc(sizeof(t_stack));
	ps->b = malloc(sizeof(t_stack));
	ps->a->node = NULL;
	ps->a->head = NULL;
	ps->b->node = NULL;
	ps->b->head = NULL;
	creat_stacks(ps, argv, argc);
	push_swap(ps);
}
