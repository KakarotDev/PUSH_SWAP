/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_double_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:42:21 by parthur-          #+#    #+#             */
/*   Updated: 2024/02/20 02:46:55 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_double_list(t_node **tail, t_node **head, int content)
{
	t_node	*new;

	new = new_dnode(content);
	*tail = new;
	*head = new;
}
