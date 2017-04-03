#include "../includes/ft_printf.h"

int			howmanytoprint(t_arg *e);
void		putd(t_arg *e)
{
	int		less;
	int		sign;

	e = d_precision(e);
	sign = (e->sign == -1 || e->more == 1) ? 1 : 0;
	less = (e->right) ? 1 : 0;
	if (e->p <= e->p0 && e->zero == 1 && less == 1)
	{
		e->p = e->p0;
		e->p0 = 0;
	}
	if (less == 0)
		e->res += print_char(' ', e->p - (e->p0 > e->arg_len ? e->p0 : e->arg_len) - sign);
	if (sign == 1)
		e->res += print_sign(e);
	e->res += print_char('0', e->p0 - e->arg_len - ((e->dot == 1) ? 0 : sign));
	e->res += rprint(1, e->ret, e->arg_len);
	if (less == 1)
		e->res += print_char(' ', e->p - (e->p0 > e->arg_len ? e->p0 : e->arg_len) - sign);
}

void		putx(t_arg *e)
{
	int		left;
	int		maj;
	int		sharp;

	if (e->value == 0 && e->dot == 1)
		e->arg_len = 0;
	sharp = (e->sharp == 1) ? 2 : 0;
	maj = (e->type == 'X') ? 1 : 0;
	left = (e->right == 1) ? 1 : 0;
	if (left == 0)
		e->res += print_char(' ', e->p - sharp - (e->p0 > e->arg_len ? e->p0 : e->arg_len));
	if (sharp != 0 && e->value != 0)
		e->res += print_base_prefix(e->base, maj);
	if (left == 0)
		e->res += print_char('0', e->p0 - (sharp + e->arg_len));
	if (e->value != 0 || e->dot == 0)
		e->res += rprint(1, (maj == 1) ? do_upper(e->ret) : e->ret, e->arg_len);
	if (left == 1)
	{
		e->p0 = (e->zero == 1) ? 0 : e->p0;
		e->res += print_char(' ', e->p - sharp - (e->p0 > ft_strlen(e->ret) ? e->p0 : e->arg_len));
	}
}

void		puto(t_arg *e)
{
	int		left;
	int		sharp;

	sharp = (e->sharp == 1) ? 1 : 0;
	if (e->value == 0 && e->dot == 1 && sharp != 1)
		e->arg_len = 0;
	left = (e->right == 1) ? 1 : 0;
	if (left == 1 && !e->dot && e->zero == 1)
	{
		e->p = e->p0;
		e->p0 = 0;
	}
	if (left == 0)
		e->res += print_char(' ', e->p - sharp - (e->p0 > e->arg_len ? e->p0 : e->arg_len));
	if (sharp != 0 && e->value != 0)
		e->res += print_base_prefix(e->base, 0);
	e->res += print_char('0', e->p0 - (sharp + e->arg_len));
	if (!(e->value == 0 && e->dot == 1) || sharp == 1)
		e->res += rprint(1, e->ret, e->arg_len);
	if (left == 1)
		e->res += print_char(' ', e->p - sharp - (e->p0 > ft_strlen(e->ret) ? e->p0 : e->arg_len));
}

void		putst(t_arg *e)
{
	int		left;

	e->res = 0;
	e = str_precision(e);
	left = (e->right == 1) ? 1 : 0;
	if (left == 0)
	{
		e->res += print_char(' ', e->p - e->p0);
		if (e->zero)
			e->res += print_char('0', e->p - e->arg_len);
	}
	e->res += rprint(1, e->ret, e->arg_len);
	if (left == 1)
		e->res += print_char(' ', e->p - ((e->p0 < e->arg_len) ? e->p0 : e->arg_len));
}

void		putch(t_arg *e)
{
	int		left;

	left = (e->right) ? 1 : 0;
	if (e->type == 'c')
		e->wlen = 1;
	if (left == 0)
		e->res += print_char(' ', e->p - (e->p0 > e->wlen ? e->p0 : e->wlen));
	if (left == 0)
		e->res += print_char('0', e->p0 - e->wlen);
	e->res += rprint(1, e->ret, e->wlen);
	if (left == 1)
		e->res += print_char(' ', e->p - (e->p0 > e->wlen ? e->p0 : e->wlen));
}

void		putpercent(t_arg *e)
{
	int		left;

	if (e->dot == 1)
		e->p0 = 0;
	left = (e->right) ? 1 : 0;
	if (left == 0)
		e->res += print_char(' ', e->p - (e->p0 > ft_strlen(e->ret) ? e->p0 : ft_strlen(e->ret)));
	if (left == 0)
		e->res += print_char('0', e->p0 - ft_strlen(e->ret));
	e->res += rprint(1, e->ret, 1);
	if (left == 1)
		e->res +=print_char(' ', e->p - 1);
}

void		putwstr(t_arg *e)
{
	int		left;
	int		i;
	int		size_read;

	size_read = 0;
	i = 0;
	/*
	   left = (e->right) ? 1 : 0;
	   if (left == 0)
	   e->res += print_char(' ', e->p - e->arg_len - e->p0);
	   if (e->zero)
	   e->res += print_char('0', e->p - e->arg_len);
	   while (*(e->ret + i))
	   e->res += rprint(1, e->ret + i++, 1);
	   if (left == 1)
	   e->res += print_char(' ', e->p - e->arg_len - e->p0);
	   */
	e->res = 0;
	e = str_precision(e);
	left = (e->right == 1) ? 1 : 0;
	if (left == 0)
	{
		if (e->p > e->p0)
			e->res += print_char(' ', e->p - ((e->spec != 1) ? howmanytoprint(e) : e->p0));
		if (e->zero)
			e->res += print_char('0', e->p - howmanytoprint(e));
	}
	if (e->spec != 1)
	{
		size_read += wlen(*e->wchar);
		while (*(e->ret + i) && size_read <= e->arg_len)
		{
			rprint(1, e->ret + i, wlen(*e->wchar));
			e->wchar++;
			i = size_read;
			size_read += wlen(*e->wchar);
		}
		e->res += size_read - wlen(*e->wchar);
	}
	else
	{
		while (*(e->ret + i))
			e->res += rprint(1, e->ret + i++, 1);
	}
	if (left == 1)
		e->res += print_char(' ', e->p - ((e->p0 < e->arg_len) ? e->p0 : e->arg_len));
}

int			howmanytoprint(t_arg *e)
{
	int i;
	int j;
	int size_read;

	size_read = 0;
	i = 0;
	j = 0;
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
