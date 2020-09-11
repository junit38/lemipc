/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 16:10:13 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	end_game(t_data *data, t_player *player, int win, int killed)
{
	wait_sem(data);
	data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
	if (killed == 1)
	{
		data->dead = 1;
		printf("GAME OVER! (%d)\n", player->team);
	}
	else if (win == 1)
		printf("CONGRATULATIONS YOU WIN! (%d)\n", player->team);
	shmdt(data->map);
	post_sem(data);
	clean_player(data, player);
	if (get_player_count(data) == 0)
		clean_game(data);
}