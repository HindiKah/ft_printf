/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:40:52 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/13 16:27:39 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			bit_max(int size);
char		*wchar_to_char(wchar_t c, size_t size, char *ret);
int			bin_mask(size_t size);
int			bin_toadd(size_t size);

char		*add_c_wc(wchar_t c)
{
	char	*ret;
	size_t	iter;
	size_t	size;

	if (c <= 0x7F)
		size = 1;
	else if (c <= 0x7FF)
		size = 2;
	else if (c <= 0xFFFF)
		size = 3;
	else if (c <= 0x10FFFF)
		size = 4;
	else
		return(NULL);
	iter = 0;
	ret = (char*)malloc(sizeof(int) * (size + 2));
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
	while(i >= 0)
	{
		if (i == 0)
		{
			ret[i] = (c & bin_mask(size)) | bin_toadd(size);
		}
		else
		{
			ret[i] = ((b_norm & c) | 0b10000000);
		}
		c = c >> 6;
		i--;
	}
	ret[size] ='\0';
	return (ret);
}


int			bit_max(int size)
{
	int		b_max;
	int i;
	int pw;

	b_max = 0;
	pw = 128;
	i = 0;
	while (i < size)
	{
		b_max += pw;
		pw /= 2;
		i++;
	}
	return (b_max);
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
