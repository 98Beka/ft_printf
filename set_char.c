/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:02:58 by ehande            #+#    #+#             */
/*   Updated: 2020/12/28 11:03:01 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_char(int ch_num, char c, t_st *st)
{
	if (st->flags & F_MN)
		write(1, &c, 1);
    while (st->width - 1 > 0)
	 {
		write(1, " ", 1);
		st->width -= 1;
		ch_num += 1;
	 }
	if (!(st->flags & F_MN))
		write(1, &c, 1);
    return (ch_num + 1);
}
	
