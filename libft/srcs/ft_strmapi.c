/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:19:40 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:33:09 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			p[i] = f(i, p[i]);
			i++;
		}
	}
	return (p);
}
