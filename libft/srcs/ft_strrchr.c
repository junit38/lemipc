/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:57:22 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:30:29 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*p;
	char			*r;

	i = 0;
	p = (char*)s;
	r = (void*)0;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			r = p + i;
		i++;
	}
	if (p[i] == '\0' && (char)c == '\0')
		r = p + i;
	return (r);
}
