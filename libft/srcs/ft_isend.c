/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 10:13:26 by jmery             #+#    #+#             */
/*   Updated: 2013/12/05 10:13:27 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_isend(char const *s1, size_t size)
{
	unsigned int	i;
	int				end;

	i = 0;
	end = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] != '\0' && end == 0 && i < size)
	{
		if (s1[i] == '\n')
			end = 1;
		i++;
	}
	return (end);
}
