/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additfun2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:15:03 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:07:11 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*add_less(char *nb)
{
	int		i;
	char	*ret;
	int		j;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(nb) + 1));
	i = 0;
	j = 1;
	ret[0] = '-';
	while (nb[i])
		ret[j++] = nb[i++];
	ret[j] = '\0';
	free(nb);
	nb = ret;
	return (ret);
}

char		*add_more(char *nb)
{
	int		i;
	char	*ret;
	int		j;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(nb) + 1));
	i = 0;
	j = 1;
	ret[0] = '+';
	while (nb[i])
		ret[j++] = nb[i++];
	ret[j] = '\0';
	free(nb);
	nb = ret;
	return (ret);
}

int			width_index(const char *format, int i, char b, char e)
{
	int ret;

	ret = i;
	while (format[i] && (format[i] <= e && format[i++] >= b))
		ret++;
	return (ret);
}

const char	*whatisnext_c(const char *format, char c)
{
	while (*format && *format == c)
		format++;
	if (*format)
		return (format);
	else
		return (NULL);
}

char		*insert_char(char *str, char c)
{
	char *ret;

	if (!str)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(ret) + 2));
	ret = ft_strcpy(ret, str);
	free(str);
	str = ft_strcpy(str, ret);
	str[ft_strlen(ret)] = c;
	str[ft_strlen(ret) + 1] = '\0';
	str = ret;
	return (str);
}
