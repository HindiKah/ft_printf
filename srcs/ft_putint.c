#include "../includes/ft_printf.h"

void		putd(t_arg *tvar)
{
	int		less;
	int		sign;

	tvar->arg_len = (!tvar->value && tvar->dot) ? 0 : tvar->arg_len;
	if (tvar->p <= 0 && tvar->p0 <= 0 && tvar->space == 1)
		tvar->p = 1 + tvar->arg_len;
	sign = (tvar->sign == -1 || ft_strchr(tvar->pref, '+')) ? 1 : 0;
	less = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (tvar->p <= tvar->p0 && ft_strchr(tvar->pref, '0') && less == 1)
	{
		tvar->p = tvar->p0;
		tvar->p0 = 0;
	}
	if (less == 0)
		tvar->res += print_char(' ', tvar->p - (tvar->p0 > tvar->arg_len ? tvar->p0 : tvar->arg_len) - sign);
	if (sign == 1)
		tvar->res += print_sign(tvar);
	tvar->res += print_char('0', tvar->p0 - tvar->arg_len - ((tvar->dot == 1) ? 0 : sign));
	tvar->res += rprint(1, tvar->ret, tvar->arg_len);
	if (less == 1)
		tvar->res += print_char(' ', tvar->p - (tvar->p0 > tvar->arg_len ? tvar->p0 : tvar->arg_len) - sign);
}

void		putx(t_arg *tvar)
{
	int		left;
	int		maj;
	int		sharp;

	if (tvar->value == 0 && tvar->dot == 1)
		tvar->arg_len = 0;
	sharp = (ft_strchr(tvar->pref, '#')) ? 2 : 0;
	maj = (tvar->type == 'X') ? 1 : 0;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - sharp - (tvar->p0 > tvar->arg_len ? tvar->p0 : tvar->arg_len));
	if (sharp != 0 && tvar->value != 0)
		tvar->res += print_base_prefix(tvar->base, maj);
	if (left == 0 && tvar->dot == 0)
		tvar->res += print_char('0', tvar->p0 - (sharp + tvar->arg_len));
	if (tvar->value != 0 || tvar->dot == 0)
		tvar->res += rprint(1, (maj == 1) ? do_upper(tvar->ret) : tvar->ret, tvar->arg_len);
	if (left == 1)
	{
		tvar->p0 = (ft_strchr(tvar->pref, '0')) ? 0 : tvar->p0;
		tvar->res += print_char(' ', tvar->p - sharp - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : tvar->arg_len));
	}
}

void		puto(t_arg *tvar)
{
	int		left;
	int		sharp;

	sharp = (ft_strchr(tvar->pref, '#')) ? 1 : 0;
	if (tvar->value == 0 && tvar->dot == 1 && sharp != 1)
		tvar->arg_len = 0;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 1 && !tvar->dot && ft_strchr(tvar->pref, '0'))
	{
		tvar->p = tvar->p0;
		tvar->p0 = 0;
	}
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - sharp - (tvar->p0 > tvar->arg_len ? tvar->p0 : tvar->arg_len));
	if (sharp != 0 && tvar->value != 0)
		tvar->res += print_base_prefix(tvar->base, 0);
		tvar->res += print_char('0', tvar->p0 - (sharp + tvar->arg_len));
	if (!(tvar->value == 0 && tvar->dot == 1) || sharp == 1)
		tvar->res += rprint(1, tvar->ret, tvar->arg_len);
	if (left == 1)
		tvar->res += print_char(' ', tvar->p - sharp - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : tvar->arg_len));
}

void		putst(t_arg *tvar)
{
	int		left;

	tvar->res = 0;
	str_precision(tvar);
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - tvar->p0);
	tvar->res += rprint(1, tvar->ret, (tvar->p0 >= tvar->arg_len) ? tvar->arg_len : tvar->p0);
	if (left == 1)
		tvar->res += print_char(' ', tvar->p - ((tvar->p0 < tvar->arg_len) ? tvar->p0 : tvar->arg_len));
}

void		putch(t_arg *tvar)
{
	int		left;

	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - (tvar->p0 > tvar->wlen ? tvar->p0 : tvar->wlen));
	if (left == 0 && tvar->ret[0])
		tvar->res += print_char('0', tvar->p0 - tvar->wlen);
	tvar->res += rprint(1, tvar->ret, tvar->wlen);
	if (left == 1)
		tvar->res += print_char(' ', tvar->p - (tvar->p0 > tvar->wlen ? tvar->p0 : tvar->wlen));
}

void		putpercent(t_arg *tvar)
{
	int		left;

	if (tvar->dot == 1)
		tvar->p0 = 0;
	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
	if (left == 0)
		tvar->res += print_char('0', tvar->p0 - ft_strlen(tvar->ret));
	tvar->res += rprint(1, tvar->ret, 1);
	if (left == 1)
		tvar->res +=print_char(' ', tvar->p - (tvar->p0 > ft_strlen(tvar->ret) ? tvar->p0 : ft_strlen(tvar->ret)));
}

void		putwstr(t_arg *tvar)
{
	int		left;

	left = (ft_strchr(tvar->pref, '-')) ? 1 : 0;
	if (left == 0)
		tvar->res += print_char(' ', tvar->p - tvar->wlen);
	tvar->res += rprint(1, tvar->ret, tvar->wlen);
	if (left == 1)
		tvar->res += print_char(' ', tvar->p - tvar->wlen);
}
