/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:02:29 by ehande            #+#    #+#             */
/*   Updated: 2020/12/28 11:05:14 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		zr_or_sp(int *ch_num, int width, int str_len, char spzr)
{
	 while (width - str_len > 0)
	 {
		write(1, &spzr, 1);
		width -= 1;
		*ch_num += 1;
	 }
}

void	wr(size_t i, int *ch_num, t_st *st)
{
	if (st->dig < 0 && st->accuracy >= 0)
		write(1, "-", 1);
	if (st->accuracy >= 0)
		zr_or_sp(ch_num, st->accuracy - 1, ft_strlen(st->str) - 1, '0');
	while (st->str[i] && i < ft_strlen(st->str))
	{
		write(1, &st->str[i], 1);
		i++;
		*ch_num += 1;
	}
}

 void	f1(int *ch_num, t_st *st)
{
	if (st->flags & F_MN)
		wr(0, ch_num, st);

	if (st->accuracy >= 0 && (size_t)st->accuracy < ft_strlen(st->str))
		st->accuracy = ft_strlen(st->str);
	if (st->accuracy >= 0)
	{
		st->width -= st->accuracy;
		zr_or_sp(ch_num, st->width, 0, ' ');
	}
	else
		zr_or_sp(ch_num, st->width, ft_strlen(st->str), st->flags & F_ZR);
	if (!(st->flags & F_MN))
		wr(0, ch_num, st);
}

int set_int(int ch_num, int set_i, t_st *st)
{
	st->dig = set_i;
	if (set_i < 0 && (st->accuracy >= 0 || st->flags & F_ZR))
	{
		if (st->flags & F_ZR && st->accuracy < 0)
			write(1, "-", 1);
		set_i *= -1;
		st->flags =st->flags | F_ZR;
		st->width--; 
		ch_num++;
	}	
	if (!st->accuracy && !set_i)
	{
		if(st->flags & F_MN && st->accuracy > 0)
			write(1, "0", 1);
		if(st->accuracy > 0)
			st->width--;
		zr_or_sp(&ch_num, st->width, 0, ' ');
		if(!(st->flags & F_MN) && st->accuracy > 0)
			write(1, "0", 1);
		return (ch_num);
	}
	st->str = ft_itoa(set_i);
	f1(&ch_num, st);
	free(st->str);
   return(ch_num);
}
