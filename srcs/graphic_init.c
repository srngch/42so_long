/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic-init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:10:03 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:15:58 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_fill_color_image(t_img *image, int width, int height, int color)
{
	int	h;
	int	w;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			image->addr[h * width + w] = color;
			w++;
		}
		h++;
	}
}

static void	sl_set_bg_image(t_sl *sl)
{
	int	bg_height;
	int	bg_width;

	bg_height = sl->win_height + 50;
	bg_width = sl->win_width;
	sl->map.background.img_ptr = mlx_new_image(sl->mlx, \
		bg_width, bg_height);
	if (sl->map.background.img_ptr == NULL)
		sl_exit_with_error("Failed to load the background image.");
	sl->map.background.addr = (int *)mlx_get_data_addr(\
		sl->map.background.img_ptr, \
		&sl->map.background.bits_per_pixel, \
		&sl->map.background.size_line, \
		&sl->map.background.endian);
	sl_fill_color_image(&(sl->map.background), \
		bg_width, bg_height, MAP_COLOR_BG);
}

static void	*sl_get_png_image(t_sl *sl, char *file)
{
	void	*img_ptr;
	int		width;
	int		height;

	img_ptr = mlx_png_file_to_image(sl->mlx, file, &width, &height);
	if (img_ptr == NULL)
		sl_exit_with_error("Failed to load the object image.");
	return (img_ptr);
}

static void	sl_set_object_images(t_sl *sl)
{
	sl->map.objects.wall = sl_get_png_image(sl, "image/wall.png");
	sl->map.objects.exit = sl_get_png_image(sl, "image/exit.png");
	sl->map.objects.collect = sl_get_png_image(sl, "image/collect.png");
	sl->map.objects.player = sl_get_png_image(sl, "image/player.png");
}

void	sl_init_images(t_sl *sl)
{
	sl_set_bg_image(sl);
	sl_set_object_images(sl);
}
