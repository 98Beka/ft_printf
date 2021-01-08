/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:09:13 by ehande            #+#    #+#             */
/*   Updated: 2021/01/07 19:55:18 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(size_t i, size_t j, char *str)
{
	while (i < j)
		write(1, &str[i++], 1);
	return (i);
}

int		set_str(int ch_num, char *str, t_st *st)
{
	size_t len;

	if (!str)
		str = NN;
	len = ft_strlen(str);
	if ((size_t)st->acrcy > len || st->acrcy < 0 || !(st->flags & F_AC))
		st->acrcy = len;
	if (st->flags & F_MN)
		ch_num += print_str(0, st->acrcy, str);
	zr_or_sp(&ch_num, st->width, st->acrcy, st->flags & F_ZR);
	if (st->flags & F_AC)
		zr_or_sp(&ch_num, st->acrcy, len, 1);
	if (!(st->flags & F_MN))
		ch_num += print_str(0, st->acrcy, str);
	return (ch_num);
}
