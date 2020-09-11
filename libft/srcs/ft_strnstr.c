/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:43:04 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:31:30 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_strnisequal(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				isequal;

	i = 0;
	isequal = 1;
	while (s1[i] != '\0' && s2[i] != '\0' && isequal == 1 && i < n)
	{
		if (s1[i] != s2[i])
			isequal = 0;
		i++;
	}
	if (s2[i] != '\0')
		isequal = 0;
	return (isequal);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	find;
	char			*p;

	find = 0;
	i = 0;
	p = (char*)s1;
	if (*s1 == '\0' && *s2 == '\0')
		return (p);
	while (p[i] != '\0' && find == 0 && (i + ft_strlen(s2)) <= n)
	{
		if (ft_strnisequal(p + i, s2, n))
			find = 1;
		i++;
	}
	if (find == 0)
		return ((void*)0);
	else if (s2[i] == '\0' || find == 1)
		return (p + i - 1);
	return (p);
}
