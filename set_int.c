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

void mn(int *ch_num, t_st *st)
{
	char *tmp;
	
	write(1, "-", 1);
	tmp = st->str;
	st->str = ft_substr(st->str, 1, ft_strlen(st->str));
	free(tmp);
	st->width--;
	*ch_num += 1;
}

void	distrb_mn(int *ch_num, t_st *st)
{
	if (st->flags & F_MN)
		wr(0, ch_num, st);
	if(st->flags & F_AC && !st->acrcy)
		zr_or_sp(ch_num, st->width, ft_strlen(st->str) - (*st->str == '0'), st->flags & F_ZR);	
	else if (st->flags & F_AC)
	{
		if (st->acrcy < 0 ||((size_t)st->acrcy < ft_strlen(st->str) && st->acrcy >= 0))
		st->acrcy = ft_strlen(st->str) - (*st->str == '-');
		if(*st->str == '-')
			st->width--;
		zr_or_sp(ch_num, st->width, st->acrcy, st->flags & F_ZR);
		if(*st->str == '-')
			st->width++;
	}
	else
		zr_or_sp(ch_num, st->width, ft_strlen(st->str), st->flags & F_ZR);
	if (!(st->flags & F_MN))
		wr(0, ch_num, st);
}

int		set_int(int ch_num, int set_i, t_st *st)
{
	st->dig = set_i;
	st->str = ft_itoa(set_i);
	if (set_i < 0 && st->flags & F_ZR)
		mn(&ch_num, st);
	distrb_mn(&ch_num, st);
	free(st->str);
	st->str = NULL;
	return (ch_num);
}
