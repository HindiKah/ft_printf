/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:12:48 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:11:38 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			final_print(const char *format,
		va_list all_arg, t_func *my_func, t_funf *my_funf);
t_arg		printer(t_arg e, t_func *my_func,
		t_funf *my_funf, va_list all_arg);

int			ft_printf(const char *format, ...)
{
	va_list		all_arg;
	t_func		*my_func;
	t_funf		*my_funf;
	int			ret;

	va_start(all_arg, format);
	my_func = ft_init_func(my_func);
	my_funf = ft_init_funf(my_funf);
	ret = final_print(format, all_arg, my_func, my_funf);
	va_end(all_arg);
	free(my_func);
	free(my_funf);
	return (ret);
}

int			final_print(const char *format,
		va_list all_arg, t_func *my_func, t_funf *my_funf)
{
	int		i;
	int		ret;
	t_arg	e;

	ret = 0;
	i = 0;
	e.type = '0';
	while (format[i])
	{
		if (format[i] == '%' && ((e = parse_args(format + i, e)).type != 'e'))
		{
			e = printer(e, my_func, my_funf, all_arg);
			ret += e.res;
			i += e.argend;
		}
		else if (format[i])
			ret += (format[i] != '%') ? rprint(1, format + i, 1) : 0;
		i++;
	}
	return (ret);
}

t_arg		printer(t_arg e, t_func *my_func, t_funf *my_funf, va_list all_arg)
{
	e = ft_init_value(e, all_arg, my_funf);
	e = print_arg(e, my_func);
	if (e.ret)
		free(e.ret);
	return (e);
}
