/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 16:50:00 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_player	*get_case(t_data *data, int x, int y)
{
	t_player *player;

	player = NULL;
	if (x < 0)
		return (NULL);
	else if (x >= MAPSIZE)
		return (NULL);
	else if (y < 0)
		return (NULL);
	else if (y >= MAPSIZE)
		return (NULL);
	player = &data->map[get_position(x, y)];
	return (player);
}
