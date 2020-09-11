/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:10:32 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:32:57 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*p;

	i = 0;
	p = ft_strnew(ft_strlen(s));
	if (p)
	{
		p = ft_memmove(p, s, ft_strlen(s));
		while (p[i] != '\0')
		{
			p[i] = f(p[i]);
			i++;
		}
	}
	return (p);
}
