/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/23 16:12:24 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int	get_shm_id_data(void)
{
	int		shm_id;
	key_t	shm_key;

	shm_key = ftok(".", 'x');
	shm_id = shmget(shm_key, sizeof(struct s_data), IPC_CREAT | 0666);
	if (shm_id < 0)
	{
		printf("shmget error\n");
		exit(1);
	}
	return (shm_id);
}

static int	get_shm_id_map(void)
{
	int		shm_id;
	key_t	shm_key;

	shm_key = ftok("map.txt", 'x');
	shm_id = shmget(shm_key,
		sizeof(struct s_player) * (MAPSIZE * MAPSIZE), IPC_CREAT | 0666);
	if (shm_id < 0)
	{
		printf("shmget error\n");
		exit(1);
	}
	return (shm_id);
}

static int	get_msq_id(void)
{
	int		msq_id;
	key_t	shm_key;

	shm_key = ftok("msgq.txt", 'B');
	msq_id = msgget(shm_key, IPC_CREAT | 0644);
	if (msq_id < 0)
	{
		printf("shmget error\n");
		exit(1);
	}
	return (msq_id);
}

t_data		*init_data(t_data *data)
{
	data->sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
	data->msq_id = get_msq_id();
	data->map_id = get_shm_id_map();
	data->dead = 0;
	post_sem(data);
	init_map(data);
	return (data);
}

int			main(int argc, char **argv)
{
	int		shm_id;

	if (argc == 2 && ft_atoi(argv[1]) >= 0 && ft_atoi(argv[1]) < 10)
	{
		initsignal();
		shm_id = get_shm_id_data();
		g_data = (struct s_data *)shmat(shm_id, NULL, 0);
		if (g_data->filled != 1)
		{
			g_data->data_id = shm_id;
			init_data(g_data);
			g_data->filled = 1;
		}
		g_player = init_player(g_data, argv[1]);
		start_game(g_data, g_player);
		shmdt(g_data);
	}
	else
	{
		ft_putstr(argv[0]);
		ft_putstr(" [team<0.9>]\n");
	}
	return (0);
}
