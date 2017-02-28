/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:00:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/14 21:57:18 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*	
int i = 0;
	while (i < ft_countparams(format))
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

	tvar = (t_arg*)malloc(sizeof(t_arg) * ft_countparams(format) + 1);
	i = 0;
	j = 0;
	i_tvar = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			tvar[i_tvar].index = i;
			while (format[j] && !ft_strchr("sSpdDioOuUxXcC%", format[j]))
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
	tvar[i_tvar].type = 'e';
	return (tvar);
}

t_arg		*parse_this_arg(t_arg *tvar, const char *format)
{
	int i;

	i = 0;
	if (tvar->type == '\0')
		return (NULL);
	init_pflag(tvar, format);
	while (*format && !ft_strchr(" 0123456789ljzhsSpdDioOuUxXcC%.", *format))
		format++;
	if (!*format)
		return (NULL);
	init_precision(tvar, format);
	while (*format && ft_strchr(" 0123456789.", *format))
			format++;
	init_flag(tvar, format);
	if (ft_strchr("diu", tvar->type))
		tvar->base = 10;
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
	int space;

	tvar->p0 = -1;
	tvar->p = -1;
	tvar->p = 0;
	space = (*format == ' ') ? 1 : 0;
	if ((format = whatisnext_c(format, ' '))[0] == '0')
		tvar->space = 1;
	tvar->p = ft_atoi(format);
	while (*format && *format != '.' && !ft_strchr("sSpdDioOuUxXcChljz%.", *format))
		format++;
	if (*format == '.')
	{
		tvar->dot = 1;
		format++;
	}
	tvar->p0 = ft_atoi(format);
	return(tvar);
}

t_arg		*treat_precision(t_arg *tvar, int dot, int p0,  int space)
{
	tvar->p0 = (tvar->p0 == 0 && dot == 0 && p0 == 1) ? tvar->p : tvar->p0;
	tvar->p = (tvar->p < tvar->p0 && space == 0) ? tvar->p0 : tvar->p;
	return(tvar);
}

t_arg		*init_flag(t_arg *tvar, const char *format)
{
	if (*format + 2)
	{
		tvar->flag = (ft_strchr("hljz",  *format)) ? *format : '0';
		if ((tvar->flag == 'h' || tvar->flag == 'l') && tvar->flag == format[1])
			tvar->flag = ft_toupper(tvar->flag);
	}
	else
		tvar->flag = '0';
	return (tvar);
}

