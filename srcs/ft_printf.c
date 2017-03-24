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


	int i = 0;
	while (i != ft_countparams(format))
	{
	printf("\n\nT_ARG %d type-> %c\nl = %d\nll = %d\nh = %d\nhh = %d\nj = %d\nz = %d\np = %d && p0 = %d && dot = %d\n# = %d\n+ == %d\n- = %d\nspace = %d\nzero = %d\nend index = %d\n\t\t\tret = |%s|\n", e[i].index, e[i].type, e[i].l, e[i].ll, e[i].h, e[i].hh, e[i].j, e[i].z, e[i].p, e[i].p0, e[i].dot,  e[i].sharp, e[i].more, e[i].right, e[i].space, e[i].zero, e[i].argend, e[i].ret);
	i++;
	}


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
	while (format[i])
	{
		if (i == e->index && e->type != 'e')
		{
			ret += rprint(1, format + tmp, j);
			print_arg(e, my_func);
			ret += e->res;
			i = e->argend;
			tmp = (format[e->argend]) ? i : tmp + 1;
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
