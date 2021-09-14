/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:42 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:39:50 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_exit(t_sl *sl)
{
	// TODO: mlx_destroy_image
	// TODO: free every malloc
	mlx_destroy_window(sl->mlx, sl->win);
	sl_print_system_message("Exit. So Long!");
	exit(EXIT_SUCCESS);
}

int	sl_exit_with_error(char *message)
{
	ft_putstr_fd("<ERROR> ", STDIN_FILENO);
	perror(message);
	exit(EXIT_FAILURE);
}

int	sl_exit_with_close_button(t_sl *sl)
{
	sl_exit(sl);
	return (FT_SUCCESS);
}

void	sl_the_end(t_sl *sl)
{
	sl_print_system_message("Congratulations! Game End.");
	sl_exit(sl);
}
