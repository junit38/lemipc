/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:50:41 by jmery             #+#    #+#             */
/*   Updated: 2013/11/22 14:50:42 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = (void*)malloc(sizeof(p) * size);
	if (p)
	{
		ft_memset(p, 0, sizeof(p));
		return (p);
	}
	return (NULL);
}
