/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:30:20 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/13 11:00:01 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_func		*ft_init_func(t_func *my_func)
{
	my_func = (t_func*)malloc(sizeof(t_func) * 7);
	my_func[0].type = FINT;
	my_func[0].f = &putd;
	my_func[1].type = FUINT;
	my_func[1].f = &putx;
	my_func[2].type = FCHAR;
	my_func[2].f = &putch;
	my_func[3].type = FSTR;
	my_func[3].f = &putst;
	my_func[4].type = FPERCENT;
	my_func[4].f = &putpercent;
	my_func[5].type = FPOINTER;
	my_func[5].f = &putx;
	my_func[6].type = FCHARTAB;
	my_func[6].f = &putwstr;

	return (my_func);
}

t_funf		*ft_init_funf(t_funf *my_funf)
{
	my_funf = (t_funf*)malloc(sizeof(t_funf) * 7);
	my_funf[0].flag = FINT;
	my_funf[0].f = &im_t;
	my_funf[1].flag = FUINT;
	my_funf[1].f = &uim_t;
	my_funf[2].flag = FCHAR;
	my_funf[2].f = &wchar_add;
	my_funf[3].flag = FSTR;
	my_funf[3].f = &str_add;
	my_funf[4].flag = FPERCENT;
	my_funf[4].f = &percent_add;
	my_funf[5].flag = FPOINTER;
	my_funf[5].f = &pointer_add;
	my_funf[6].flag = FCHARTAB;
	my_funf[6].f = &wstr_add;
	return (my_funf);
}

t_arg		*ft_do_all_fun(t_funf *my_funf, t_func *my_func, va_list all_arg, t_arg *tvar)
{
	int i;

	i = 0;
	while (tvar[i].type != 'e')
	{
		ft_init_value(&tvar[i], all_arg, my_funf);
		tvar->value = (tvar[i].ret[0] == '0') ? 0 : 1;
		i++;
	}
	return (tvar);
}

void		print_arg(t_arg *tvar, t_func *my_func)
{
	int		i;

	i = 0;
	while (!ft_strchr(my_func[i].type, tvar->type))
		i++;
	my_func[i].f(tvar);
}

