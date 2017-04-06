/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:30:20 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 10:39:40 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_func		*ft_init_func(t_func *my_func)
{
	my_func = (t_func*)malloc(sizeof(t_func) * 8);
	if (!my_func)
		return (NULL);
	my_func[0].type = FINT;
	my_func[0].f = &putd;
	my_func[1].type = FUINTO;
	my_func[1].f = &puto;
	my_func[2].type = FUINT;
	my_func[2].f = &putx;
	my_func[3].type = FCHAR;
	my_func[3].f = &putch;
	my_func[4].type = FSTR;
	my_func[4].f = &putst;
	my_func[5].type = FPERCENT;
	my_func[5].f = &putpercent;
	my_func[6].type = FPOINTER;
	my_func[6].f = &putp;
	my_func[7].type = FCHARTAB;
	my_func[7].f = &putwstr;
	return (my_func);
}

t_funf		*ft_init_funf(t_funf *my_funf)
{
	my_funf = (t_funf*)malloc(sizeof(t_funf) * 8);
	if (!my_funf)
		return (NULL);
	my_funf[0].flag = FINT;
	my_funf[0].f = &im_t;
	my_funf[1].flag = FUINT;
	my_funf[1].f = &uim_t;
	my_funf[2].flag = FWCHAR;
	my_funf[2].f = &wchar_add;
	my_funf[3].flag = FCHAR;
	my_funf[3].f = &ch_add;
	my_funf[4].flag = FSTR;
	my_funf[4].f = &str_add;
	my_funf[5].flag = FPERCENT;
	my_funf[5].f = &percent_add;
	my_funf[6].flag = FPOINTER;
	my_funf[6].f = &pointer_add;
	my_funf[7].flag = FCHARTAB;
	my_funf[7].f = &wstr_add;
	return (my_funf);
}

t_arg		print_arg(t_arg e, t_func *my_func)
{
	int		i;

	i = 0;
	while (!ft_strchr(my_func[i].type, e.type))
		i++;
	e = my_func[i].f(e);
	return (e);
}
