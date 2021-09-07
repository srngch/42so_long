/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:42:35 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 04:03:02 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_input.h"

int	sl_key_hook(int keycode, t_state *state)
{
	if (keycode == KEY_W)
		state->player_pos.ypos--;
	else if (keycode == KEY_S)
		state->player_pos.ypos++;
	else if (keycode == KEY_A)
		state->player_pos.xpos--;
	else if (keycode == KEY_D)
		state->player_pos.xpos++;
	else if (keycode == KEY_ESC)
		sl_exit(state);
	printf("x: %d / y: %d\n", state->player_pos.xpos, state->player_pos.ypos);
	return (0);
}

// int mouse_hook(int button, int x, int y, void *state)
// {

// }

int sl_close(t_state *state)
{
	sl_exit(state);
	return (FT_SUCCESS);
}
