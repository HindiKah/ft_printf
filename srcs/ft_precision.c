#include "../includes/ft_printf.h"

t_arg		*str_precision(t_arg *e)
{
	if (e->p0 == 0 && e->dot == 0)
		e->p0 = e->arg_len;
	if (e->p0 > e->arg_len && e->p > e->p0 && e->arg_len == 0)
		e->p0 = 0;
	e->arg_len = (e->p0 < e->arg_len && e->p0 != 0) ? e->p0 : e->arg_len;
	return (e);
}
