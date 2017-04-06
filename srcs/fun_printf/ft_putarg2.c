/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:04:53 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:16:18 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_arg		left_0(t_arg e, int *i);

t_arg		putpercent(t_arg e)
{
	int	left;

	if (e.dot == 1)
		e.p0 = 0;
	if (e.zero)
		e.p0 = e.p;
	left = (e.right) ? 1 : 0;
	if (left == 0)
		e.res += print_char(' ', e.p -
				(e.p0 > ft_strlen(e.ret) ? e.p0 : ft_strlen(e.ret)));
	if (left == 0)
		e.res += print_char('0', e.p0 - ft_strlen(e.ret));
	e.res += rprint(1, e.ret, 1);
	if (left == 1)
		e.res += print_char(' ', e.p - 1);
	return (e);
}

t_arg		putwstr(t_arg e)
{
	int	left;
	int	i;
	int	size_read;

	size_read = 0;
	i = 0;
	e.res = 0;
	str_precision(&e);
	left = (e.right == 1) ? 1 : 0;
	if (e.zero && e.dot && e.p)
		e.p0 = 0;
	if (left == 0)
		e = left_0(e, &i);
	else
	{
		while (*(e.ret + i))
			e.res += rprint(1, e.ret + i++, 1);
	}
	if (left == 1)
		e.res += print_char(' ', e.p -
				((e.p0 < e.arg_len) ? e.p0 : e.arg_len));
	return (e);
}

int			howmanytoprint(t_arg *e)
{
	int i;
	int j;
	int size_read;

	size_read = 0;
	i = 0;
	j = 0;
	if (!e->p0)
	{
		e->arg_len = 0;
		return (0);
	}
	if (e->p0 != 0 && e->p0 < e->arg_len)
		e->arg_len = e->p0;
	size_read += wlen(*e->wchar);
	while (*(e->ret + i) && size_read <= e->arg_len)
	{
		j++;
		i = size_read;
		size_read += wlen(*e->wchar + j);
	}
	return (size_read - wlen(*e->wchar));
}

t_arg		putp(t_arg e)
{
	int	left;
	int	sharp;

	sharp = (e.sharp == 1) ? 2 : 0;
	left = (e.right == 1) ? 1 : 0;
	if (left == 0)
		e.res += print_char(' ', e.p - sharp -
				(e.p0 > e.arg_len ? e.p0 : e.arg_len));
	if (sharp != 0 && e.value != 0)
		e.res += print_base_prefix(e.base, 0);
	if (left == 0)
		e.res += print_char('0', e.p0 -
				e.arg_len - ((e.zero == 1) ? sharp : 0));
	if (e.value != 0 || e.dot == 0)
		e.res += rprint(1, e.ret, e.arg_len);
	if (left == 1)
	{
		e.p0 = (e.zero == 1) ? 0 : e.p0;
		e.res += print_char(' ', e.p - 2
				- (e.p0 > ft_strlen(e.ret) ? e.p0 : e.arg_len));
	}
	return (e);
}

t_arg		left_0(t_arg e, int *i)
{
	int size_read;

	size_read = 0;
	if (e.p > e.p0 && !e.zero)
		e.res += print_char(' ', e.p -
				((e.spec != 1) ? howmanytoprint(&e) : e.p0));
	if (e.zero)
		e.res += print_char('0', e.p - howmanytoprint(&e));
	if (e.spec != 1)
	{
		size_read += wlen(*e.wchar);
		while (*(e.ret + *i) && size_read <= e.arg_len)
		{
			rprint(1, e.ret + *i, wlen(*e.wchar));
			e.wchar++;
			*i = size_read;
			size_read += wlen(*e.wchar);
		}
		e.res += size_read - wlen(*e.wchar);
	}
	return (e);
}
