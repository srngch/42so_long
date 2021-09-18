/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:25:42 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/18 18:17:46 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_destroy_images(t_sl *sl)
{
	mlx_destroy_image(sl->mlx, sl->map.objects.wall);
	mlx_destroy_image(sl->mlx, sl->map.objects.exit);
	mlx_destroy_image(sl->mlx, sl->map.objects.collect);
	mlx_destroy_image(sl->mlx, sl->map.objects.player);
}

void	sl_exit(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	sl_destroy_images(sl);
	ft_lstclear(&(sl->map.raw), free);
	free(sl->map.array);
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
