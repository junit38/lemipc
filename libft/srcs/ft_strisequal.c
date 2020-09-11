/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisequal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:21:36 by jmery             #+#    #+#             */
/*   Updated: 2013/11/19 15:22:53 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_strisequal(const char *s1, const char *s2)
{
	int		i;
	int		isequal;

	i = 0;
	isequal = 1;
	while (s1[i] != '\0' && s2[i] != '\0' && isequal == 1)
	{
		if (s1[i] != s2[i])
			isequal = 0;
		i++;
	}
	if (s2[i] != '\0')
		isequal = 0;
	return (isequal);
}
