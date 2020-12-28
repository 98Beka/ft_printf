/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:09:13 by ehande            #+#    #+#             */
/*   Updated: 2020/12/28 11:09:15 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		zr_or_sp(int *ch_num, int width, int str_len, char spzr)
{
    while (width - str_len > 0)
	 {
		write(1, &spzr, 1);
		width -= 1;
		*ch_num += 1;
	 }
}

static void		wr(int i, int *ch_num, char *str, t_st *st)
{
    int len;

    len = ft_strlen(str);
	if (st->accuracy >= 0)
	{
		zr_or_sp(ch_num, st->accuracy, ft_strlen(str), 0);
        while( i++ < st->accuracy)
            write(1, &str[i], 1);
	}
	else
            while( i++ < len)
            write(1, &str[i], 1);

}

int			set_str(int ch_num, char *str, t_st *st)
{
	if (!str)
		str = "(null)";
	if (st->accuracy >= 0 && (size_t)st->accuracy > ft_strlen(str))
		st->accuracy = ft_strlen(str);
	if (st->flags & F_MN)
		wr(-1, &ch_num, str, st);
	if (st->accuracy >= 0)
		zr_or_sp(&ch_num, st->width, st->accuracy, 0);
	else
		zr_or_sp(&ch_num, st->width, ft_strlen(str), 0);
	if (!(st->flags & F_MN))
		wr(-1, &ch_num, str, st);
	return (ch_num);
}
