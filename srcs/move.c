/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 15:34:07 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_player 	*get_next_move(t_data *data, t_player *player, int diff_x, int diff_y)
{
	if (diff_x == 0 && diff_y < 0)
		return get_case(data, player->x, player->y - 1);
	else if (diff_x > 0 && diff_y < 0)
		return get_case(data, player->x + 1, player->y - 1);
	else if (diff_x > 0 && diff_y == 0)
		return get_case(data, player->x + 1, player->y);
	else if (diff_x > 0 && diff_y > 0)
		return get_case(data, player->x + 1, player->y + 1);
	else if (diff_x == 0 && diff_y > 0)
		return get_case(data, player->x, player->y + 1);
	else if (diff_x < 0 && diff_y > 0)
		return get_case(data, player->x - 1, player->y + 1);
	else if (diff_x < 0 && diff_y == 0)
		return get_case(data, player->x - 1, player->y);
	else if (diff_x < 0 && diff_y < 0)
		return get_case(data, player->x - 1, player->y - 1);
	return (NULL);
}

void		move_to(t_player *player, t_player *to_move)
{
	to_move->isPlayer = 1;
	to_move->team = player->team;
	to_move->isChief = player->isChief;
	player->isPlayer = 0;
	player->isChief = 0;
	player->cible_x = -1;
	player->cible_y = -1;
}

t_player	*player_move(t_data *data, t_player *player)
{
	int			diff_x;
	int			diff_y;
	t_player 	*to_move;

	diff_x = 0;
	diff_y = 0;
	if (player && player->cible_x != -1)
	{
		diff_x = player->cible_x - player->x;
		diff_y = player->cible_y - player->y;
		to_move = get_next_move(data, player, diff_x, diff_y);
		if (to_move && to_move->isPlayer == 1 && to_move->team == player->team)
			to_move = get_next_move(data, player, rand() % MAPSIZE, rand() % MAPSIZE);
		if (to_move && to_move->isPlayer == 0)
		{
			move_to(player, to_move);
			player = to_move;
		}
	}
	return (player);
}
