/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:25:27 by ehande            #+#    #+#             */
/*   Updated: 2021/01/05 09:31:04 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define F_NONE	0b00000000
# define F_ST	0b00000001
# define F_MN	0b00000010
# define F_ZR	0b00000100
# define F_WP	0b00001000
# define F_NG	0b00010000
# define F_PR	0b00100000
# define F_AC	0b01000000
# define F_ER	0b10000000
# define NN     "(null)"
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_st
{
	char			flags;
	char			*arg;
	char			*str;
	int				dig;
	int				acrcy;
	int				width;
}					t_st;
void				mn(int *ch_num, t_st *st);
int					str_next(char **s);
int					wrstr(t_st *st, int *ch_num);
char				*chang_notation(int i, unsigned long long input, int sist);
int					set_p(int i, unsigned long long ull, t_st *st);
int					set_x(int ch_num, unsigned int set_i, t_st *st, int x);
int					set_uint(int ch_num, unsigned int set_i, t_st *st);
void				zr_or_sp(int *ch_num, int width, int str_len, int spzr);
void				wr(size_t i, int *ch_num, t_st *st);
int					set_str(int ch_num, char *str, t_st *st);
int					set_char(int ch_num, char c, t_st *st);
int					specif_type(int c);
int					is_flag(int c);
void				get_digit(t_st *st);
int					get_accuracy(va_list *pa, t_st *st);
void				get_width(va_list *pa, t_st *st);
int					ft_printf(const char *str, ...);
int					putchar_next(char ch, int *ch_num);
int					set_int(int ch_num,  int set_i, t_st *st);
#endif
