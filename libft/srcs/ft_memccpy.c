/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:51:47 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:36:40 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*p2;
	int				find;

	i = 0;
	find = 0;
	p2 = (unsigned char*)s2;
	if (s1 != NULL && p2 != NULL)
	{
		while (i < n && find == 0)
		{
			if (p2[i] == (unsigned char)c)
				find = 1;
			*((unsigned char*)s1 + i) = p2[i];
			i++;
		}
		if (find == 1)
			return ((unsigned char*)s1 + i);
		return (NULL);
	}
	return (NULL);
}
