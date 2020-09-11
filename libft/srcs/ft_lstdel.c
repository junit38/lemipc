/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:08:23 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:25:43 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*todel;
	t_list	*nexttodel;

	nexttodel = *alst;
	if (nexttodel != NULL)
	{
		while (nexttodel != NULL)
		{
			todel = nexttodel;
			nexttodel = todel->next;
			del(todel->content, todel->content_size);
			free(todel);
			*alst = NULL;
		}
	}
}
