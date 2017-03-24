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
t_arg		*parse_this_arg(t_arg *e, const char *format);

t_arg		*parse_args(t_arg *e, const char *format)
{
	int		i;
	int		j;
	int		i_e;

	e = init_e(e, ft_countparams(format));
	i = 0;
	j = 0;
	i_e = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			e[i_e].index = i;
			while (format[j] && !ft_strchr(ARG, format[j]))
				j++;
			e[i_e].type = format[j];
			e[i_e].argend = j + 1;
			e[i_e].index = i;
			parse_this_arg(&e[i_e], format + i + 1);
			i = (e[i_e].type == '%') ? j + 1 : j;
			i_e++;
		}
		i++;
	}
	e[i_e].type = 'e';
	return (e);
}

t_arg		*init_e(t_arg *e, int n)
{
	int		e_i;

	e_i = 0;
	e = (t_arg*)malloc(sizeof(t_arg) * (n + 1));
	while (e_i++ < n)
	{
		e[e_i].h = 0;
		e[e_i].hh = 0;
		e[e_i].l = 0;
		e[e_i].ll = 0;
		e[e_i].j = 0;
		e[e_i].z = 0;
		e[e_i].sharp = 0;
		e[e_i].space = 0;
		e[e_i].zero = 0;
		e[e_i].right = 0;
		e[e_i].more = 0;
	}
	e[e_i].type = 'e';
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
	//while (*format && ft_strchr("+0-#", *format))
	//	format++;
	//if (!*format)
	//	return (NULL);
	init_precision(e, format);
	//while (*format && ft_strchr(" 0123456789.", *format))
	//	format++;
	init_flag(e, format);
	if (ft_strchr("diuU", e->type))
	{
		if (e->type == 'U')
		{
			e->type = 'u';
			e->l = 1;
		}
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

