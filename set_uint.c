/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:18:26 by ehande            #+#    #+#             */
/*   Updated: 2021/01/07 20:00:39 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		string_size(unsigned int n)
{
	size_t i;

	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*int_to_string(char *str, unsigned int n, size_t len)
{
	str[len] = '\0';
	while (n)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char		*ft_utoa(unsigned int n)
{
	char	*result;
	size_t	string_s;

	if (n == 0)
		return (ft_strdup("0"));
	string_s = string_size(n);
	result = (char *)malloc(sizeof(char) * string_s + 1);
	if (result == NULL)
		return (NULL);
	result = int_to_string(result, n, string_s);
	return (result);
}

void		udistrb_mn(int *ch_num, t_st *st)
{
	if (st->flags & F_MN)
		wr(0, ch_num, st);
	if (st->flags & F_AC && !st->acrcy)
		zero_acrcy(ch_num, st);
	else if (st->flags & F_AC)
	{
		if (st->acrcy < 0 ||
				((size_t)st->acrcy < ft_strlen(st->str) && st->acrcy >= 0))
			st->acrcy = ft_strlen(st->str);
		zr_or_sp(ch_num, st->width, st->acrcy, st->flags & F_ZR);
	}
	else
		zr_or_sp(ch_num, st->width, ft_strlen(st->str), st->flags & F_ZR);
	if (!(st->flags & F_MN))
		wr(0, ch_num, st);
}

int			set_uint(int ch_num, unsigned int set_i, t_st *st)
{
	st->dig = set_i;
	st->str = ft_utoa(set_i);
	udistrb_mn(&ch_num, st);
	free(st->str);
	st->str = NULL;
	return (ch_num);
}
