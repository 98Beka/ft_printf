/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:16:27 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 08:24:43 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zr_or_sp(int *ch_num, int width, int str_len, int spzr)
{
	while (width - str_len > 0)
	{
		if (spzr)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width -= 1;
		*ch_num += 1;
	}
}

void		wr(size_t i, int *ch_num, t_st *st)
{
	if(*st->str == '-')
		mn(ch_num, st);
	if (st->flags & F_AC)
		zr_or_sp(ch_num, st->acrcy, ft_strlen(st->str), 1);
	if(st->flags & F_AC && st->str[i] =='0' && st->acrcy == 0)
		return ;
	while (st->str[i] && i < ft_strlen(st->str))
		write(1, &st->str[i++], 1);
	*ch_num += i;
}

char		*chang_notation(int i, unsigned long long inp, int sst)
{
	unsigned long long	tmp;
	char				*str;

	tmp = inp;
	if (!inp)
		return (ft_strdup("0"));
	while (tmp && i++ >= 0)
		tmp /= sst;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	while (i-- >= 0)
	{
		str[i] = (inp % sst) < 10 ? (inp % sst) + 48 : (inp % sst) + 87;
		inp /= sst;
	}
	return (str);
}

int			wrstr(t_st *st, int *ch_num)
{
	while (*st->arg && *st->arg != '%')
	{
		ft_putchar_fd(*st->arg, 1);
		*ch_num += 1;
		if (!str_next(&st->arg))
			return (0);
	}
	return (str_next(&st->arg));
}

int			putchar_next(char ch, int *ch_num)
{
	write(1, &ch, 1);
	*ch_num += 1;
	return (1);
}
