/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 17:02:45 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_player	*get_next_move(t_data *data, t_player *player, int d_x, int d_y)
{
	if (d_x == 0 && d_y < 0)
		return (get_case(data, player->x, player->y - 1));
	else if (d_x > 0 && d_y < 0)
		return (get_case(data, player->x + 1, player->y - 1));
	else if (d_x > 0 && d_y == 0)
		return (get_case(data, player->x + 1, player->y));
	else if (d_x > 0 && d_y > 0)
		return (get_case(data, player->x + 1, player->y + 1));
	else if (d_x == 0 && d_y > 0)
		return (get_case(data, player->x, player->y + 1));
	else if (d_x < 0 && d_y > 0)
		return (get_case(data, player->x - 1, player->y + 1));
	else if (d_x < 0 && d_y == 0)
		return (get_case(data, player->x - 1, player->y));
	else if (d_x < 0 && d_y < 0)
		return (get_case(data, player->x - 1, player->y - 1));
	return (NULL);
}

void		move_to(t_player *player, t_player *to_move)
{
	to_move->is_player = 1;
	to_move->team = player->team;
	to_move->is_chief = player->is_chief;
	player->is_player = 0;
	player->is_chief = 0;
	player->cible_x = -1;
	player->cible_y = -1;
}

t_player	*player_move(t_data *data, t_player *player)
{
	int			diff_x;
	int			diff_y;
	t_player	*to_move;

	diff_x = 0;
	diff_y = 0;
	if (player && player->cible_x != -1)
	{
		diff_x = player->cible_x - player->x;
		diff_y = player->cible_y - player->y;
		to_move = get_next_move(data, player, diff_x, diff_y);
		if (to_move && to_move->is_player == 1 && to_move->team == player->team)
			to_move = get_next_move(data, player,
				rand() % MAPSIZE, rand() % MAPSIZE);
		if (to_move && to_move->is_player == 0)
		{
			move_to(player, to_move);
			player = to_move;
		}
	}
	return (player);
}
