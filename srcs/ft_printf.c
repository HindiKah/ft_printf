/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:12:48 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/14 21:50:55 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		final_print(const char *format, t_arg *tvar, va_list all_arg);
size_t		ft_arglen(t_arg *tvar);
int			testprint(t_arg tvar);
int			printf_result(const char *format, t_arg *tvar);

int			ft_printf(const char *format, ...)
{
	va_list		all_arg;
	t_func		*my_func;
	t_funf		*my_funf;
	t_arg		*tvar;
	int			ret;

	tvar = (t_arg*)malloc(sizeof(t_arg) * ft_countparams(format));
	my_func = NULL;
	my_funf = NULL;
	va_start(all_arg, format);
	my_func = ft_init_func(my_func);
	my_funf = ft_init_funf(my_funf);
	tvar = parse_args(tvar, format);
	ft_do_all_fun(my_funf, my_func, all_arg, tvar);

/*
	int i = 0;
	while (i < ft_countparams(format))
	{
		printf("\nFT_PRINTF\nstruct s_arg:\n{\n\tindex = %d\n\tflag = %c\n\ttype= %c\n\tpref= %s\n\tprecision= %d\n\tprecision2= %d\n\ti_end= %d\n\tbase = %d\n\tSign = %d\n\tvalue = %d\n\tdot = %d\n\targend = %d\n\twlen = %d\n\tstr = %d\n\tRET = |%s|\n}\n\n", tvar[i].index, tvar[i].flag, tvar[i].type, tvar[i].pref, tvar[i].p, tvar[i].p0, tvar[i].argend, tvar[i].base,tvar[i].sign,tvar[i].value, tvar[i].dot, tvar[i].argend, tvar[i].wlen, tvar[i].str, tvar[i].ret);
		i++;
	}
*/

	ret = (tvar[0].type != 'e') ?  printf_result(format, tvar) : ft_strlen(format);;
	final_print(format, tvar, all_arg);
	free(my_func);
	free(my_funf);
	if (tvar != NULL)
		free(tvar);
	va_end(all_arg);

	return (ret);
}

void		final_print(const char *format, t_arg *tvar, va_list all_arg)
{
	int		i;
	int		k;
	int		j;
	int		tmp;

	tmp = 0;
	j = 0;
	k = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && tvar[k].type != 'e')
		{
			i++;
			write(1, format + tmp, j);
			if (ft_strchr("cCS", tvar[k].type))
					write(1, tvar[k].ret, tvar[k].wlen);
			else if (testprint(tvar[k]) == 1)
				write(1, tvar[k].ret, ft_strlen(tvar[k].ret));
			i = tvar[k].argend;
			tmp = i + 1;
			j = 0;
			k++;
		}
		else
			j++;
		i++;
	}
	if (format[tmp])
		write(1, format + tmp, j);
}

size_t			ft_arglen(t_arg *tvar)
{
	int		i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (tvar[i].type != 'e')
	{
	}
	return (ret);
}

int			testprint(t_arg tvar)
{
	int ret;

	ret = ((ft_strchr("xXo", tvar.type) && tvar.value == 0 && 
				tvar.p == 0 && tvar.p0 == 0 && tvar.dot == 1) || (ft_strchr("di", tvar.type) && tvar.value == 0 && tvar.p == 0 && tvar.p0 == 0 && tvar.dot == 0)) ? 0 : 1;
	return (ret);
}

int			printf_result(const char *format, t_arg *tvar)
{
	int		i;
	int		k;
	int		ret;

	k = 0;
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (i == tvar[k].index)
		{
			if (ft_strchr("cCS", tvar[k].type))
				ret += tvar[k].wlen;
				else
			ret += ft_strlen(tvar[k].ret);
			i = tvar[k].argend;
			k++;
		}
		else
			ret++;
		i++;
	}
	return (ret);
}
