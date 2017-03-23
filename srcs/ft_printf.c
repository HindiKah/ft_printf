/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:12:48 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/22 17:11:09 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			final_print(const char *format, t_arg *tvar, va_list all_arg, t_func *my_func);

int			ft_printf(const char *format, ...)
{
	va_list		all_arg;
	t_func		*my_func;
	t_funf		*my_funf;
	t_arg		*tvar;
	int			ret;

	tvar = (t_arg*)malloc(sizeof(t_arg) * ft_countparams(format));
	if (!tvar)
		return(0);
	my_func = NULL;
	my_funf = NULL;
	va_start(all_arg, format);
	my_func = ft_init_func(my_func);
	my_funf = ft_init_funf(my_funf);
	tvar = parse_args(tvar, format);
	ft_do_all_fun(my_funf, my_func, all_arg, tvar);
	ret = final_print(format, tvar, all_arg, my_func);
/*
	   int i = 0;
	   while (i < ft_countparams(format))
	   {
	   printf("\nFT_PRINTF\nstruct s_arg:\n{\n\tindex = %d\n\tflag = %c\n\ttype= %c\n\tpref= %s\n\tprecision= %d\n\tprecision2= %d\n\tspace= %d\n\tbase = %d\n\tSign = %d\n\tvalue = %d\n\tdot = %d\n\targend = %d\n\twlen = %d\n\tstr = %d\n\tRET = |%s|\n}\n\n", tvar[i].index, tvar[i].flag, tvar[i].type, tvar[i].pref, tvar[i].p, tvar[i].p0, tvar[i].space, tvar[i].base,tvar[i].sign,tvar[i].value, tvar[i].dot, tvar[i].argend, tvar[i].wlen, tvar[i].res, tvar[i].ret);
	   i++;
	   }
*/
	va_end(all_arg);
	free(my_func);
	free(my_funf);
	free(tvar);
	return (ret);
}

int			final_print(const char *format, t_arg *tvar, va_list all_arg, t_func *my_func)
{
	int		i;
	int		ret;
	int		j;
	int		tmp;

	tmp = 0;
	j = 0;
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (i == tvar->index && tvar->type != 'e')
		{
			ret += rprint(1, format + tmp, j);
			print_arg(tvar, my_func);
			ret += tvar->res;
			i = tvar->argend;
			tmp = i;
			j = 0;
			tvar++;
		}
		else
		{
			j++;
			i++;
		}
	}
	while (format[tmp] && format[tmp] != '%')
		ret += rprint(1, format + tmp++, 1);
	return (ret);
}
