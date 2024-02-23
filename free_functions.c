/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:27:01 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/22 23:02:07 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_push_swap *ps)
{
	if (ps->a->head != NULL)
		free_double_list(&ps->a->head, &ps->a->tail);
	free(ps->a);
	free(ps->b);
	free(ps);
}
