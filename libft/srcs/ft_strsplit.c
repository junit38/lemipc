/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:43:57 by jmery             #+#    #+#             */
/*   Updated: 2013/12/20 21:29:20 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_getword(char **p, char c)
{
	unsigned int	len;
	char			*s;
	char			*tmp;

	len = 0;
	s = *p;
	while (s[len] != (char)c && s[len] != '\0')
		len++;
	tmp = (char*)malloc(sizeof(tmp) * (len + 1));
	if (tmp)
	{
		tmp = ft_strncpy(tmp, s, len);
		tmp[len] = '\0';
	}
	*p = s + len;
	return (tmp);
}

size_t	ft_count_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb;
	char			*p;

	i = 0;
	nb = 0;
	p = (char*)s;
	while (p[i] != '\0')
	{
		if (p[i] != c)
		{
			nb++;
			while (p[i] != c && p[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (p[i] == '\0' && c == '\0')
		nb = 1;
	return (nb);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*p;
	char	*tmp;
	char	**v;
	int		j;

	j = 0;
	p = (char*)s;
	v = (char**)malloc(sizeof(v) * (ft_count_word(p, c) + 1));
	if (p != NULL && v != NULL)
	{
		while (*p != '\0')
		{
			if (*p != (char)c)
			{
				tmp = p;
				v[j] = ft_getword(&tmp, c);
				p = tmp;
				j++;
			}
			else
				p++;
		}
	}
	v[j] = NULL;
	return (v);
}
