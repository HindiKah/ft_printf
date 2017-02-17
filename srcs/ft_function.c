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
	my_func = (t_func*)malloc(sizeof(t_func) * 6);
	my_func[0].pflag = '0';
	my_func[0].f = &pflag_0;
	my_func[1].pflag = '#';
	my_func[1].f = &pflag_sharp;
	my_func[2].pflag = '+';
	my_func[2].f = &pflag_more;
	my_func[3].pflag = 'n';
	my_func[3].f = &pflag_none;
	my_func[4].pflag = 'N';
	my_func[4].f = &pflag_pc;
	my_func[5].pflag = '-';
	my_func[5].f = &pflag_less;
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

t_arg		*func_check(t_func *my_func, t_arg *tvar)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tvar->pref[j] && i < 6)
	{
		if (ft_strchr(tvar->pref, my_func[i].pflag))
		{
			my_func[i].f(tvar);
			j++;
		}
		i++;
	}
	return (tvar);
}

t_arg		*ft_do_all_fun(t_funf *my_funf, t_func *my_func, va_list all_arg, t_arg *tvar)
{
	int i;

	ft_putstr("ENTER DO ALL FUN\n");
	i = 0;
	while (tvar[i].type != 'e')
	{
		ft_putstr("ENTER THE WHILE\n");
		ft_putchar(tvar[i].type);
		ft_init_value(&tvar[i], all_arg, my_funf);
		ft_putstr("AFTER INIT VALUE\n");
		tvar->value = (tvar[i].ret[0] == '0') ? 0 : 1;
		ft_putstr("ATTRIB TVAR VALUE\n");
		func_check(my_func, &tvar[i]);
		ft_putstr("AFTER FUNC CHECK\n");
		i++;
	}
	return (tvar);
}
