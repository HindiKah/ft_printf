/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additfun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:11:28 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/22 16:59:57 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_cutbin(char *bin)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (bin[i] != '1' && bin[i])
		i++;
	if (bin[i] == '\0')
		return ("0000");
	i = i / 4;
	ret = (char*)malloc(sizeof(char) * (41 - (i * 4)));
	i = i * 4;
	while (bin[i])
		ret[j++] = bin[i++];
	ret[j] = '\0';
	free(bin);
	return (ret);
}

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

void		ft_putfloat(double nbr, int p)
{
	double				i;
	unsigned long int	tmp;

	tmp = 0;
	i = 10;
	ft_putnbr((unsigned long int)nbr);
	ft_putchar('.');
	while (p > 0)
	{
		tmp = (unsigned long int)(nbr * i);
		if ((tmp - ((unsigned long int)(nbr * (i / 10))) * 10) <= 0)
			ft_putnbr(0);
		else
			ft_putnbr(tmp - ((unsigned long int)(nbr * (i / 10))) * 10);
		i *= 10;
		p--;
	}
}

t_arg		*init_pflag(t_arg *tvar, const char *format)
{
	int j;
	int tmp;

	tmp = 0;
	tvar->pref = (char*)malloc(sizeof(char) * (4));
	j = 0;
	while (format[tmp] && !ft_strchr("sSuUdioxXp%123456789", format[tmp]))
		{
		if (search_pflag(format, tmp) != 0)
			tvar->pref[j++] = format[tmp];
		tmp++;
		}
	tvar->pref[j] = '\0';
	return (tvar);
}

char		search_pflag(const char *format, int i)
{
	if (ft_strchr("+#-0", format[i]) != NULL)
		return (format[i]);
	else
		return (0);
}
