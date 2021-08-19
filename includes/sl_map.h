/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:10:03 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/20 03:10:03 by sarchoi          ###   ########.fr       */
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
	int		width;
	int		height;
}				t_map;

t_map	*sl_read_map(int filde);
void	sl_validate_map(t_map *map);

int		sl_check_map_rectangular(t_map	*map);
int		sl_check_map_letters(t_map	*map);
int		sl_check_map_walls(t_map *map);
int		sl_check_map_essentials(t_map *map);

int		sl_get_map_height(t_map *map);
int		is_char_map_letter(char c);
int		is_str_map_wall(char *str);
int		is_char_in_map(t_map *map, char c);

#endif
