/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:08:10 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/17 16:31:11 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_sstradd(char **dest, char **src, char *to_add)
{
	int i;
	int j;

	i = 0;
	j = 0;
	dest = (char **)malloc(sizeof(char*) * ft_sstrlen(src));
	if (!dest)
		return (NULL);
	while (src[i++])
	{
		dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]));
		if (!dest[i])
			return (NULL);
		dest[i] = ft_strcpy(dest[i], (const char*)src[i]);
		free(src[i]);
	}
	free(src);
	dest[i] = ft_strcpy(dest[i], (const char*)to_add);
	i++;
	dest[i] = NULL;
	return (dest);
}
