/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:26:04 by jmery             #+#    #+#             */
/*   Updated: 2013/11/21 16:26:06 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lens1;
	unsigned int	lens2;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = lens1;
	while (s2[j] != '\0' && (j + lens1) < (n - 1))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	if (n < lens1)
		return (lens2 + n);
	return (lens1 + lens2);
}
