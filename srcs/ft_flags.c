/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:43:58 by ybenoit           #+#    #+#             */
/*   Updated: 2017/03/22 17:17:49 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

t_arg		*im_t(t_arg *e, va_list all_arg)
{
	intmax_t n;

	n = va_arg(all_arg, intmax_t);
	if (e->j)
		n = n;
	else if (e->z)
		n = (size_t) n;
	else if (e->ll)
		n = (long long int) n;
	else if (e->l)
		n = (long int) n;
	else if (e->hh)
		n = (signed char) n;
	else if (e->h)
		n = (short int) n;
	else
		n = (int)n;
	if (e->sign == -1 && !e->more)
		e->more = 1;
	e->value = (n == 0) ? 0 : 1;
	e->sign = (n < 0) ? -1 : 1;
	e->ret = ft_itoabase_uint(n * e->sign, 10);
	return(e);
}

t_arg		*uim_t(t_arg *e, va_list all_arg)
{
	uintmax_t n;

	n = va_arg(all_arg, uintmax_t);
	if (e->j)
		n = n;
	else if (e->z)
		n = (size_t)n;
	else if (e->ll)
		n = (unsigned long long int)n;
	else if (e->l)
		n = (unsigned long int)n;
	else if (e->hh)
		n = (unsigned char)n;
	else if (e->h)
		n = (unsigned short int)n;
	else
		n = (unsigned int)n;
	e->value = (n == 0) ? 0 : 1;
	e->ret = add_c_ui(n, e);
	return(e);
}


t_arg		*ch_add(t_arg *e, va_list all_arg)
{
	intmax_t n;

	n = va_arg(all_arg, uintmax_t);
	e->ret = add_c_c((int)n);
	return(e);
}

t_arg		*str_add(t_arg *e, va_list all_arg)
{
	char *ret;

	if (e->l == 1)
	{
		e = wstr_add(e, all_arg);
		return (e);
	}
	ret = va_arg(all_arg, char*);
	if (ret)
		e->ret = ft_strdup(ret);
	else
		e->ret = ft_strdup("(null)");
	return(e);
}

t_arg		*percent_add(t_arg *e, va_list all_arg)
{
	if (e->type != 'Z')
		e->ret = add_percent();
	else
	{
		e->ret = (char*)malloc(sizeof(char) * 2);
		e->ret = "Z\0";
	}
	return(e);
}

t_arg		*pointer_add(t_arg *e, va_list all_arg)
{
	void				*n_tmp;
	t_arg				tmp;

	e->sharp = 1;
	e->value = 1;
	tmp = *e;
	n_tmp = va_arg(all_arg, void*);
	tmp.l = 1;
	tmp.base = 16;
	e->ret = add_c_ui((unsigned long int) n_tmp, &tmp);
	return(e);
}

t_arg		*wchar_add(t_arg *e, va_list all_arg)
{
	wchar_t n;

	n = (wchar_t)va_arg(all_arg, wint_t);
	e->wlen = wlen(n);
	e->ret = add_c_wc(n);
	return (e);
}

t_arg		*wstr_add(t_arg *e, va_list all_arg)
{
	wchar_t		*n;
	int			i;

	e->wlen = 0; 
	i = 0;
	n = va_arg(all_arg, wchar_t*);
	while (n[i])
	{
		e->wlen++;
		if (e->ret == NULL)
			e->ret = add_c_wc(n[i]);
		else
			e->ret = ft_strjoin_free(e->ret, add_c_wc(n[i]));
		i++;
	}
	return (e);
}
