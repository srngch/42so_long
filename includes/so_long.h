/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:11 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 04:52:55 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "sl_type.h"
# include "sl_macro.h"

/*
** game states
*/
void	sl_exit(t_sl *state);
int		sl_exit_with_error(char *message);
void	sl_the_end(t_sl *sl);

t_point	get_player_position(t_map *map);
int		sl_count_collects(t_map *map);

/*
** map
*/
void	sl_read_map(int filde, t_map *map);
void	sl_validate_map(t_map *map);
void	sl_raw_to_array_map(t_map *map);
void	sl_organize_map(t_map *map);

int		sl_check_map_rectangular(t_map	*map);
int		sl_check_map_letters(t_map	*map);
int		sl_check_map_walls(t_map *map);
int		sl_check_map_essentials(t_map *map);

int		sl_get_map_height(t_map *map);
char	sl_get_char_pos(t_sl *sl, t_point pos);
t_bool	is_char_map_letter(char c);
t_bool	is_str_map_wall(char *str);
t_bool	is_char_in_map(t_map *map, char c);

/*
** image
*/
void	sl_init_images(t_sl *sl);
void	sl_draw_frame(t_sl *sl);

void	*sl_get_png_image(t_sl *sl, char *file);
void	sl_put_image_with_map_data(t_sl *sl, char map_char, t_point *img_pos);
void	sl_fill_color_image(t_img *image, int width, int height, int color);

/*
** input
*/
int		sl_key_hook(int keycode, t_sl *state);
void	sl_move_up(t_sl *sl);
void	sl_move_down(t_sl *sl);
void	sl_move_left(t_sl *sl);
void	sl_move_right(t_sl *sl);
int		sl_close(t_sl *state);

char	sl_get_char_pos(t_sl *sl, t_point pos);
/*
** for TEST
*/
void	sl_print_map_raw(t_map *map);
void	sl_print_map_array(t_map *map);

void	put_test_img_to_window(t_sl *state);

#endif
