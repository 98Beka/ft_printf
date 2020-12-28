/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:23:39 by ehande            #+#    #+#             */
/*   Updated: 2020/12/22 14:23:50 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int distrib(int ch_num, va_list *pa, t_st *st, int *i)
{
    if(st->arg[*i] == 'd' || st->arg[*i] == 'i')
        ch_num += set_int(0, va_arg(*pa, int), st);
    if(st->arg[*i] == 'c')
        ch_num += set_char(0, va_arg(*pa, int), st);
    return(ch_num);
}
int pars(int ch_num, int i, va_list *pa, t_st *st)
{
    if(st->arg[i] == '%' && st->arg[i + 1])
       while(st->arg[i++])
       {   
        if (st->arg[i] == '0' && !(st->flags & F_MN) )
			st->flags = st->flags | F_ZR; 
        if (st->arg[i] == '-')
			st->flags = (st->flags | F_MN) & ~F_ZR; 
       if (st->arg[i] == '*')
			get_width(pa, st);
		if (st->arg[i] == '.')
			get_accuracy(pa, st, &i);
        if (ft_isdigit(st->arg[i]))
            get_digit(st, st->arg[i]);
		if (specif_type(st->arg[i]))
		{
            st->spcr = st->arg[i];
            ch_num += distrib(0, pa, st, &i);	
		}
        else if (st->arg[i] && !is_flag(st->arg[i]))
        ch_num +=putch(st->arg[i]);
       }
    return(ch_num);
}

int     ft_printf(const char *str, ...)
{
    va_list pa;
    t_st st;
    int ch_num;

    ch_num = 0;
    st.flags = F_NONE;
    st.str = NULL;
    st.dig = 0; 
    st.width = 0;
    st.accuracy = 0;
    st.arg = ft_strdup(str);
    va_start(pa, str);
    while(*st.arg != '%' && *st.arg)
       ch_num += putchar_next(&st.arg);
    ch_num += pars(0, 0, &pa, &st);
    va_end(pa);
    return(ch_num);
}

#include <stdio.h>
int main()
{
    ft_printf("%.*d",9,3);
    printf("\n%.*f",-90,3.5599);
    return (0);
}

