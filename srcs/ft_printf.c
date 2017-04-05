/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:12:48 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/29 18:11:44 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			final_print(const char *format, va_list all_arg, t_func *my_func, t_funf *my_funf);

int			ft_printf(const char *format, ...)
{
	va_list		all_arg;
	t_func		*my_func;
	t_funf		*my_funf;
	t_arg		*e;
	int			ret;

	va_start(all_arg, format);
	my_func = ft_init_func(my_func);
	my_funf = ft_init_funf(my_funf);




	//	int i = 0;
	//	while (i < 2)
	//		print_debug(e[i++]);



	ret = final_print(format, all_arg, my_func, my_funf);
	va_end(all_arg);
	free(my_func);
	free(my_funf);
	return (ret);
}

int			final_print(const char *format, va_list all_arg, t_func *my_func, t_funf *my_funf)
{
	int		i;
	int		ret;
	t_arg	e;

	ret = 0;
	i = 0;
	e.type = '0';
	e.ret = NULL;
	while (format[i])
	{
		if (format[i] == '%' && ((e = parse_args(format + i, e)).type != 'e'))
		{
			e = parse_args(format + i, e);
			if (e.type != 'e')
			{
				e = ft_init_value(e, all_arg, my_funf); 
				e = print_arg(e, my_func);
			}
			ret += e.res;
			i += e.argend;
		}
		else if (format[i] != 10)
			ret += (format[i] != '%') ? rprint(1, format + i, 1) : 0;
		i++;
	}
	return (ret);
}


void		print_debug(t_arg e)
{
	printf("\n\nT_ARG type-> %c\nl = %d\nll = %d\nh = %d\nhh = %d\nj = %d\nz = %d\np = %d && p0 = %d && dot = %d\n# = %d\n+ == %d\n- = %d\nspace = %d\nzero = %d\nargend = %d\nvalue = %d\n\tret = %s -> e.res = %d\n",  e.type, e.l, e.ll, e.h, e.hh, e.j, e.z, e.p, e.p0, e.dot,  e.sharp, e.more, e.right, e.space, e.zero, e.argend, e.value,  e.ret, e.res);
}
