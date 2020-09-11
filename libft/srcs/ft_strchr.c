/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:52:39 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:29:56 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*r;
	char			*p;

	i = 0;
	r = (void*)0;
	p = (char*)s;
	while (p[i] != '\0' && r == (void*)0)
	{
		if (p[i] == (char)c)
			r = p + i;
		i++;
	}
	if (p[i] == '\0' && (char)c == '\0')
		r = p + i;
	return (r);
}
