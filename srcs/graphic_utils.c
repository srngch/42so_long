/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:43:37 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:32:01 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_fill_color_image(t_img *image, int width, int height, int color)
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

void	*sl_get_png_image(t_sl *sl, char *file)
{
	void	*img_ptr;
	int		width;
	int		height;

	img_ptr = mlx_png_file_to_image(sl->mlx, file, &width, &height);
	if (img_ptr == NULL)
		sl_exit_with_error("Failed to load the object image.");
	printf("[img w, h] %d , %d", width, height);
	return (img_ptr);
}

static void	sl_put_image(t_sl *sl, void *img_ptr, t_point *img_pos)
{
	mlx_put_image_to_window(sl->mlx, sl->win, img_ptr, \
		img_pos->xpos * MAP_TILE_SIZE, img_pos->ypos * MAP_TILE_SIZE);
}

void	sl_put_image_with_map_data(t_sl *sl, char map_char, t_point *img_pos)
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
