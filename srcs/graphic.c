/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:10:03 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:29:46 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_set_bg_image(t_sl *sl)
{
	int	bg_height;
	int	bg_width;

	bg_height = sl->win_height + 50;
	bg_width = sl->win_width;
	sl->map.background.img_ptr = mlx_new_image(sl->mlx, \
		bg_width, bg_height);
	if (sl->map.background.img_ptr == NULL)
		printf("Failed to load the background image.");
	sl->map.background.addr = (int *)mlx_get_data_addr(sl->map.background.img_ptr, \
		&sl->map.background.bits_per_pixel, \
		&sl->map.background.size_line, \
		&sl->map.background.endian);
	sl_fill_color_image(&(sl->map.background), \
		bg_width, bg_height, MAP_COLOR_BG);
}

static void	sl_put_bg_image(t_sl *sl)
{
	mlx_clear_window(sl->mlx, sl->win);
	mlx_put_image_to_window(sl->mlx, sl->win, sl->map.background.img_ptr, 0, 0);
}

static void	sl_set_object_images(t_sl *sl)
{
	sl->map.objects.wall = sl_get_png_image(sl, "image/wall.png");
	sl->map.objects.exit = sl_get_png_image(sl, "image/exit.png");
	sl->map.objects.collect = sl_get_png_image(sl, "image/collect.png");
	sl->map.objects.player = sl_get_png_image(sl, "image/player.png");
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
			c = sl_get_char_pos(sl, pos);
			sl_put_image_with_map_data(sl, c, &pos);
			x++;
		}
		y++;
	}
}

void		sl_init_images(t_sl *sl)
{
	sl_set_bg_image(sl);
	sl_set_object_images(sl);
}

void	sl_draw_frame(t_sl *sl)
{
	// TODO: put every image
	mlx_clear_window(sl->mlx, sl->win);
	sl_put_bg_image(sl);
	sl_put_object_images(sl);
	// put_test_img_to_window(sl);
}
