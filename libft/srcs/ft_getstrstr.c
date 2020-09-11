/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 18:40:48 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:16:38 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	ft_getstrstr(const char *s1, const char *s2)
{
	int			i;
	int			find;
	char		*p;

	find = 0;
	i = 0;
	p = (char*)s1;
	while (p[i] != '\0' && find == 0)
	{
		if (ft_strisequal(p + i, s2))
			find = 1;
		i++;
	}
	if (find == 0)
		return (0);
	else if (s2[i] == '\0' || find == 1)
		return (i);
	return (i);
}
