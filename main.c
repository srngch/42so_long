/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:58:47 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_with_error(char *message)
{
	ft_putstr_fd("[ERROR] ", STDIN_FILENO);
	perror(message);
	exit(EXIT_FAILURE);
} 

void	sl_vaildate_map_file_extension(char *filename)
{
	char	*p;

	p = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (p == NULL)
		sl_exit_with_error("Invalid file extension. Extension must be '.ber'.");
}

// void sl_state_init(t_state *state, t_map *map)
// {
//	state->player_pos = sl_find_pos_spawn(map);
// 	state->map_pos_spawn
// 	state->player_pos_x = 3;
// 	state->player_pos_y = 4;
// }

void	so_long(char *map_filename)
{
	t_state	state;
	int		filde;
	t_map	*map;

	sl_vaildate_map_file_extension(map_filename);
	filde = open(map_filename, O_RDONLY);
	if (filde == FT_ERROR)
		sl_exit_with_error("Map file not found.");
	else
	{
		map = sl_read_map(filde);
		sl_print_map_raw(map); ///// TEST
		sl_validate_map(map);
		sl_raw_to_array_map(map);
		sl_print_map_array(map); ///// TEST
	}
	// TODO: 각 요소별, 플레이어 등 포지션 세팅
	// 플레이어 스폰 좌표가 두 개라면 가장 좌상단에 있는 것만 남기고 0으로 변경
	// sl_state_init(&state);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, 500, 500, "So Long");
	mlx_pixel_put(state.mlx, state.win, 10, 10, 0x00FF0000); mlx_string_put(state.mlx, state.win, 50, 50, 0x00FF0000, "TEST TEXT");
	mlx_key_hook (state.win, &key_hook, &state);
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
