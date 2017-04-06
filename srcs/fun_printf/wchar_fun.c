/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:40:52 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 11:08:24 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			bit_max(int size);
char		*wchar_to_char(wchar_t c, size_t size, char *ret);
int			bin_mask(size_t size);
int			bin_toadd(size_t size);

char		*add_c_wc(wchar_t c)
{
	char	*ret;
	size_t	size;

	size = wlen(c);
	ret = (char*)malloc(sizeof(int) * (size + 1));
	if (!ret)
		return (NULL);
	ret = wchar_to_char(c, size, ret);
	return (ret);
}

char		*wchar_to_char(wchar_t c, size_t size, char *ret)
{
	int		b_max;
	int		b_norm;
	int		i;

	i = size - 1;
	if (size == 1)
	{
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	b_max = bit_max(size);
	b_norm = 0b111111;
	while (i >= 0)
	{
		if (i == 0)
			ret[i] = (c | b_max);
		else
			ret[i] = ((b_norm & c) | 0b10000000);
		c = c >> 6;
		i--;
	}
	ret[size] = '\0';
	return (ret);
}

int			bit_max(int size)
{
	int	pw;
	int	i;

	pw = 0;
	i = 1;
	while (pw++ < size - 1)
		i = (i << 1) + 1;
	pw = 0;
	while ((i & 0b10000000) != 0b10000000)
		i = i << 1;
	return (i);
}

int			bin_mask(size_t size)
{
	int i;
	int pw;

	pw = 0;
	i = 1;
	while (pw++ < size)
		i = (i << 1) + 1;
	return (i);
}

int			bin_toadd(size_t size)
{
	int ret;
	int i;
	int pw;

	i = 0;
	pw = 128;
	ret = 0;
	while (i++ < size)
	{
		ret += pw;
		pw /= 2;
	}
	return (ret);
}
