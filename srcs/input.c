/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:42:35 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/21 03:37:23 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_input.h"

int	key_hook(int keycode, t_state *state)
{
	if (keycode == KEY_W)
		state->player_pos.xpos++;
	else if (keycode == KEY_S)
		state->player_pos.xpos--;
	else if (keycode == KEY_ESC)
		sl_exit(state);
	printf("x: %d\n", state->player_pos.xpos);
	return (0);
}

// mouse_hook(int button, int x, int y, void *param);
