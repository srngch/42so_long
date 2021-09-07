/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:10:03 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 02:08:23 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_MAP_H
# define SL_MAP_H

# include "libft.h"

# define MAP_EMPTY		'0'
# define MAP_WALL		'1'
# define MAP_COLLECT	'C'
# define MAP_EXIT		'E'
# define MAP_PLAYER		'P'

typedef struct s_map
{
	t_list	*raw;
	char	**array;
	int		width;
	int		height;
}				t_map;

t_map	*sl_read_map(int filde);
void	sl_validate_map(t_map *map);
void	sl_raw_to_array_map(t_map *map);
// void	sl_draw_map(t_map *map);
void	sl_organize_map(t_map *map);

int		sl_check_map_rectangular(t_map	*map);
int		sl_check_map_letters(t_map	*map);
int		sl_check_map_walls(t_map *map);
int		sl_check_map_essentials(t_map *map);

int		sl_get_map_height(t_map *map);
t_bool	is_char_map_letter(char c);
t_bool	is_str_map_wall(char *str);
t_bool	is_char_in_map(t_map *map, char c);

#endif
