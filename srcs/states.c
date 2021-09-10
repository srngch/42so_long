/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:42 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:46:21 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit(t_sl *sl)
{
	// TODO: mlx_destroy_image
	// TODO: free every malloc
	mlx_destroy_window(sl->mlx, sl->win);
	ft_putstr_fd("<SYSTEM> Exit. So Long.", STDIN_FILENO);
	exit(EXIT_SUCCESS);
}

int	sl_exit_with_error(char *message)
{
	ft_putstr_fd("<ERROR> ", STDIN_FILENO);
	perror(message);
	exit(EXIT_FAILURE);
}

void	sl_the_end(t_sl *sl)
{
	printf("<SYSTEM> Game End!\n");
	sl_exit(sl);
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
