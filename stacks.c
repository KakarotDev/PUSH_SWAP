/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:37:38 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/20 02:44:37 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_push_swap *ps)
{
	int			index;
	long int	control;
	int			aux;
	t_node		*indicator;

	index = 1;
	aux = -2147483648;
	ps->a->node = ps->a->head;
	while (index <= ps->size)
	{
		control = 2147483648;
		while (ps->a->node)
		{
			if (control > ps->a->node->value && ps->a->node->value > aux)
			{
				indicator = ps->a->node;
				control = ps->a->node->value;
			}
			ps->a->node = ps->a->node->prev;
		}
		indicator->index = index;
		aux = control;
		ps->a->node = ps->a->head;
		index++;
	}
}

int	checking_duplicity(long int arg, t_stack *stack)
{
	t_node	*aux;

	if (arg > 2147483647 || arg < -2147483648)
		return (0);
	aux = stack->node;
	if (stack->node == NULL)
		return (1);
	else
	{
		stack->node = stack->tail;
		while (stack->node)
		{
			if (stack->node->value == arg)
			{
				stack->node = aux;
				return (0);
			}
			stack->node = stack->node->next;
		}
		stack->node = aux;
		return (1);
	}
}

char	*handling_arguments(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arg);
	if (((arg[i] == '+' || arg[i] == '-') && ft_isdigit(arg[i + 1]) != 0)
		|| ft_isdigit(arg[i]) != 0)
	{
		i++;
		while (ft_isdigit(arg[i]) != 0)
			i++;
	}
	if (i == len)
		return (arg);
	else
		return (NULL);
}

void	creat_stacks(t_push_swap *ps, char **argv, int argc)
{
	int	i;

	ps->size = 0;
	i = 0;
	while (++i < argc)
	{
		if (handling_arguments(argv[i]))
		{
			if (checking_duplicity(ft_atoi(argv[i]), ps->a) == 1)
			{
				ps->size++;
				if (ps->a->node == NULL)
				{
					init_double_list(&ps->a->tail, &ps->a->head,
						ft_atoi(argv[i]));
					ps->a->node = ps->a->tail;
				}
				else
				{
					add_dnode_front(&ps->a->node, new_dnode(ft_atoi(argv[i])));
					ps->a->tail = ps->a->node;
				}
			}
		}
	}
}
