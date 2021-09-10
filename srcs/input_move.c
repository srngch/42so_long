/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:10:22 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:51:39 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		sl_is_possible_move(t_sl *sl, t_point pos_to_move)
{
	if (sl_get_char_pos(sl, pos_to_move) == MAP_WALL)
		return (FT_FALSE);
	else if (sl_get_char_pos(sl, pos_to_move) == MAP_COLLECT)
	{
		sl->map.array[pos_to_move.ypos][pos_to_move.xpos] = MAP_EMPTY;
		sl->state.remaining_collect--;
	}
	else if (sl->state.remaining_collect == 0 && \
		sl_get_char_pos(sl, pos_to_move) == MAP_EXIT)
	{
		sl->state.is_gameend = FT_TRUE;
	}
	return (FT_TRUE);
}

void	sl_move_up(t_sl *sl)
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

void	sl_move_down(t_sl *sl)
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

void	sl_move_left(t_sl *sl)
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

void	sl_move_right(t_sl *sl)
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
