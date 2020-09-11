/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 16:47:14 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <stdio.h>
# include <time.h>

# include <sys/ipc.h>
# include <sys/shm.h>
# include <semaphore.h>
# include <sys/msg.h>
# include <sys/sem.h>
# include <sys/types.h>
# include <sys/ipc.h>

# include "libft.h"
# include "structs.h"

# define MAPSIZE 20
# define BUF_MSG_SIZE get_buf_size()

t_data		*g_data;
t_player	*g_player;

/*
** CASE.C
*/
t_player	*get_case(t_data *data, int x, int y);

/*
** CLEAN.C
*/
void		clean_game(t_data *data);
void		clean_player(t_data *data, t_player *player);

/*
** DATA.C
*/
t_data		*new_data(void);
void		free_data(t_data *data);

/*
** END_GAME.C
*/
void		end_game(t_data *data, t_player *player, int win, int killed);

/*
** GAME.C
*/
void		start_game(t_data *data, t_player *player);

/*
** MAP.C
*/
int 		get_position(int x, int y);
int 		get_player_count(t_data *data);
void		init_map(t_data *data);
void		print_map(t_data *data);

/*
** MOVE.C
*/
t_player	*player_move(t_data *data, t_player *player);

/*
** MSG.C
*/
void		send_next_target(t_data *data, t_player *player);
void		receive_next_target(t_data *data, t_player *player);

/*
** PLAYER.C
*/
t_player	*init_player(t_data *data, char *team);
void		change_chief(t_data *data, t_player *player);

/*
** SEM.C
*/
void		wait_sem(t_data *data);
void		post_sem(t_data *data);

/*
** SIGNAL.C
*/
void		initsignal(void);

#endif
