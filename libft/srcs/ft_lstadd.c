/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:26:04 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:24:52 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	if (*alst == NULL)
		*alst = new;
	if (new != NULL)
	{
		new->next = current;
		*alst = new;
	}
}
