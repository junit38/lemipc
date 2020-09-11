/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 02:15:30 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:22:34 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list		*current;

	current = begin_list;
	while (current->next != (void*)0)
	{
		current = current->next;
	}
	return (current);
}
