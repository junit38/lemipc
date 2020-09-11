/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:09:49 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:34:10 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*p;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_strnew(len);
	if (p)
	{
		ft_memset(p, '\0', len);
		p = ft_memmove(p, s1, ft_strlen(s1));
		p = ft_strcat(p, s2);
	}
	return (p);
}
