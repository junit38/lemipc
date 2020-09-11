/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 01:19:25 by jmery             #+#    #+#             */
/*   Updated: 2013/09/27 13:59:33 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list			*elem;
	t_list			*current;

	elem = ft_create_elem(data);
	if (*begin_list == (void*)0)
		*begin_list = elem;
	else
	{
		current = *begin_list;
		while (current->next != (void*)0)
		{
			current = current->next;
		}
		current->next = elem;
	}
}
