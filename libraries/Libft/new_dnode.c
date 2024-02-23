/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:39:31 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/20 03:04:07 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*new_dnode(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->next = NULL;
	new->prev = NULL;
	new->value = content;
	new->index = 0;
	return (new);
}
