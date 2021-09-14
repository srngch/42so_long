/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:32:54 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/15 04:53:52 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_MACRO_H
# define SL_MACRO_H

/*
** keycodes 
*/
# define KEY_ESC		53
// # define KEY_Q			12
// # define KEY_E			14
// # define KEY_R			15
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
// TODO: Add arrow keys
# define KEY_ARROW_UP		
# define KEY_ARROW_DOWN		
# define KEY_ARROW_LEFT		
# define KEY_ARROW_RIGHT	
# define X_EVENT_KEY_EXIT	17

/*
** map sources
*/
# define MAP_TILE_SIZE		50
# define MAP_SRC_PLAYER		'image/player.png'
# define MAP_SRC_COLLECT	'image/collect.png'
# define MAP_SRC_WALL		'image/wall.png'
# define MAP_SRC_EXIT		'image/exit.png'
# define MAP_COLOR_BG		0x00DFFFF4

/*
** .ber file characters
*/
# define MAP_PLAYER		'P'
# define MAP_COLLECT	'C'
# define MAP_EMPTY		'0'
# define MAP_WALL		'1'
# define MAP_EXIT		'E'

#endif
