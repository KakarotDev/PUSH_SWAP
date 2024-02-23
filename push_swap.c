/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:31:27 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 22:08:18 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	if (argc < 2)
		exit(0);
	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->a->node = NULL;
	ps->a->head = NULL;
	ps->b->node = NULL;
	ps->b->head = NULL;
	creat_stacks(ps, argv, argc);
	create_index(ps);
	defining_parts(ps);
	creating_inverse_pyramid(ps);
	where_is_the_one(ps);
	h_and_t_game(ps);
	free_stacks(ps);
}

// int	main(int argc, char **argv)
// {
// 	t_push_swap	*ps;

// 	if (argc < 2)
// 		exit(0);
// 	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
// 	ps->a = (t_stack *)malloc(sizeof(t_stack));
// 	ps->b = (t_stack *)malloc(sizeof(t_stack));
// 	ps->a->node = NULL;
// 	ps->a->head = NULL;
// 	ps->b->node = NULL;
// 	ps->b->head = NULL;
// 	creat_stacks(ps, argv, argc);
// 	create_index(ps);
// 	defining_parts(ps);
// 	ft_printf("STACK A:\n");
// 	ps->a->node = ps->a->head;
// 	while (ps->a->node)
// 	{
// 		ft_printf("%d\n", ps->a->node->index);
// 		ps->a->node = ps->a->node->prev;
// 	}
// 	creating_inverse_pyramid(ps);
// 	where_is_the_one(ps);
// 	ft_printf("STACK B:\n");
// 	ps->b->node = ps->b->head;
// 	while (ps->b->node)
// 	{
// 		ft_printf("%d\n", ps->b->node->index);
// 		ps->b->node = ps->b->node->prev;
// 	}
// 	h_and_t_game(ps);
// 	ft_printf("STACK A:\n");
// 	ps->a->node = ps->a->head;
// 	while (ps->a->node)
// 	{
// 		ft_printf("%d\n", ps->a->node->index);
// 		ps->a->node = ps->a->node->prev;
// 	}
// 		ft_printf("STACK B:\n");
// 	ps->b->node = ps->b->head;
// 	while (ps->b->node)
// 	{
// 		ft_printf("%d\n", ps->b->node->index);
// 		ps->b->node = ps->b->node->prev;
// 	}
// 	free_stacks(ps);
// }