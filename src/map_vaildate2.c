/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vaildate3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 03:56:09 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 03:58:36 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_get_map_height(t_map *map)
{
	return (ft_lstsize(map->raw));
}

t_bool	sl_is_char_map_letter(char c)
{
	if (c == MAP_EMPTY \
		|| c == MAP_WALL \
		|| c == MAP_COLLECT \
		|| c == MAP_EXIT \
		|| c == MAP_PLAYER)
		return (FT_TRUE);
	return (FT_FALSE);
}

t_bool	sl_is_str_map_wall(char *str)
{
	while (*str)
	{
		if (*str != MAP_WALL)
			return (FT_FALSE);
		str++;
	}
	return (FT_TRUE);
}

int	sl_count_char_in_map(t_map *map, char c)
{
	int		count;
	t_list	*raw_p;
	char	*temp_content;

	count = 0;
	raw_p = map->raw;
	while (raw_p != NULL)
	{
		temp_content = (char *)(raw_p->content);
		while (*temp_content)
		{
			if (*temp_content == c)
				count++;
			temp_content++;
		}
		raw_p = raw_p->next;
	}
	return (count);
}
