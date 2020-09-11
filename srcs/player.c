/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 16:41:02 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static t_player	*init_player_position(t_data *data, int team)
{
	int 	x;
	int 	y;

	srand(time(NULL));
	x = rand() % MAPSIZE;
	y = rand() % MAPSIZE;
	while (data->map[get_position(x, y)].is_player == 1)
	{
		x = rand() % MAPSIZE;
		y = rand() % MAPSIZE;
	}
	data->map[get_position(x, y)].is_player = 1;
	data->map[get_position(x, y)].team = team;
	return (&data->map[get_position(x, y)]);
}

static int 		is_player_chef(t_data *data, t_player *player)
{
	int			x;
	int 		y;
	int 		isChef;

	x = 0;
	isChef = 1;
	while (x < MAPSIZE)
	{
		y = 0;
		while (y < MAPSIZE)
		{
			if (data->map[get_position(x, y)].is_player
				&& data->map[get_position(x, y)].team == player->team
				&& x != player->x && y != player->y)
				isChef = 0;
			y++;
		}
		x++;
	}
	return (isChef);
}

void		change_chief(t_data *data, t_player *player)
{
	int			x;
	int 		y;

	x = 0;
	while (x < MAPSIZE)
	{
		y = 0;
		while (y < MAPSIZE)
		{
			if (data->map[get_position(x, y)].is_player
				&& data->map[get_position(x, y)].team == player->team)
				data->map[get_position(x, y)].is_chief = 1;
			y++;
		}
		x++;
	}
}

t_player	*init_player(t_data *data, char *team)
{
	t_player	*player;

	wait_sem(data);
	data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
	player = init_player_position(data, ft_atoi(team));
	if (is_player_chef(data, player))
		player->is_chief = 1;
	printf("Player on %d, %d\n", player->x, player->y);
	shmdt(data->map);
	post_sem(data);
	return (player);
}