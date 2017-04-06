/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:46:32 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 10:00:44 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_arg		n_exist(t_arg e, wchar_t *n, int i);
t_arg		n_doesnt_exist(t_arg e, wchar_t *n);

t_arg		pointer_add(t_arg e, va_list all_arg)
{
	void	*n_tmp;
	t_arg	tmp;

	e.sharp = 1;
	e.value = 1;
	tmp = e;
	n_tmp = va_arg(all_arg, void*);
	tmp.l = 1;
	tmp.base = 16;
	if (n_tmp || e.dot == 0)
		e.ret = add_c_ui((unsigned long int)n_tmp, &tmp);
	else
		e.ret = ft_strdup("");
	return (e);
}

t_arg		wchar_add(t_arg e, va_list all_arg)
{
	wchar_t	n;

	n = (wchar_t)va_arg(all_arg, wint_t);
	e.wlen = wlen(n);
	e.ret = add_c_wc(n);
	if (e.dot == 1)
		e.p0 = 0;
	return (e);
}

t_arg		wstr_add(t_arg e, va_list all_arg)
{
	wchar_t		*n;
	int			i;

	e.wlen = 0;
	i = 0;
	n = va_arg(all_arg, wchar_t*);
	if (n && n[0] != '\0')
	{
		while (n[i])
		{
			e.wlen++;
			e = n_exist(e, n, i);
			i++;
		}
		e.wchar = n;
		e.spec = 0;
	}
	else
	{
		e = n_doesnt_exist(e, n);
		e.spec = 1;
	}
	return (e);
}

t_arg		n_exist(t_arg e, wchar_t *n, int i)
{
	if (e.ret == NULL)
		e.ret = add_c_wc(n[i]);
	else
		e.ret = ft_strjoin_free(e.ret, add_c_wc(n[i]));
	return (e);
}

t_arg		n_doesnt_exist(t_arg e, wchar_t *n)
{
	if (!n)
		e.ret = ft_strdup("(null)");
	else if (n)
		e.ret = ft_strdup("\0");
	e.type = 's';
	return (e);
}
