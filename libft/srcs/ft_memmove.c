/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:52:33 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:45:14 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	i = 0;
	p1 = s1;
	p2 = (char*)malloc(sizeof(p2) * (ft_strlen(s2) + 1));
	ft_memset(p2, '\0', n);
	ft_memcpy(p2, s2, n);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	free(p2);
	return (s1);
}
