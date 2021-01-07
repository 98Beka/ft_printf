/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:23:39 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 09:25:08 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flginit(t_st *st)
{
	st->flags = F_NONE;
	st->str = NULL;
	st->dig = 0;
	st->width = 0;
	st->acrcy = 0;
}

void		distrib(int *ch_num, va_list *pa, t_st *st)
{
	if (*st->arg == 'd' || *st->arg == 'i')
		*ch_num += set_int(0, va_arg(*pa, long int), st);
	if (*st->arg == 'c')
		*ch_num += set_char(0, va_arg(*pa, int), st);
	if (*st->arg == 's')
		*ch_num += set_str(0, va_arg(*pa, char *), st);
	if (*st->arg == 'u')
		*ch_num += set_uint(0, va_arg(*pa, unsigned int), st);
	if (*st->arg == 'p')
		*ch_num += set_p(0, va_arg(*pa, unsigned long long), st);
	if (*st->arg == 'x')
		*ch_num += set_x(0, va_arg(*pa, unsigned long long), st, 0);
	if (*st->arg == 'X')
		*ch_num += set_x(0, va_arg(*pa, unsigned long long), st, 1);
	if (*st->arg == '%')
		*ch_num += set_char(0, '%', st);
}

void		parsfl(va_list *pa, t_st *st)
{
	if (*st->arg == '0' && !(st->flags & F_MN))
		st->flags = st->flags | F_ZR;
	if (ft_isdigit(*st->arg))
		get_digit(st);
	if (*st->arg == '-')
		st->flags = (st->flags & ~F_ZR) | F_MN;
	if (*st->arg == '*')
		get_width(pa, st);
	if (*st->arg == '.')
	get_accuracy(pa, st);
}

int			pars(int *ch_num, va_list *pa, t_st *st)
{
	parsfl(pa, st);
	if (specif_type(*st->arg))
	{
		distrib(ch_num, pa, st);
		str_next(&st->arg);
		return (1);
	}
	if (!str_next(&st->arg))
		return (0);
	if (specif_type(*st->arg))
	{
		distrib(ch_num, pa, st);
		str_next(&st->arg);
		return (1);
	}
	else 
		if (!pars(ch_num, pa, st))
			return (0);
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	pa;
	t_st	st;
	int		ch_num;
	char	*tmp;

	ch_num = 0;
	st.arg = ft_strdup(str);
	tmp = st.arg;
	va_start(pa, str);
	while (wrstr(&st, &ch_num))
	{
		flginit(&st);
		if (!pars(&ch_num, &pa, &st))
		{
			//zr_or_sp(&ch_num, st.width, 0, st.flags & F_ZR);
			break ;
		}
	}
	free(tmp);
	va_end(pa);
	return (ch_num);
}
#include <stdio.h>











// int main()
// {
// 	int		a = -1;int	b = 0;char c = 'a';int	d = 2147483647;int	e = -2147483648;int	f = 42;
// 	int		g = 25;int	h = 4200;int i = 8;int	j = -12;int	k = 123456789;int	l = 0;int	m = -12345678;
// 	char	*n = "abcdefghijklmnop";char *o = "-a";char	*p = "-12";char	*q = "0";char	*r = "%%";
// 	char	*s = "-2147483648";char	*t = "0x12345678";char	*u = "-0";


// 	//    ft_printf("\n|%*d|", 4, -12);

// 	//    printf("\n|%*d|", 4, -12);

// 	//     printf("\n");

// 	   ft_printf("\n|%.*u|", 0, 0 );

// 	   printf("\n|%.*u|",0 , 0  );

// }

	
