#include "../includes/ft_printf.h"

t_arg		*str_precision(t_arg *e)
{
	if (e->p < e->p0 && e->p0 > e->arg_len && e->dot != 1)
		e->p0 = e->arg_len;
	if ((e->p0 == 0 && e->dot == 0) || (e->p0 > e->arg_len && e->p > e->p0))
		e->p0 = e->arg_len;
	if (e->p0 > e->arg_len && e->p > e->p0 && e->arg_len == 0)
		e->p0 = 0;
	e->arg_len = (e->p0 < e->arg_len && e->p0 != 0) ? e->p0 : e->arg_len;
	if (e->dot == 1 && e->p0 == 0)
		e->arg_len = 0;
	if (e->p0 > e->arg_len && e->p < e->p0)
		e->p0 = e->arg_len;
	return (e);
}

t_arg		*d_precision(t_arg *e)
{
	e->arg_len = (!e->value && e->dot) ? 0 : e->arg_len;
	if (e->p <= 0 && e->p0 <= 0 && e->space == 1)
		e->p = 1 + e->arg_len;
	if (e->p == e->p0 && e->space == 1)
		e->p0 -= 1;
	return (e);
}
