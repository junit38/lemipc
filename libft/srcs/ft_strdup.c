/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:51:32 by jmery             #+#    #+#             */
/*   Updated: 2013/11/19 12:02:50 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft.h>

char	*ft_strdup(const char *str)
{
	char	*dup;

	dup = (char*)malloc(sizeof(dup) * (ft_strlen(str) + 1));
	dup = ft_strcpy(dup, str);
	return (dup);
}
