/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 15:56:00 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		clean_game(t_data *data)
{
	semctl(data->sem_id, 0, IPC_RMID, NULL);
	msgctl(data->msq_id, IPC_RMID, NULL);
	shmctl(data->map_id, IPC_RMID, NULL);
	shmctl(data->data_id, IPC_RMID, NULL);
}

void		clean_player(t_data *data, t_player *player)
{
	if (player)
	{
		wait_sem(data);
		data->map = (struct s_player*)shmat(data->map_id, NULL, 0);	
		if (player->isChief)
			change_chief(data, player);
		player->isPlayer = 0;
		player->isChief = 0;
		player->cible_x = -1;
		player->cible_y = -1;
		shmdt(data->map);
		post_sem(data);
	}
}
