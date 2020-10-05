/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:09:19 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:34:44 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;
	int				eq;

	i = 0;
	eq = 1;
	while (s1[i] != '\0' && s2[i] != '\0' && eq == 1)
	{
		if (s1[i] != s2[i])
			eq = 0;
		i++;
	}
	if (s1[i] != s2[i])
		eq = 0;
	return (eq);
}
