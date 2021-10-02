/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:32:54 by sarchoi           #+#    #+#             */
/*   Updated: 2021/10/03 00:04:20 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_MACRO_H
# define SL_MACRO_H

/*
** keycodes 
** ESC: exit 
** Q: exit 
** ARROW KEYS: move player
** WASD: move player
** CLOSE_BUTTON: the red close button at window bar
** 
*/
# define KEY_ESC			53
# define KEY_Q				12
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_UP		126
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define CLOSE_BUTTON		17

/*
** map sources
*/
# define MAP_TILE_SIZE		50
# define MAP_SRC_PLAYER		'image/player.png'
# define MAP_SRC_COLLECT	'image/collect.png'
# define MAP_SRC_WALL		'image/wall.png'
# define MAP_SRC_EXIT		'image/exit.png'
# define MAP_COLOR_BG		0x00DFFFF4
# define MAP_COLOR_TEXT		0x00D9625B
# define DECIMAL_BASE		"0123456789"

/*
** .ber file characters
*/
# define MAP_PLAYER		'P'
# define MAP_COLLECT	'C'
# define MAP_EMPTY		'0'
# define MAP_WALL		'1'
# define MAP_EXIT		'E'

/*
** ANSI Color Codes
*/
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define BLUE			"\x1b[34m"
# define YELLOW			"\x1b[33m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

#endif
