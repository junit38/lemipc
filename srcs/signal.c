/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 17:59:50 by jmery             #+#    #+#             */
/*   Updated: 2020/09/11 17:00:16 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	sighandler(int sig)
{
	if (sig == SIGQUIT || sig == SIGINT)
	{
		post_sem(g_data);
		clean_player(g_data, g_player);
		if (get_player_count(g_data) == 0)
			clean_game(g_data);
		exit(1);
	}
}

void	initsignal(void)
{
	signal(SIGQUIT, sighandler);
	signal(SIGINT, sighandler);
}
