/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 02:15:30 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:24:21 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		length;

	length = 0;
	current = begin_list;
	while (current != (void*)0)
	{
		length++;
		current = current->next;
	}
	return (length);
}
