/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:09:44 by jmery             #+#    #+#             */
/*   Updated: 2013/11/22 16:09:44 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	p = ft_strnew(len + 1);
	if (p)
	{
		ft_memset(p, '\0', len);
		p = ft_memmove(p, s + start, len);
	}
	return (p);
}
