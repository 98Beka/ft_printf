/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:18:42 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 08:51:02 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	touperstr(size_t i, char *s)
{
	while (s[i++])
		if (ft_isalpha(s[i]))
			s[i] = ft_toupper(s[i]);
}

int		set_x(int ch_num, unsigned int input, t_st *st, int x)
{
	if (!st->acrcy && !input)
	{
		zr_or_sp(&ch_num, st->width, 0, 0);
		return (ch_num);
	}
	st->str = chang_notation(0, input, 16);
	if (x)
		touperstr(-1, st->str);
	if (st->acrcy >= 0 && (size_t)st->acrcy < ft_strlen(st->str))
		st->acrcy = ft_strlen(st->str);
	if (st->flags & F_MN)
		wr(0, &ch_num, st);
	if (st->acrcy >= 0)
		zr_or_sp(&ch_num, st->width - st->acrcy, 0, 0);
	else
		zr_or_sp(&ch_num, st->width, ft_strlen(st->str), st->flags & F_ZR);
	if (!(st->flags & F_MN))
		wr(0, &ch_num, st);
	free(st->str);
	st->str = NULL;
	return (ch_num);
}
