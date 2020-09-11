/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:28:54 by jmery             #+#    #+#             */
/*   Updated: 2013/11/28 12:28:55 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*head;
	t_list	*tmp1;
	t_list	*tmp2;

	current = lst;
	head = current;
	if (current != NULL)
	{
		head = f(current);
		current = current->next;
		tmp1 = head;
		while (current != NULL)
		{
			tmp2 = f(current);
			tmp1->next = tmp2;
			current = current->next;
			tmp1 = tmp2;
		}
	}
	return (head);
}
