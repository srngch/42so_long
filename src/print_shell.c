/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 03:23:13 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:35:57 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_counter(t_sl *sl)
{
	ft_putstr_fd("<Move counter>: ", STDIN_FILENO);
	ft_putnbr_fd(sl->state.move_count, STDIN_FILENO);
	ft_putstr_fd("\n", STDIN_FILENO);
}

void	sl_print_system_message(char *message)
{
	ft_putstr_fd("<SYSTEM> ", STDIN_FILENO);
	ft_putstr_fd(message, STDIN_FILENO);
	ft_putstr_fd("\n", STDIN_FILENO);
}

void	sl_print_map_array(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putchar_fd(map->array[y][x], STDIN_FILENO);
			ft_putchar_fd(' ', STDIN_FILENO);
			x++;
		}
		ft_putchar_fd('\n', STDIN_FILENO);
		y++;
	}
}
