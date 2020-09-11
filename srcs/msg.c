/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 17:18:16 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			get_buf_size(void)
{
	int		map_size;
	int		size;

	map_size = MAPSIZE;
	size = 0;
	while (map_size / 10 > 0)
	{
		size = size + 1;
		map_size = map_size / 10;
	}
	if (MAPSIZE % (size * 10) > 0)
		size++;
	return (5 + (2 * size));
}

static void	get_next_target(t_data *data, t_player *player)
{
	int			x;
	int			y;

	x = 0;
	while (x < MAPSIZE && player->cible_x == -1)
	{
		y = 0;
		while (y < MAPSIZE && player->cible_x == -1)
		{
			if (data->map[get_position(x, y)].is_player == 1
				&& data->map[get_position(x, y)].team != player->team)
			{
				player->cible_x = x;
				player->cible_y = y;
			}
			y++;
		}
		x++;
	}
}

static void	print_attack(t_player *player)
{
	if (player->cible_x != -1)
		printf("Attacking (%d, %d)\n", player->cible_x, player->cible_y);
}

void		send_next_target(t_data *data, t_player *player)
{
	char	buf[get_buf_size()];
	char	*x;
	char	*y;

	ft_bzero(buf, get_buf_size() + 1);
	ft_strcpy(buf, ft_itoa(player->team));
	buf[1] = '>';
	get_next_target(data, player);
	x = ft_itoa(player->cible_x);
	y = ft_itoa(player->cible_y);
	print_attack(player);
	if (x && y)
	{
		ft_strcpy(buf + 2, x);
		ft_strcpy(buf + 2 + ft_strlen(x), "/");
		ft_strcpy(buf + 3 + ft_strlen(x), y);
		msgsnd(data->msq_id, &buf, get_buf_size() + 1, 0);
		free(x);
		free(y);
	}
}

void		receive_next_target(t_data *data, t_player *player)
{
	char	buf[get_buf_size()];
	char	**split;
	char	**split_2;

	msgrcv(data->msq_id, &buf, get_buf_size() + 1, 0, 0);
	split = ft_strsplit(buf, '>');
	while (ft_atoi(split[0]) != player->team)
	{
		free(split);
		msgrcv(data->msq_id, &buf, get_buf_size() + 1, 0, 0);
		split = ft_strsplit(buf, '>');
	}
	if (split && ft_atoi(split[0]) == player->team)
	{
		split_2 = ft_strsplit(split[1], '/');
		if (split_2)
		{
			player->cible_x = ft_atoi(split_2[0]);
			player->cible_y = ft_atoi(split_2[1]);
			print_attack(player);
			free(split_2);
		}
		free(split);
	}
}
