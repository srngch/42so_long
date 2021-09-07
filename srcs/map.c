/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:36 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 04:00:27 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_map.h"

t_map	*sl_read_map(int filde)
{
	t_map	*map;
	char	*buf;
	int		result;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		sl_exit_with_error("Memory allocation failed.");
	map->width = 0;
	map->raw = ft_lstnew(NULL);
	result = get_next_line(filde, &buf);
	while (result != FT_EOF)
	{
		if (map->width == 0)
			map->width = ft_strlen(buf);
		ft_lstadd_back(&(map->raw), ft_lstnew((void *)buf));
		result = get_next_line(filde, &buf);
	}
	return (map);
}

void	sl_validate_map(t_map *map)
{
	if (sl_check_map_rectangular(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. The map must be rectangular.");
	if (sl_check_map_letters(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. Unknown characters.");
	if (sl_check_map_walls(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. Maps are not walled up.");
	if (sl_check_map_essentials(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. \
The map must contain a starting point, exit, and collection.");
}

void	sl_raw_to_array_map(t_map *map)
{
	t_list	*raw_p;
	int		i;

	raw_p = map->raw;
	map->array = (char **)malloc(sizeof(char *) * map->height);
	i = 0;
	while (i < map->height)
	{
		*((map->array) + i) = (char *)raw_p->content;
		printf("arr(%d): %s\n", i, *((map->array) + i));
		i++;
		raw_p = raw_p->next;
	}
}

// TODO: sl_draw_map

void	sl_organize_map(t_map *map)
{
	int		x;
	int		y;
	t_bool	found_player;
	t_bool	found_exit;

	found_player = FT_FALSE;
	found_exit = FT_FALSE;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (found_player == FT_FALSE && map->array[y][x] == MAP_PLAYER)
				found_player = FT_TRUE;
			else if (found_exit == FT_FALSE && map->array[y][x] == MAP_EXIT)
				found_exit = FT_TRUE;
			else if (found_player == FT_TRUE && map->array[y][x] == MAP_PLAYER)
				map->array[y][x] = MAP_EMPTY;
			else if (found_exit == FT_TRUE && map->array[y][x] == MAP_EXIT)
				map->array[y][x] = MAP_EMPTY;
			x++;
		}
		y++;
	}
}
