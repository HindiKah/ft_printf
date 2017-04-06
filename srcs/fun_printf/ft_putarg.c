/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:30:56 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:08:17 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_arg		putd(t_arg e)
{
	int		less;
	int		sign;

	d_precision(&e);
	sign = (e.sign == -1 || e.more == 1) ? 1 : 0;
	less = (e.right) ? 1 : 0;
	if (e.p <= e.p0 && e.zero == 1 && less == 1)
	{
		e.p = e.p0;
		e.p0 = 0;
	}
	if (less == 0)
		e.res += print_char(' ', e.p -
				(e.p0 > e.arg_len ? e.p0 : e.arg_len) - sign);
	if (sign == 1)
		e.res += print_sign(&e);
	e.res += print_char('0', e.p0 - e.arg_len - ((e.dot == 1) ? 0 : sign));
	e.res += rprint(1, e.ret, e.arg_len);
	if (less == 1)
		e.res += print_char(' ', e.p -
				(e.p0 > e.arg_len ? e.p0 : e.arg_len) - sign);
	return (e);
}

t_arg		putx(t_arg e)
{
	int		left;
	int		maj;
	int		sharp;

	e.arg_len = (e.value == 0 && e.dot == 1) ? 0 : e.arg_len;
	sharp = (e.sharp == 1) ? 2 : 0;
	maj = (e.type == 'X') ? 1 : 0;
	left = (e.right == 1) ? 1 : 0;
	e.p0 += (!e.p && e.dot && e.sharp) ? 2 : 0;
	if (!left)
		e.res += print_char(' ', e.p -
			sharp - (e.p0 > e.arg_len ? e.p0 : e.arg_len));
	if (sharp != 0 && e.value != 0)
		e.res += print_base_prefix(e.base, maj);
	if (left == 0)
		e.res += print_char('0', e.p0 - (sharp + e.arg_len));
	if (e.value != 0 || e.dot == 0)
		e.res += rprint(1, (maj == 1) ? do_upper(e.ret) : e.ret, e.arg_len);
	if (left == 1)
	{
		e.p0 = (e.zero == 1) ? 0 : e.p0;
		e.res += print_char(' ', e.p - sharp -
				(e.p0 > ft_strlen(e.ret) ? e.p0 : e.arg_len));
	}
	return (e);
}

t_arg		puto(t_arg e)
{
	int		left;
	int		sharp;

	sharp = (e.sharp == 1) ? 1 : 0;
	if (e.value == 0 && e.dot == 1 && sharp != 1)
		e.arg_len = 0;
	left = (e.right == 1) ? 1 : 0;
	if (left == 1 && !e.dot && e.zero == 1)
	{
		e.p = e.p0;
		e.p0 = 0;
	}
	if (left == 0)
		e.res += print_char(' ', e.p - sharp -
				(e.p0 > e.arg_len ? e.p0 : e.arg_len));
	if (sharp != 0 && e.value != 0)
		e.res += print_base_prefix(e.base, 0);
	e.res += print_char('0', e.p0 - (sharp + e.arg_len));
	if (!(e.value == 0 && e.dot == 1) || sharp == 1)
		e.res += rprint(1, e.ret, e.arg_len);
	if (left == 1)
		e.res += print_char(' ', e.p - sharp -
				(e.p0 > ft_strlen(e.ret) ? e.p0 : e.arg_len));
	return (e);
}

t_arg		putst(t_arg e)
{
	int		left;

	e.res = 0;
	str_precision(&e);
	left = (e.right == 1) ? 1 : 0;
	if (left == 0)
	{
		e.res += print_char(' ', e.p - e.p0);
		if (e.zero)
			e.res += print_char('0', e.p - e.arg_len);
	}
	e.res += rprint(1, e.ret, e.arg_len);
	if (left == 1)
		e.res += print_char(' ', e.p -
				((e.p0 < e.arg_len) ? e.p0 : e.arg_len));
	return (e);
}

t_arg		putch(t_arg e)
{
	int		left;

	left = (e.right) ? 1 : 0;
	if (e.zero && e.p0 < e.p)
		e.p0 = e.p;
	if (e.type == 'c')
		e.wlen = 1;
	if (left == 0)
		e.res += print_char(' ', e.p - (e.p0 > e.wlen ? e.p0 : e.wlen));
	if (left == 0)
		e.res += print_char('0', e.p0 - e.wlen);
	e.res += rprint(1, e.ret, e.wlen);
	if (left == 1)
		e.res += print_char(' ', e.p - (e.p0 > e.wlen ? e.p0 : e.wlen));
	return (e);
}
