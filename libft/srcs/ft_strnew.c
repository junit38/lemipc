/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:56:59 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:31:52 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strnew(size_t size)
{
	char	*p;

	if (size == 0)
	{
		p = (char*)malloc(sizeof(p) * 1);
		*p = '\0';
		return (p);
	}
	p = (char*)malloc(sizeof(p) * size);
	if (p)
	{
		ft_memset(p, '\0', sizeof(p));
		return (p);
	}
	return (NULL);
}
