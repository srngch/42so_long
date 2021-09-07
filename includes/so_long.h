/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:47:11 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/08 03:56:17 by sarchoi          ###   ########.fr       */
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

// # define FT_SUCCESS		1
// # define FT_ERROR		-1
// # define FT_EOF			0
// # define FT_TRUE		1
// # define FT_FALSE		0
// # define BUFFER_SIZE	50

# define X_EVENT_KEY_EXIT	17

typedef struct s_point
{
	int	xpos;
	int	ypos;
}				t_point;

typedef struct s_state
{
	void	*mlx;
	void	*win;
	int		block_size;
	int		win_width;
	int		win_height;
	t_point	player_pos;
}				t_state;

void	sl_exit(t_state *state);
int		sl_exit_with_error(char *message);

t_point	get_player_position(t_map *map);

int		sl_key_hook(int keycode, t_state *state);
// int		mouse_hook(int button, int x, int y, void *state);
int		sl_close(t_state *state);

#endif
