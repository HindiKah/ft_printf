/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:51:02 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:07:27 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t		ft_countparams(const char *format)
{
	int		i;
	size_t	res;

	res = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i] && !ft_strchr("sSpdDioOuUxXcC%", format[i]))
				i++;
			if (format[i + 1])
				res++;
		}
		i++;
	}
	return (res);
}
