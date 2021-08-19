/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:49 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/20 03:09:50 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_map.h"

int	sl_get_map_height(t_map *map)
{
	int		map_height;

	map_height = ft_lstsize(map->raw);
	return (map_height);
}

int	is_char_map_letter(char c)
{
	if (c == MAP_EMPTY
		|| c == MAP_WALL
		|| c == MAP_COLLECT
		|| c == MAP_EXIT
		|| c == MAP_PLAYER)
		return (FT_TRUE);
	return (FT_FALSE);
}

int	is_str_map_wall(char *str)
{
	while (*str)
	{
		if (*str != MAP_WALL)
			return (FT_FALSE);
		str++;
	}
	return (FT_TRUE);
}

int	is_char_in_map(t_map *map, char c)
{
	t_list	*raw_p;
	char	*temp_content;

	raw_p = map->raw;
	while (raw_p != NULL)
	{
		temp_content = (char *)(raw_p->content);
		while (*temp_content)
		{
			if (*temp_content == c)
				return (FT_TRUE);
			temp_content++;
		}
		raw_p = raw_p->next;
	}
	return (FT_FALSE);
}
