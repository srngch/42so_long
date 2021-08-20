/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:42 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/20 23:51:48 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit(t_state *state)
{
	mlx_destroy_window(state->mlx, state->win);
	ft_putstr_fd("[SYSTEM] Exit. So Long.", STDIN_FILENO);
	exit(EXIT_SUCCESS);
}

// void	loop_hook(void *param)
// {

// }

// expose_hook(void *param);
