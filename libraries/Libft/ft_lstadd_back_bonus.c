/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:41:25 by parthur-          #+#    #+#             */
/*   Updated: 2023/05/30 14:56:34 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new || !lst)
		return ;
	aux = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		aux = ft_lstlast(aux);
		aux->next = new;
	}
}
