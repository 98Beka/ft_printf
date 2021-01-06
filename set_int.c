/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:02:29 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 09:11:14 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	distrb_mn(int *ch_num, t_st *st)
{
	if (st->flags & F_MN)
		wr(0, ch_num, st);
	if (st->flags & F_AC)
		zr_or_sp(ch_num, st->width, st->acrcy, 0);
	else
		zr_or_sp(ch_num, st->width, ft_strlen(st->str), st->flags & F_ZR);
	if (!(st->flags & F_MN))
		wr(0, ch_num, st);
}

int		set_int(int ch_num, int set_i, t_st *st)
{
	st->dig = set_i;
	if (set_i < 0 && (st->acrcy >= 0 || st->flags & F_ZR))
	{
		if (st->flags & F_ZR && st->acrcy < 0)
			write(1, "-", 1);
		set_i *= -1;
		st->flags = st->flags | F_ZR;
		st->width--;
		ch_num++;
	}
	if (!st->acrcy && !set_i)
	{
		zr_or_sp(&ch_num, st->width, 0, 0);
		return (ch_num);
	}
	st->str = ft_itoa(set_i);
	if (st->acrcy >= 0 && (size_t)st->acrcy < ft_strlen(st->str))
		st->acrcy = ft_strlen(st->str);
	distrb_mn(&ch_num, st);
	free(st->str);
	st->str = NULL;
	return (ch_num);
}
