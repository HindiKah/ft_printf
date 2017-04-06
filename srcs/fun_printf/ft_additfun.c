/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additfun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:11:28 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:06:51 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_checkmaj(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		nbr[i] = ft_toupper(nbr[i]);
		i++;
	}
	return (nbr);
}

t_arg		*init_pflag(t_arg *e, const char *format)
{
	int tmp;

	tmp = 0;
	while (format[tmp] && !ft_strchr(ARG, format[tmp]))
	{
		if (ft_strchr(PREF, format[tmp]))
		{
			if (format[tmp] == '0' && !ft_strchr(NUM, format[tmp - 1]) &&
					!ft_strchr("0", format[tmp + 1]) && format[tmp - 1] != '.')
				e->zero = 1;
			if (format[tmp] == '#')
				e->sharp = 1;
			if (format[tmp] == ' ')
				e->space = 1;
			if (format[tmp] == '+')
				e->more = 1;
			if (format[tmp] == '-')
				e->right = 1;
		}
		tmp++;
	}
	return (e);
}
