/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:07:02 by ehande            #+#    #+#             */
/*   Updated: 2020/12/28 11:07:36 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_accuracy(va_list *pa, t_st *st, int *i)
{
	*i +=1;
	if(ft_isdigit(st->arg[*i]))
	{
		st->accuracy = 0;
		while(ft_isdigit(st->arg[*i]))
		{
			st->accuracy = (st->accuracy * 10) + (st->arg[*i] - '0');
			*i+= 1;
		}
	}
	else if(st->arg[*i] == '*')
	{
		st->accuracy = va_arg(*pa, int);
		*i+= 1;
	}
}

void get_width(va_list *pa, t_st *st)
{
	
	st->width = va_arg(*pa, int);
		if (st->width < 0)
	{
		st->flags = st->flags | F_MN;
		st->width *= -1;
	}
	st->flags = st->flags | F_ST;
}

void get_digit(t_st *st, char ch)
{
		if (st->flags & F_ST)
		    st->width = 0;
	st->width = (st->width * 10) + (ch - '0');
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
