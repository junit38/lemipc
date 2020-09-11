/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:52:04 by jmery             #+#    #+#             */
/*   Updated: 2013/11/26 10:52:05 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_countspace(char *p)
{
	unsigned int	i;
	unsigned int	clear;

	clear = 0;
	i = 0;
	if (*p == '\0')
		return (0);
	while (p[i] == ' ' || p[i] == '\n' || p[i] == '\t')
		i++;
	clear = i;
	i = ft_strlen(p) - 1;
	while ((p[i] == ' ' || p[i] == '\n' || p[i] == '\t') && i > clear)
		i--;
	i = ft_strlen(p) - (i + 1);
	return (clear + i);
}

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	len;
	char			*p;
	char			*tmp;

	i = 0;
	tmp = (char*)s;
	len = ft_countspace(tmp);
	p = (char*)malloc(sizeof(p) * (len + 1));
	if (p)
	{
		while (tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t')
			i++;
		ft_strncpy(p, tmp + i, ft_strlen(s) - len);
		p[ft_strlen(p)] = '\0';
	}
	return (p);
}
