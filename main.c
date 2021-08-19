/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:23 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/20 03:09:28 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_with_error(char *message)
{
	ft_putstr_fd("[ERROR] ", STDIN_FILENO);
	perror(message);
	exit(EXIT_FAILURE);
}

void	sl_vaildate_map_file_extension(char *filename)
{
	char	*p;

	p = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (p == NULL)
		sl_exit_with_error("Invalid file extension. Extension must be '.ber'.");
}

void	so_long(char *map_filename)
{
	int		filde;
	t_map	*map;

	sl_vaildate_map_file_extension(map_filename);
	filde = open(map_filename, O_RDONLY);
	if (filde == FT_ERROR)
		sl_exit_with_error("Map file not found.");
	else
	{
		map = sl_read_map(filde);
		sl_print_map(map); ///// TEST
		sl_validate_map(map);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
		perror("Invalid number of arguments.");
	return (0);
}
