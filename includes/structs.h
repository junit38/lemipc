/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 16:27:20 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_player
{
	int				team;
	int				x;
	int				y;
	int				is_player;
	int				is_chief;
	int				cible_x;
	int				cible_y;
}					t_player;

typedef struct		s_data
{
	t_player		*map;
	int				filled;
	int				data_id;
	int				map_id;
	int				sem_id;
	int				msq_id;
	int				dead;
}					t_data;

#endif
