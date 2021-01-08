/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:02:58 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 08:27:10 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		str_next(char **s)
{
	if (!**s)
		return (0);
	*s += 1;
	if (**s)
		return (1);
	return (0);
}

void	zero_acrcy(int *ch_num, t_st *st)
{
	int	l;

	l = ft_strlen(st->str);
	zr_or_sp(ch_num, st->width, l - (*st->str == '0'), st->flags & F_ZR);
}

int		set_char(int ch_num, char c, t_st *st)
{
	ch_num = 0;
	if (st->flags & F_MN)
		write(1, &c, 1);
	zr_or_sp(&ch_num, st->width - 1, 0, st->flags & F_ZR);
	if (!(st->flags & F_MN))
		write(1, &c, 1);
	ch_num += 1;
	return (ch_num);
}
