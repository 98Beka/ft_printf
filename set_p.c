/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:18:05 by ehande            #+#    #+#             */
/*   Updated: 2021/01/07 19:54:30 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wr_p(int i, t_st *st, int *ch_num)
{
	*ch_num += write(1, "0x", 2);
	if (!st->acrcy && st->flags & F_AC)
	{
		st->width = 0;
		return (0);
	}
	if (st->flags & F_AC)
	{
		zr_or_sp(ch_num, st->acrcy, ft_strlen(st->str), 1);
		if (st->acrcy < 0)
			st->acrcy = ft_strlen(st->str);
		while (st->str[i] && i <= st->acrcy)
			i += putchar_next(st->str[i], ch_num);
	}
	else
		while (st->str[i])
			i += putchar_next(st->str[i], ch_num);
	return (1);
}

int		set_p(int ch_num, unsigned long long input, t_st *st)
{
	size_t len;

	len = 1;
	if (!st->acrcy && st->flags & F_AC)
		len = 0;
	if (!input)
		st->str = chang_notation(0, input, 16);
	else
	{
		st->str = chang_notation(0, input, 16);
		len = ft_strlen(st->str);
	}
	if (st->flags & F_MN)
		if (!wr_p(0, st, &ch_num))
			return (ch_num);
	zr_or_sp(&ch_num, st->width, len + 2, st->flags & F_ZR);
	if (!(st->flags & F_MN))
		if (!wr_p(0, st, &ch_num))
			return (ch_num);
	free(st->str);
	st->str = NULL;
	return (ch_num);
}
