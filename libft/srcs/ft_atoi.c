/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:28:29 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:14:15 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_atoi(const char *str)
{
	int		sign;
	int		nb;

	nb = 0;
	sign = -1;
	while (!ft_isdigit(*str) && sign == (-1))
	{
		if (*str == '-')
			sign = 1;
		else if (*str != '\n' && *str != '\v' && *str != '\t' && *str != '\r'
			&& *str != '\f' && *str != ' ' && *str != '+' && *str != '\0')
			sign = 0;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb = nb * 10;
		if ((nb >= -2147483640) || (((nb + 2147483640) + (*str - 48)) >= 7))
			nb = nb - (*str - 48);
		str++;
	}
	if (sign == -1 && nb == -2147483648)
		return (nb);
	return (nb * sign);
}
