/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/02 03:52:45 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map_file;
	int		filde;

	if (argc == 2)
	{
		map_file = argv[1];
		filde = open(map_file, O_RDONLY);
		printf("[test] file: %s(%d)", map_file, filde);
	}
	else
		perror("Invalid number of arguments.");
	
	return (0);
}
