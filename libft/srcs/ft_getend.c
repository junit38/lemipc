/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:19:51 by jmery             #+#    #+#             */
/*   Updated: 2013/12/05 10:19:52 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_getend(char const *s1, size_t size)
{
	unsigned int	i;
	int				find;

	i = 0;
	find = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0' && find == 0 && i < size)
	{
		if (s1[i] == '\n')
			find = 1;
		i++;
	}
	if (find == 1)
		return (i);
	else
		return (0);
}
