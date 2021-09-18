/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:00:35 by sarchoi           #+#    #+#             */
/*   Updated: 2021/09/19 00:23:10 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_num_length(unsigned int num)
{
	int	length;

	if (num == 0)
		return (1);
	length = 0;
	if (num < 0)
		length++;
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}

char	*sl_itoa(int nbr, char *buf)
{
	long long	n;
	int			length;

	if (nbr == 0)
	{
		*buf = '0';
		*(buf + 1) = '\0';
		return (buf);
	}
	n = nbr;
	length = sl_num_length(n);
	*(buf + length) = '\0';
	if (nbr < 0)
		n *= -1;
	while (n)
	{
		*(buf + --length) = DECIMAL_BASE[n % 10];
		n /= 10;
	}
	if (nbr < 0)
		*buf = '-';
	return (buf);
}
