/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/10/03 00:07:57 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_struct_init(t_sl *sl)
{
	sl->win_width = MAP_TILE_SIZE * sl->map.width;
	sl->win_height = MAP_TILE_SIZE * sl->map.height;
	sl->state.player_pos = sl_get_player_position(&(sl->map));
	sl->state.remaining_collect = sl_count_collects(&(sl->map));
	sl->state.move_count = 0;
	sl->state.is_gameend = FT_FALSE;
}

void	so_long(char *map_filename)
{
	t_sl	sl;

	sl_preparing_map(map_filename, &sl);
	sl_struct_init(&sl);
	sl.mlx = mlx_init();
	sl.win = mlx_new_window(sl.mlx, \
		sl.win_width, sl.win_height, "So Long");
	sl_init_images(&sl);
	sl_draw_frame(&sl);
	mlx_key_hook(sl.win, &sl_key_hook, &sl);
	mlx_hook(sl.win, CLOSE_BUTTON, 0, &sl_exit_with_close_button, &sl);
	mlx_loop(sl.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		sl_exit_with_error("Invalid number of arguments.");
	return (0);
}
