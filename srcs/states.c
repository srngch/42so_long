/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:42 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 04:05:09 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit(t_state *state)
{
	mlx_destroy_window(state->mlx, state->win);
	ft_putstr_fd("[SYSTEM] Exit. So Long.", STDIN_FILENO);
	exit(EXIT_SUCCESS);
}

int	sl_exit_with_error(char *message)
{
	ft_putstr_fd("[ERROR] ", STDIN_FILENO);
	perror(message);
	exit(EXIT_FAILURE);
}

t_point	get_player_position(t_map *map)
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

// void	loop_hook(void *param)
// {

// }

// expose_hook(void *param);
