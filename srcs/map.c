/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:36 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:23:34 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_vaildate_map_file_extension(char *filename)
{
	char	*p;

	p = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (p == NULL)
		sl_exit_with_error("Invalid file extension. Extension must be '.ber'.");
}

static void	sl_read_map(int filde, t_map *map)
{
	char	*buf;
	int		result;

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
}

static void	sl_validate_map(t_map *map)
{
	if (sl_check_map_rectangular(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. The map must be rectangular.");
	if (sl_check_map_letters(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. Unknown characters.");
	if (sl_check_map_walls(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. Maps are not walled up.");
	if (sl_check_map_essentials(map) == FT_ERROR)
		sl_exit_with_error("Invalid map. \
The map must contain one of starting point, one of exit, and collections.");
}

static void	sl_raw_to_array_map(t_map *map)
{
	t_list	*raw_p;
	int		i;

	raw_p = map->raw;
	map->array = (char **)malloc(sizeof(char *) * map->height);
	i = 0;
	while (i < map->height)
	{
		*((map->array) + i) = (char *)raw_p->content;
		i++;
		raw_p = raw_p->next;
	}
}

void	sl_preparing_map(char *map_filename, t_sl *sl)
{
	int		filde;

	sl_vaildate_map_file_extension(map_filename);
	filde = open(map_filename, O_RDONLY);
	if (filde == FT_ERROR)
		sl_exit_with_error("Map file not found.");
	else
	{
		sl_read_map(filde, &(sl->map));
		sl_print_system_message("Completed reading the map file.");
		sl_validate_map(&(sl->map));
		sl_print_system_message("Completed validate the map.");
		sl_raw_to_array_map(&(sl->map));
		sl_print_system_message("Map");
		sl_print_map_array(&(sl->map));
	}
}
