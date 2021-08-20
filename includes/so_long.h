/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:11 by sarchoi           #+#    #+#             */
/*   Updated: 2021/08/21 04:59:38 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "mlx.h"
# include "libft.h"
# include "../get_next_line/get_next_line.h"
# include "sl_test.h"

# define FT_SUCCESS		1
# define FT_ERROR		-1
# define FT_EOF			0
# define FT_TRUE		1
# define FT_FALSE		0
# define BUFFER_SIZE	50

typedef struct s_point
{
	int	xpos;
	int	ypos;
}				t_point;

typedef struct s_state
{
	void	*mlx;
	void	*win;
	t_point	player_pos;
}				t_state;

void	sl_exit(t_state *state);

int		sl_exit_with_error(char *message);

int		key_hook(int keycode, t_state *state);

#endif
