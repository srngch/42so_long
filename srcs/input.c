/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:42:35 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 03:43:43 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook(int keycode, t_sl *sl)
{
	if (keycode == KEY_W)
		sl_move_up(sl);
	else if (keycode == KEY_S)
		sl_move_down(sl);
	else if (keycode == KEY_A)
		sl_move_left(sl);
	else if (keycode == KEY_D)
		sl_move_right(sl);
	else if (keycode == KEY_ESC)
		sl_exit(sl);
	printf("x: %d / y: %d\n", sl->state.player_pos.xpos, sl->state.player_pos.ypos);
	sl_draw_frame(sl);
	// TODO: 쉘에 움직임 카운트 수 표시 ft_putstr_fd
	sl_print_map_array(&(sl->map)); ///// TEST
	return (0);
}

// int mouse_hook(int button, int x, int y, void *state)
// {

// }

int sl_close(t_sl *state)
{
	sl_exit(state);
	return (FT_SUCCESS);
}

// TODO
// int	check_collision
