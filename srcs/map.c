/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:51:02 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 15:55:54 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int 		get_position(int x, int y)
{
	return (x + y * MAPSIZE);
}

int 		get_player_count(t_data *data)
{
	int			x;
	int 		y;
	int 		count;

	x = 0;
	count = 0;
	wait_sem(data);
	data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
	while (x < MAPSIZE)
	{
		y = 0;
		while (y < MAPSIZE)
		{
			if (data->map[get_position(x, y)].isPlayer == 1)
				count++;
			y++;
		}
		x++;
	}
	shmdt(data->map);
	post_sem(data);
	return (count);
}

void	init_map(t_data *data)
{
	int			x;
	int 		y;

	wait_sem(data);
	data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
	x = 0;
	while (x < MAPSIZE)
	{
		y = 0;
		while (y < MAPSIZE)
		{
			data->map[get_position(x, y)].isPlayer = 0;
			data->map[get_position(x, y)].isChief = 0;
			data->map[get_position(x, y)].x = x;
			data->map[get_position(x, y)].y = y;
			data->map[get_position(x, y)].cible_x = -1;
			data->map[get_position(x, y)].cible_y = -1;
			y++;
		}
		x++;
	}
	shmdt(data->map);
	post_sem(data);
}

static void	print_separator()
{
	int 	curs;

	curs = 0;
	ft_putchar('|');
	while (curs < MAPSIZE)
	{
		ft_putchar('-');
		curs++;
	}
	ft_putchar('|');
	ft_putchar('\n');
}

void	print_map(t_data *data)
{
	int		size;
	int		curs;

	size = 0;
	wait_sem(data);
	print_separator();
	data->map = (struct s_player*)shmat(data->map_id, NULL, 0);
	while (size < MAPSIZE)
	{
		curs = 0;
		ft_putchar('|');
		while (curs < MAPSIZE)
		{
			if (data->map[get_position(size, curs)].isPlayer == 0)
				ft_putchar(' ');
			else
				ft_putnbr(data->map[get_position(size, curs)].team);
			curs++;
		}
		ft_putstr("|\n");
		size++;
	}
	shmdt(data->map);
	post_sem(g_data);
	print_separator();
	ft_putchar('\n');
}