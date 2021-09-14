/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:11 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:47:36 by sarchoi          ###   ########.fr       */
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
int		sl_exit_with_close_button(t_sl *sl);
void	sl_the_end(t_sl *sl);

/*
** map
*/
void	sl_preparing_map(char *map_filename, t_sl *sl);

int		sl_check_map_rectangular(t_map	*map);
int		sl_check_map_letters(t_map	*map);
int		sl_check_map_walls(t_map *map);
int		sl_check_map_essentials(t_map *map);

int		sl_get_map_height(t_map *map);
t_bool	sl_is_char_map_letter(char c);
t_bool	sl_is_str_map_wall(char *str);
int		sl_count_char_in_map(t_map *map, char c);

char	sl_get_char_in_pos(t_sl *sl, t_point pos);
int		sl_is_possible_move(t_sl *sl, t_point pos_to_move);
t_point	sl_get_player_position(t_map *map);
int		sl_count_collects(t_map *map);

/*
** graphic
*/
void	sl_init_images(t_sl *sl);
void	sl_draw_frame(t_sl *sl);

/*
** print in shell
*/
void	sl_print_counter(t_sl *sl);
void	sl_print_system_message(char *message);
void	sl_print_map_array(t_map *map);

/*
** input
*/
int		sl_key_hook(int keycode, t_sl *state);

#endif
