/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:27:52 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/11 03:37:05 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_TYPE_H
# define SL_TYPE_H

typedef struct s_point
{
	int	xpos;
	int	ypos;
}				t_point;

typedef struct	s_img
{
	void		*img_ptr;
	int			*addr;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
}				t_img;

typedef struct s_objects
{
	void	*player;
	void	*collect;
	void	*wall;
	void	*exit;
}				t_objects;

typedef struct s_map
{
	t_list		*raw;
	char		**array;
	int			width;
	int			height;
	t_img		background;
	t_objects	objects;
}				t_map;

typedef struct s_state
{
	t_point	player_pos;
	int		remaining_collect;
	int		move_count;
	t_bool	is_gameend;
}				t_state;

typedef struct s_sl
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		win_width;
	int		win_height;
	t_state	state;
}				t_sl;

#endif
