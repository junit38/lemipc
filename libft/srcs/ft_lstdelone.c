/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:59:54 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:42:10 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*todel;

	todel = *alst;
	if (todel != NULL)
	{
		del(todel->content, todel->content_size);
		free(todel);
		*alst = NULL;
	}
}
