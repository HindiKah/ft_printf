/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:00:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/22 17:13:35 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*	
	i = 0;
	while (i < nb_param + 1)
	{
	printf("\nFT_PRINTF\nstruct s_arg:\n{\n\tindex = %d\n\tflag = %c\n\ttype= %c\n\tpref= %s\n\tprecision= %d\n\tprecision2= %d\n\ti_end= %d\n\tbase = %d\n\tSign = %d\n\tvalue = %d\n\tdot = %d\n\targend = %d\n\twlen = %d\n\tRET = |%s|\n}\n\n", tvar[i].index, tvar[i].flag, tvar[i].type, tvar[i].pref, tvar[i].p, tvar[i].p0, tvar[i].argend, tvar[i].base,tvar[i].sign,tvar[i].value, tvar[i].dot, tvar[i].argend, tvar[i].wlen, tvar[i].ret);
	i++;
	}
	*/
t_arg		*parse_this_arg(t_arg *tvar, const char *format);

t_arg		*parse_args(t_arg *tvar, const char *format)
{
	int		i;
	int		j;
	int		i_tvar;
	int		nb_param;

	nb_param = ft_countparams(format);
	tvar = (t_arg*)malloc(sizeof(t_arg) * (nb_param + 1));
	i = 0;
	j = 0;
	i_tvar = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			tvar[i_tvar].index = i;
			while (format[j] && !ft_strchr("sSpdDioOuUxXcC%Z", format[j]))
				j++;
			tvar[i_tvar].type = format[j];
			tvar[i_tvar].argend = j + 1;
			tvar[i_tvar].index = i;
			parse_this_arg(&tvar[i_tvar], format + i + 1);
			tvar[i_tvar].truearg = 1;
			i = (tvar[i_tvar].type == '%') ? j + 1 : j;
			i_tvar++;
		}
		i++;
	}
	tvar[nb_param].type = 'e';
	return (tvar);
}

t_arg		*parse_this_arg(t_arg *tvar, const char *format)
{
	int i;

	i = 0;
	if (tvar->type == '\0')
	{
		tvar->type = 'e';
		return (NULL);
	}
	init_pflag(tvar, format);
	while (*format && ft_strchr("+0-#", *format))
		format++;
	if (!*format)
		return (NULL);
	init_precision(tvar, format);
	while (*format && ft_strchr(" 0123456789.", *format))
		format++;
	init_flag(tvar, format);
	if (ft_strchr("diuU", tvar->type))
	{
		if (tvar->type == 'U')
		{
			tvar->type = 'u';
			tvar->flag = 'l';
		}
		tvar->base = 10;
	}
	else if (ft_strchr("pxX", tvar->type))
		tvar->base = 16;
	else if (ft_strchr("o", tvar->type))
		tvar->base = 8;
	else
		tvar->base = 0;
	return (tvar);
}

t_arg		*init_precision(t_arg *tvar, const char *format)
{
	tvar->p0 = -1;
	tvar->p = -1;
	tvar->p = 0;
	tvar->space = (*format == ' ') ? 1 : 0;
	while (*format && !ft_strchr("123456789", *format))
		format++;
	tvar->p = ft_atoi(format);
	while (*format && *format != '.' && !ft_strchr("sSpdDioOuUxXcChljzZ%.", *format))
		format++;
	if (*format == '.')
	{
		tvar->dot = 1;
		format++;
	}
	tvar->p0 = ft_atoi(format);
	if (tvar->p0 == 0 && tvar->p != 0 && ft_strchr(tvar->pref, '0'))
		tvar->p0 = tvar->p;
	return(tvar);
}

t_arg		*init_flag(t_arg *tvar, const char *format)
{
	while (*format && ft_strchr("hljz", *format))
	{
		if (*format + 2)
		{
			tvar->flag = (ft_strchr("hljz",  *format)) ? *format : '0';
			if ((tvar->flag == 'h' || tvar->flag == 'l') && tvar->flag == format[1])
				tvar->flag = ft_toupper(tvar->flag);
		}
		else
			tvar->flag = '0';
		format++;
	}
	return (tvar);
}

