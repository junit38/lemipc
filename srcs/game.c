/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 17:01:21 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static t_player	*get_ennemy(t_data *data, t_player *player, int current)
{
	t_player *next_case;

	next_case = NULL;
	if (current == 0)
		next_case = get_case(data, player->x - 1, player->y);
	else if (current == 1)
		next_case = get_case(data, player->x - 1, player->y + 1);
	else if (current == 2)
		next_case = get_case(data, player->x, player->y + 1);
	else if (current == 3)
		next_case = get_case(data, player->x + 1, player->y + 1);
	else if (current == 4)
		next_case = get_case(data, player->x + 1, player->y);
	else if (current == 5)
		next_case = get_case(data, player->x + 1, player->y - 1);
	else if (current == 6)
		next_case = get_case(data, player->x, player->y - 1);
	else if (current == 7)
		next_case = get_case(data, player->x - 1, player->y - 1);
	if (next_case && next_case->is_player && next_case->team != player->team)
		return (next_case);
	return (NULL);
}

static int		is_killed(t_data *data, t_player *player)
{
	int			is_killed;
	int			current_case;
	int			check_case;
	t_player	*enemy;
	t_player	*next_enemy;

	is_killed = 0;
	current_case = 0;
	enemy = NULL;
	while (current_case <= 7 && is_killed == 0)
	{
		enemy = get_ennemy(data, player, current_case);
		check_case = current_case + 1;
		while (enemy != NULL && check_case <= 7 && is_killed == 0)
		{
			next_enemy = get_ennemy(data, player, check_case);
			if (enemy && next_enemy && enemy->team == next_enemy->team)
				is_killed = 1;
			check_case++;
		}
		current_case++;
	}
	return (is_killed);
}

static int		is_win(t_data *data, t_player *player)
{
	int			x;
	int			y;
	int			ennemy;

	x = 0;
	ennemy = 0;
	while (x < MAPSIZE)
	{
		y = 0;
		while (y < MAPSIZE)
		{
			if (data->map[get_position(x, y)].is_player == 1
				&& data->map[get_position(x, y)].team != player->team)
				ennemy++;
			y++;
		}
		x++;
	}
	if (ennemy == 0 && data->dead == 1)
		return (1);
	return (0);
}

void			start_game(t_data *data, t_player *player)
{
	int		killed;
	int		win;

	killed = 0;
	win = 0;
	while (!killed && !win)
	{
		sleep(2);
		print_map(data);
		wait_sem(data);
		data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
		if (is_win(data, player))
			win = 1;
		else if (is_killed(data, player))
			killed = 1;
		else if (player->is_chief == 1)
			send_next_target(data, player);
		else
			receive_next_target(data, player);
		if (killed != 1 && win != 1)
			player = player_move(data, player);
		g_player = player;
		shmdt(data->map);
		post_sem(data);
	}
	end_game(data, player, win, killed);
}
