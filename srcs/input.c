/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:42:35 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:47:35 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_move_up(t_sl *sl)
{
	t_point	pos_to_move;

	pos_to_move.xpos = sl->state.player_pos.xpos;
	pos_to_move.ypos = sl->state.player_pos.ypos - 1;
	if (sl_is_possible_move(sl, pos_to_move) == FT_FALSE)
		return ;
	if (sl->state.is_gameend == FT_TRUE)
		sl_the_end(sl);
	sl->state.player_pos.ypos--;
	sl->state.move_count++;
}

static void	sl_move_down(t_sl *sl)
{
	t_point	pos_to_move;

	pos_to_move.xpos = sl->state.player_pos.xpos;
	pos_to_move.ypos = sl->state.player_pos.ypos + 1;
	if (sl_is_possible_move(sl, pos_to_move) == FT_FALSE)
		return ;
	if (sl->state.is_gameend == FT_TRUE)
		sl_the_end(sl);
	sl->state.player_pos.ypos++;
	sl->state.move_count++;
}

static void	sl_move_left(t_sl *sl)
{
	t_point	pos_to_move;

	pos_to_move.xpos = sl->state.player_pos.xpos - 1;
	pos_to_move.ypos = sl->state.player_pos.ypos;
	if (sl_is_possible_move(sl, pos_to_move) == FT_FALSE)
		return ;
	if (sl->state.is_gameend == FT_TRUE)
		sl_the_end(sl);
	sl->state.player_pos.xpos--;
	sl->state.move_count++;
}

static void	sl_move_right(t_sl *sl)
{
	t_point	pos_to_move;

	pos_to_move.xpos = sl->state.player_pos.xpos + 1;
	pos_to_move.ypos = sl->state.player_pos.ypos;
	if (sl_is_possible_move(sl, pos_to_move) == FT_FALSE)
		return ;
	if (sl->state.is_gameend == FT_TRUE)
		sl_the_end(sl);
	sl->state.player_pos.xpos++;
	sl->state.move_count++;
}

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
	sl_draw_frame(sl);
	sl_print_counter(sl);
	return (0);
}
