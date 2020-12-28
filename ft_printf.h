/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:25:27 by ehande            #+#    #+#             */
/*   Updated: 2020/12/28 11:04:56 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define F_NONE	0b00000000
# define F_ST	0b00000001
# define F_MN	0b00000010
# define F_ZR	0b00000100
# define F_WP	0b00001000
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_st
{
    char    flags;
    char    *arg;
    char    *str;
    int     dig;
    int     accuracy;
    int     width;
    char    spcr;
}           t_st;
int		            set_char(int ch_num, char c, t_st *st);
int                 specif_type(int c);
int                 is_flag(int c);
void                get_digit(t_st *st, char ch);
void                get_accuracy(va_list *pa, t_st *st, int *i);
void                get_width(va_list *pa, t_st *st);
int					ft_printf(const char *str, ...);
int                 putchar_next(char **str);
int                 putch(char ch);
int                 set_int(int ch_num, int set_i, t_st *st);

#endif
