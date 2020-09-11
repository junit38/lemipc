/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 15:32:48 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:15:49 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_getnstr(char const *s1, size_t n)
{
	unsigned int	i;
	char			*get;
	char			*put;

	i = 0;
	get = (char*)malloc(sizeof(get) * n + 1);
	if (!get)
		return ((void*)0);
	put = (char*)s1;
	while (n > 0)
	{
		get[i] = put[i];
		i++;
		n--;
	}
	get[i] = '\0';
	return (get);
}
