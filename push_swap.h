/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:31:30 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 03:21:43 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libraries/Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define MAXIMUM_SIZE 2147483647
# define MINI_SIZE -2147483648

typedef struct s_stack
{
	t_node			*node;
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

typedef struct s_price
{
	int		price_tail;
	int		price_head;
	t_node	*cheaper_t;
	t_node	*cheaper_h;
}	t_price;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		rltv_size_up;
	int		rltv_size_down;
	int		piece;
	int		control_up;
	int		control_down;
	int		middle;
}	t_push_swap;

void	init_double_list_b(t_node **tail, t_node **head,
			int content, int index);
char	*handling_arguments(char *arg);
void	creat_stacks(t_push_swap *ps, char **argv, int argc);
void	create_index(t_push_swap *ps);
void	defining_parts(t_push_swap *ps);
t_price	what_is_the_price(t_push_swap *ps);
void	creating_inverse_pyramid(t_push_swap *ps);
void	where_is_the_one(t_push_swap *ps);
void	h_and_t_game(t_push_swap *ps);
void	free_stacks(t_push_swap *ps);
void	sa(t_push_swap *ps);
void	sb(t_push_swap *ps);
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);
void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	ss(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rrr(t_push_swap *ps);
#endif