/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:43:04 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:26:31 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strstr(const char *s1, const char *s2)
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
		return ((void*)0);
	else if (s2[i] == '\0' || find == 1)
		return (p + i - 1);
	return (p);
}
