/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:46:51 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/22 15:00:56 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	write(fd , str, n);
	return (n);
}
