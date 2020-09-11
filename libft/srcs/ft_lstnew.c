/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:29:32 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:43:01 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(new) * (content_size));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
		}
		else
		{
			new->content = (void*)content;
			new->content_size = content_size;
			new->next = NULL;
		}
	}
	return (new);
}
