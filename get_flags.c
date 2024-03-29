/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:07:02 by ehande            #+#    #+#             */
/*   Updated: 2021/01/07 19:53:38 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_accuracy(va_list *pa, t_st *st)
{
	st->flags = st->flags | F_AC;
	st->arg += 1;
	if (ft_isdigit(*st->arg))
	{
		st->acrcy = 0;
		while (ft_isdigit(*st->arg))
			st->acrcy = (st->acrcy * 10) + (*(st->arg++) - '0');
	}
	else if (*st->arg == '*')
	{
		st->acrcy = va_arg(*pa, int);
		st->arg++;
	}
	if (st->acrcy >= 0)
		st->flags = st->flags & ~F_ZR;
	return (st->acrcy != 0 || *st->arg + 1 != 'p');
}

void	get_width(va_list *pa, t_st *st)
{
	st->width = va_arg(*pa, int);
	if (st->width < 0)
	{
		st->flags = st->flags | F_MN;
		st->flags = (st->flags & ~F_ZR) | F_MN;
		st->width *= -1;
	}
	st->flags = st->flags | F_ST;
}

void	get_digit(t_st *st)
{
	while (ft_isdigit(*st->arg))
	{
		st->width = (st->width * 10) + (*st->arg - '0');
		str_next(&st->arg);
	}
}

int		specif_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		is_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}
