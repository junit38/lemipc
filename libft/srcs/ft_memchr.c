/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:53:24 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:35:36 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*res;
	unsigned char	*p;

	i = 0;
	p = (unsigned char*)s;
	res = NULL;
	while (i < n && res == NULL)
	{
		if (p[i] == (unsigned char)c)
			res = p + i;
		i++;
	}
	return (res);
}
