/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:49 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:46:37 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	sl_get_char_in_pos(t_sl *sl, t_point pos)
{
	return (sl->map.array[pos.ypos][pos.xpos]);
}

int		sl_is_possible_move(t_sl *sl, t_point pos_to_move)
{
	if (sl_get_char_in_pos(sl, pos_to_move) == MAP_WALL)
		return (FT_FALSE);
	else if (sl_get_char_in_pos(sl, pos_to_move) == MAP_COLLECT)
	{
		sl->map.array[pos_to_move.ypos][pos_to_move.xpos] = MAP_EMPTY;
		sl->state.remaining_collect--;
	}
	else if (sl->state.remaining_collect == 0 && \
		sl_get_char_in_pos(sl, pos_to_move) == MAP_EXIT)
	{
		sl->state.is_gameend = FT_TRUE;
	}
	return (FT_TRUE);
}

t_point	sl_get_player_position(t_map *map)
{
	t_point	player_pos;
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == MAP_PLAYER)
			{
				player_pos.xpos = x;
				player_pos.ypos = y;
				return (player_pos);
			}
			x++;
		}
		y++;
	}
	player_pos.xpos = -1;
	player_pos.ypos = -1;
	return (player_pos);
}

int	sl_count_collects(t_map *map)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == MAP_COLLECT)
				count++;
			x++;
		}
		y++;
	}	
	return (count);
}
