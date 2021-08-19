/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:36 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/20 03:09:39 by sarchoi          ###   ########.fr       */
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
