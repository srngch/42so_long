/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:54 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 03:42:46 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// for TEST

void	sl_print_map_raw(t_map *map)
{
	t_list	*raw_p;

	raw_p = map->raw;
	while (raw_p != NULL)
	{
		printf("[] raw    : %s\n", (char *)raw_p->content);
		raw_p = raw_p->next;
	}
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
			printf("%c ", map->array[y][x]);
			x++;
		}
		printf("[LINE END](%d)\n", y);
		y++;
	}
}

void	put_test_img_to_window(t_sl *sl)
{
	int		test_h;
	int		test_w;
	void	*test_img;
	void	*test_img2;
	void	*test_img3;
	void	*test_img4;
	void	*test_img5;

	// mlx_pixel_put(sl.mlx, sl.win, 10, 10, 0x00FF0000);
	// mlx_string_put(sl.mlx, sl.win, sl.player_pos.xpos * MAP_TILE_SIZE, sl.player_pos.ypos * MAP_TILE_SIZE, 0x00FF0000, "TEST TEXT");
	test_img = mlx_png_file_to_image(sl->mlx, "image/player.png", &test_w, &test_h);
	test_img2 = mlx_png_file_to_image(sl->mlx, "image/wall.png", &test_w, &test_h);
	test_img3 = mlx_png_file_to_image(sl->mlx, "image/wall.png", &test_w, &test_h);
	test_img4 = mlx_png_file_to_image(sl->mlx, "image/collect.png", &test_w, &test_h);
	test_img5 = mlx_png_file_to_image(sl->mlx, "image/exit.png", &test_w, &test_h);
	mlx_put_image_to_window(sl->mlx, sl->win, test_img, sl->state.player_pos.xpos * MAP_TILE_SIZE, sl->state.player_pos.ypos * MAP_TILE_SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, test_img2, 0 * MAP_TILE_SIZE, 0 * MAP_TILE_SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, test_img3, 0 * MAP_TILE_SIZE, 1 * MAP_TILE_SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, test_img4, 1* MAP_TILE_SIZE, 1 * MAP_TILE_SIZE);
	mlx_put_image_to_window(sl->mlx, sl->win, test_img5, 2* MAP_TILE_SIZE, 3 * MAP_TILE_SIZE);
}
