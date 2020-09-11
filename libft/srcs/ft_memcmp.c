/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:54:08 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:36:00 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned int		dif;
	unsigned char		*p1;
	unsigned char		*p2;

	i = 0;
	dif = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (i < n && dif == 0)
	{
		if (p1[i] != p2[i])
			dif = (p1[i] - p2[i]);
		i++;
	}
	return (dif);
}
