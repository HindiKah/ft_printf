/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:51:02 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/02 19:40:17 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int			ft_checkprecise(const char *format, int i)
{
	int j;
	int ret;
	int pw;

	pw = 1;
	ret = 0;//atoi(format + i);;
	j = i;
	while (format[j] <= '9' && format[j] >= '0' && format[j])
	{
		ret *= 10;
		ret += pw * (format[j] - '0');
		j++;
	}
	
	return (ret);
}

char		*add_char(char *str, char c)
{
	char	*ret;
	int		len;

	len = ft_strlen(str);
	if (!ft_strchr(str, c))
	{
		ret =(char*)malloc(sizeof(char) * (len + 2));
		ret = ft_strcpy(ret, str);
		ret[len] = c;
		ret[len + 1] = '\0';
		str = ret;
		return(str);
	}
	else
		return (str);
}
