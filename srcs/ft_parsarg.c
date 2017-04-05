/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:00:01 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/29 15:18:23 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
t_arg		*parse_this_arg(t_arg *e, const char *format);

t_arg		parse_args(const char *format, t_arg e)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	e = init_e(e);
	if (*format == '%')
	{
		while (format[j] && !ft_strchr(ARG, format[j]))
			j++;
		e.type = (ft_strchr(ARG, format[j])) ? format[j] : 'e';
		e.argend = (e.type != 'e') ? j : -1;
		(e.argend != -1) ? parse_this_arg(&e, format + i + 1) : 0;
	}
	return (e);
}

t_arg		init_e(t_arg e)
{
	e.h = 0;
	e.hh = 0;
	e.l = 0;
	e.ll = 0;
	e.j = 0;
	e.z = 0;
	e.sign = 0;
	e.dot = 0;
	e.sharp = 0;
	e.space = 0;
	e.zero = 0;
	e.right = 0;
	e.more = 0;
	e.res = 0;
	e.wchar = NULL;
	if (e.ret != NULL)
		free(e.ret);
	e.ret = NULL;
	e.argend = 0;
	return (e);
}

t_arg		*parse_this_arg(t_arg *e, const char *format)
{
	int i;

	i = 0;
	if (e->type == '\0')
	{
		e->type = 'e';
		return (NULL);
	}
	init_pflag(e, format);
	init_precision(e, format);
	init_flag(e, format);
	if (ft_strchr("DUO", e->type))
	{
		e->type = e->type - 'A' + 'a';
		e->l = 1;
	}
	if (ft_strchr("cs", e->type) && e->l == 1)
		e->type = e->type - 'a' + 'A';
	if (ft_strchr("diuU", e->type))
	{
		e->base = 10;
	}
	else if (ft_strchr("pxX", e->type))
		e->base = 16;
	else if (ft_strchr("o", e->type))
		e->base = 8;
	else
		e->base = 0;
	return (e);
}

t_arg		*init_precision(t_arg *e, const char *format)
{
	e->p0 = -1;
	e->p = -1;
	if (ft_strchr(ARG, *format))
		return (e);
	while (*format && !ft_strchr("123456789.", *format))
		format++;
	e->p = ft_atoi(format);
	while (*format && *format != '.' && !ft_strchr("sSpdDioOuUxXcChljzZ%.", *format))
		format++;
	if (*format == '.')
	{
		e->dot = 1;
		format++;
	}
	e->p0 = ft_atoi(format);
	if (e->p0 == 0 && e->p != 0 && e->zero == 1)
		e->p0 = e->p;
	return(e);
}

t_arg		*init_flag(t_arg *e, const char *format)
{
	while (*format && !ft_strchr(ARG, *format))
	{
		if (*format == 'l' && *(format + 1) != 'l')
			e->l = 1;
		if (*format == 'l' && *(format + 1) == 'l')
			e->ll = 1;
		if (*format == 'h' && *(format + 1) != 'h')
			e->h = 1;
		if (*format == 'h' && *(format + 1) == 'h')
			e->hh = 1;
		if (*format == 'j')
			e->j = 1;
		if (*format == 'z')
			e->z = 1;
		format++;
	}
	return (e);
}

