/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 03:35:31 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:39:41 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_put_bg_image(t_sl *sl)
{
	mlx_clear_window(sl->mlx, sl->win);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->map.background.img_ptr, 0, 0);
}

static void	sl_put_image(t_sl *sl, void *img_ptr, t_point *img_pos)
{
	mlx_put_image_to_window(sl->mlx, sl->win, img_ptr, \
		img_pos->xpos * MAP_TILE_SIZE, img_pos->ypos * MAP_TILE_SIZE);
}

static void	sl_put_image_with_map_data(\
	t_sl *sl, char map_char, t_point *img_pos)
{
	if (map_char == MAP_WALL)
		sl_put_image(sl, sl->map.objects.wall, img_pos);
	else if (map_char == MAP_EXIT)
		sl_put_image(sl, sl->map.objects.exit, img_pos);
	else if (map_char == MAP_COLLECT)
		sl_put_image(sl, sl->map.objects.collect, img_pos);
	else if (map_char == MAP_PLAYER)
		sl_put_image(sl, sl->map.objects.player, \
			&(sl->state.player_pos));
}

static void	sl_put_object_images(t_sl *sl)
{
	int		x;
	int		y;
	t_point	pos;
	char	c;

	y = 0;
	while (y < sl->map.height)
	{
		x = 0;
		while (x < sl->map.width)
		{
			pos.xpos = x;
			pos.ypos = y;
			c = sl_get_char_in_pos(sl, pos);
			sl_put_image_with_map_data(sl, c, &pos);
			x++;
		}
		y++;
	}
}

void	sl_draw_frame(t_sl *sl)
{
	mlx_clear_window(sl->mlx, sl->win);
	sl_put_bg_image(sl);
	sl_put_object_images(sl);
	// TODO: sl_draw_counter
}
