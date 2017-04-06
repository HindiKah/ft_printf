/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:46:51 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:07:53 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_arg		ft_init_value(t_arg e, va_list all_arg, t_funf *my_funf)
{
	int i;

	i = 0;
	while (ft_strchr(my_funf[i].flag, e.type) == NULL)
		i++;
	e = my_funf[i].f(e, all_arg);
	e.arg_len = ft_strlen(e.ret);
	e.value = (e.ret[0] == '0' && e.type != 'p') ? 0 : 1;
	return (e);
}

int			rprint(int fd, const char *str, int n)
{
	write(fd, str, n);
	return (n);
}

int			wlen(int c)
{
	int	size;

	if (c <= 0x7F)
		size = 1;
	else if (c <= 0x7FF)
		size = 2;
	else if (c <= 0xFFFF)
		size = 3;
	else if (c <= 0x10FFFF)
		size = 4;
	else
		size = 0;
	return (size);
}

t_arg		*treat_flag_base(t_arg *e)
{
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
