/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:57:34 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/19 22:03:53 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countmalloc_base_ui(uintmax_t c, size_t base)
{
	size_t	i;

	i = 0;
	while (c > 1 && base > 0)
	{
		c = c / base;
		i++;
	}
	return (i);
}

char		*ft_itoabase_uint(uintmax_t c, size_t base)
{
	int		i;
	char	*ret;
	char	*tmp;

	if (base > 16)
		return (NULL);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (ft_countmalloc_base_ui(c, base) + 1));
	while (c != 0 && base != 0)
	{
		ret[i++] = ft_converttochar(c % base);
		c = c / base;
	}
	ret[i] = '\0';
	if (i == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
	}
	tmp = ret;
	ret = ft_strrev(tmp);
	free(tmp);
	return (ret);
}
