/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 03:09:54 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:40:27 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_map.h"

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
	char	**array;

	array = map->array;
	while (*array)
	{
		while (**array)
		{
			printf("%c ", **array);
			(*array)++;
		}
		printf("[LINE END]\n");
		array++;
	}
}
