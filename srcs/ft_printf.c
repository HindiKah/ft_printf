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

int			final_print(const char *format, t_arg *e, va_list all_arg, t_func *my_func);

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
	e = parse_args(e, format);
	ft_do_all_fun(my_funf, my_func, all_arg, e);
	ret = final_print(format, e, all_arg, my_func);


//	int i = 0;
//	while (i < 1)
//		print_debug(e[i++]);




	va_end(all_arg);
	//free(my_func);
	//free(my_funf);
	//free(e);
	return (ret);
}

int			final_print(const char *format, t_arg *e, va_list all_arg, t_func *my_func)
{
	int		i;
	int		ret;
	int		j;
	int		tmp;

	tmp = 0;
	j = 0;
	ret = 0;
	i = 0;
	while (format[i] && e)
	{
		if (i == e->index && e->type != 'e')
		{
			ret += rprint(1, format + tmp, j);
			print_arg(e, my_func);
			ret += e->res;
			i = e->argend;
			tmp = i;
			j = 0;
			e++;
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


void		print_debug(t_arg e)
{
	printf("\n\nT_ARG %d type-> %c\nl = %d\nll = %d\nh = %d\nhh = %d\nj = %d\nz = %d\np = %d && p0 = %d && dot = %d\n# = %d\n+ == %d\n- = %d\nspace = %d\nzero = %d\nargend = %d\n\tret = %s -> arglen = %d\n", e.index, e.type, e.l, e.ll, e.h, e.hh, e.j, e.z, e.p, e.p0, e.dot,  e.sharp, e.more, e.right, e.space, e.zero, e.argend, e.ret, e.arg_len);
}
