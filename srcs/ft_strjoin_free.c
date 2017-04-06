/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:24:52 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 10:49:07 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		cleaning_str(char const *s1, char const *s2);

char		*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	i = 0;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	cleaning_str(s1, s2);
	return (ret);
}

void		cleaning_str(char const *s1, char const *s2)
{
	if (s1)
		free((char*)s1);
	if (s2)
		free((char*)s2);
}
