/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctransformer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:57:27 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/29 14:56:56 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*add_c_ui(uintmax_t n, t_arg *e)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_itoabase_uint(n, e->base);
	if (e->type == 'X')
	{
		while (ret[i])
		{
			ret[i] = ft_toupper(ret[i]);
			i++;
		}
	}
	return (ret);
}

char		*add_c_c(int n)
{
	char *ret;

	ret = (char*)malloc(sizeof(char) * 2);
	ret[0] = n;
	ret[1] = '\0';
	return (ret);
}

char		*add_percent(void)
{
	char *ret;

	ret = (char*)malloc(sizeof(char) * 2);
	ret[0] = '%';
	ret[1] = '\0';
	return (ret);
}
