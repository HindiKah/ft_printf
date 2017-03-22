#include "../includes/ft_printf.h"

t_arg		*str_precision(t_arg *tvar)
{
	if (tvar->p0 == 0 && tvar->dot == 0)
		tvar->p0 = tvar->arg_len;
	if (tvar->p0 > tvar->arg_len && tvar->p > tvar->p0 && tvar->arg_len == 0)
		tvar->p0 = 0;
	return (tvar);
}
