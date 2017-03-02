#include "../includes/ft_printf.h"

void		putd(t_arg *tvar)
{
	int		less;

	less = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (less == 0)
		print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
	print_char('0', tvar->p0 - ft_strlen(tvar->ret));
	write(1, tvar->ret, ft_strlen(tvar->ret));
	if (less == 1)
		print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
}

void		putx(t_arg *tvar)
{
	int		left;
	int		maj;
	int		sharp;

	sharp = (ft_strchr(tvar->pref, '#')) ? ((tvar->base == 16) ? 2 : 1) :0;
	maj = (tvar->type == 'X') ? 1 : 0;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		print_char(' ', tvar->p - sharp - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
	if (sharp != 0)
		print_base_prefix(tvar->base, maj);
	print_char('0', tvar->p0 - ft_strlen(tvar->ret));
	write(1, (maj == 1) ? do_upper(tvar->ret) : tvar->ret, ft_strlen(tvar->ret));
	if (left == 1)
		print_char(' ', tvar->p - sharp - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
}

void		putst(t_arg *tvar)
{
	int		left;

	if (tvar->space == 1 && tvar->p0 < ft_strlen(tvar->ret))
		tvar->p0 = ft_strlen(tvar->ret);
	if (tvar->p < tvar->p0)
		tvar->p0 = tvar->p;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
	if (left == 0)
		print_char('0', tvar->p0 - ft_strlen(tvar->ret));
	write(1, tvar->ret, (tvar->p0 >= ft_strlen(tvar->ret)) ? ft_strlen(tvar->ret) : tvar->p0);
	if (left == 1)
		print_char(' ', tvar->p - (tvar->p0 < ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
}

void		putch(t_arg *tvar)
{
	int		left;

	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		print_char(' ', tvar->p - (tvar->p0 > tvar->wlen ? tvar->p0 : tvar->wlen));
	if (left == 0)
		print_char('0', tvar->p0 - tvar->wlen);
	write(1, tvar->ret, tvar->wlen);
	if (left == 1)
		print_char(' ', tvar->p - (tvar->p0 > tvar->wlen ? tvar->p0 : tvar->wlen));
}

void		putpercent(t_arg *tvar)
{
	int		left;

	if (tvar->dot == 1)
		tvar->p0 = 0;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
	if (left == 0)
		print_char('0', tvar->p0 - ft_strlen(tvar->ret));
	write(1, tvar->ret, 1);
	if (left == 1)
		print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
}

void		putwstr(t_arg *tvar)
{
	int		left;

	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		print_char(' ', tvar->p - tvar->wlen);
	write(1, tvar->ret, tvar->wlen);
	if (left == 1)
		print_char(' ', tvar->p - tvar->wlen);
}
