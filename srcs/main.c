/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:44:58 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_vaildate_map_file_extension(char *filename)
{
	char	*p;

	p = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (p == NULL)
		sl_exit_with_error("Invalid file extension. Extension must be '.ber'.");
}

void	sl_struct_init(t_sl *sl)
{
	sl->win_width = MAP_TILE_SIZE * sl->map.width;
	sl->win_height = MAP_TILE_SIZE * sl->map.height;
	sl->state.player_pos = get_player_position(&(sl->map));
	sl->state.remaining_collect = sl_count_collects(&(sl->map));
	sl->state.move_count = 0;
	sl->state.is_gameend = FT_FALSE;
}

void	sl_preparing_map(char *map_filename, t_sl *sl)
{
	int		filde;

	sl_vaildate_map_file_extension(map_filename);
	filde = open(map_filename, O_RDONLY);
	if (filde == FT_ERROR)
		sl_exit_with_error("Map file not found.");
	else
	{
		sl_read_map(filde, &(sl->map));
		sl_print_map_raw(&(sl->map)); ///// TEST
		sl_validate_map(&(sl->map));
		printf("height: %d\n", (&(sl->map))->height);
		// printf("[sl_raw_to_array_map]\n");
		sl_raw_to_array_map(&(sl->map));
		printf("[sl_print_map_array]\n");
		sl_print_map_array(&(sl->map)); ///// TEST
		printf("[sl_organize_map]\n");
		sl_organize_map(&(sl->map));
		printf("[sl_print_map_array - again]\n");
		sl_print_map_array(&(sl->map)); ///// TEST
	}
}

void	so_long(char *map_filename)
{
	t_sl	sl;

	sl_preparing_map(map_filename, &sl);
	// printf("sl_struct_init\n");
	sl_struct_init(&sl);
	// printf("[player_pos] %d, %d\n", \
	//	sl.state.player_pos.xpos, sl.state.player_pos.ypos);
	sl.mlx = mlx_init();
	sl.win = mlx_new_window(sl.mlx, \
		sl.win_width, sl.win_height, "So Long");
	sl_init_images(&sl);
	mlx_key_hook(sl.win, &sl_key_hook, &sl);
	sl_draw_frame(&sl);
	mlx_hook(sl.win, X_EVENT_KEY_EXIT, 0, &sl_close, &sl);
	mlx_loop(sl.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		perror("Invalid number of arguments.");
	return (0);
}
