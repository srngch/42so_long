/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 04:05:56 by sarchoi          ###   ########.fr       */
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

void	sl_state_init(t_state *state, t_map **map)
{
	state->player_pos = get_player_position(*map);
	state->block_size = 50;
	state->win_width = state->block_size * (*map)->width;
	state->win_height = state->block_size * (*map)->height;
}

void	sl_preparing_map(char *map_filename, t_map **map)
{
	int		filde;

	sl_vaildate_map_file_extension(map_filename);
	filde = open(map_filename, O_RDONLY);
	if (filde == FT_ERROR)
		sl_exit_with_error("Map file not found.");
	else
	{
		// TODO: map 전부 이중 포인터로 바꾸기
		*map = sl_read_map(filde);
		sl_print_map_raw(*map); ///// TEST
		sl_validate_map(*map);
		printf("height: %d\n", (*map)->height);
		// printf("[sl_raw_to_array_map]\n");
		sl_raw_to_array_map(*map);
		printf("[sl_print_map_array]\n");
		sl_print_map_array(*map); ///// TEST
		printf("[sl_organize_map]\n");
		sl_organize_map(*map);
		printf("[sl_print_map_array - again]\n");
		sl_print_map_array(*map); ///// TEST
	}
}

void	so_long(char *map_filename)
{
	t_state	state;
	t_map	*map;

	sl_preparing_map(map_filename, &map);
	// TODO: 각 요소별, 플레이어 등 포지션 세팅
	printf("sl_state_init\n");
	sl_state_init(&state, &map);
	printf("[player_pos] %d, %d\n", state.player_pos.xpos, state.player_pos.ypos);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, state.win_width, state.win_height, "So Long");
	mlx_pixel_put(state.mlx, state.win, 10, 10, 0x00FF0000);
	mlx_string_put(state.mlx, state.win, state.player_pos.xpos * 50, state.player_pos.ypos * 50, 0x00FF0000, "TEST TEXT");
	mlx_key_hook(state.win, &sl_key_hook, &state);
	// mlx_mouse_hook(state.win, &mouse_hook, &state);
	mlx_hook(state.win, X_EVENT_KEY_EXIT, 0, &sl_close, &state);
	mlx_loop(state.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		perror("Invalid number of arguments.");
	return (0);
}
