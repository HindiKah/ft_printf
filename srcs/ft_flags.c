/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:43:58 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/14 21:40:23 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"

t_arg		*im_t(t_arg *tvar, va_list all_arg)
{
	intmax_t n;

	n = va_arg(all_arg, intmax_t);
	tvar->value = (n == 0) ? 0 : 1;
	tvar->sign = (n <  0 || n >= 2147483648) ? -1 : 1;
	if (tvar->flag == '0')
		tvar->ret = add_c_i((int)n * tvar->sign);
	else if (tvar->flag == 'h')
		tvar->ret = add_c_i((short int)n * tvar->sign);
	else if (tvar->flag == 'H')
		tvar->ret = add_c_i((signed char)n * tvar->sign);
	else if (tvar->flag == 'l')
		tvar->ret = add_c_i((long int)n * tvar->sign);
	else if (tvar->flag == 'L')
		tvar->ret = add_c_i((long long int)n * tvar->sign);
	else if (tvar->flag == 'j')
		tvar->ret = add_c_i(n * tvar->sign);
	else if (tvar->flag == 'z')
		tvar->ret = add_c_i((size_t)n * tvar->sign);
	if (tvar->sign == -1 && !ft_strchr("tvar->pref", '+'))
		insert_char(tvar->pref, '+');
	return(tvar);
}

t_arg		*uim_t(t_arg *tvar, va_list all_arg)
{
	uintmax_t n;

	n = va_arg(all_arg, uintmax_t);
	tvar->value = (n == 0) ? 0 : 1;
	if (tvar->flag == '0')
		tvar->ret = add_c_ui((unsigned int)n, tvar);
	else if (tvar->flag == 'h')
		tvar->ret = add_c_ui((unsigned short int)n, tvar);
	else if (tvar->flag == 'H')
		tvar->ret = add_c_ui((unsigned char)n,tvar);
	else if (tvar->flag == 'l')
		tvar->ret = add_c_ui((unsigned long int)n, tvar);
	else if (tvar->flag == 'L')
		tvar->ret = add_c_ui((unsigned long long int)n, tvar);
	else if (tvar->flag == 'j')
		tvar->ret = add_c_ui(n, tvar);
	else if (tvar->flag == 'z')
		tvar->ret = add_c_ui((size_t)n, tvar);
	return(tvar);
}


t_arg		*ch_add(t_arg *tvar, va_list all_arg)
{
	intmax_t n;

	n = va_arg(all_arg, uintmax_t);
	/*if (tvar->flag == 'l')
	  tvar->ret = add_c_wc((unsigned long int)n);
	  else*/
	tvar->ret = add_c_c((int)n);
	return(tvar);
}

t_arg		*str_add(t_arg *tvar, va_list all_arg)
{
	/*if (tvar->flag == 'l')
	  tvar->ret = add_c_ws(va_arg(all_arg, wchar_t));
	  else*/
	char *ret;
	
	ret = va_arg(all_arg, char*);
	if (ret != 0)
		tvar->ret = ft_strdup(ret);
	else
	{
		tvar->ret = ft_strdup("(null)");
	}
	return(tvar);
}

t_arg		*percent_add(t_arg *tvar, va_list all_arg)
{
	tvar->ret = add_percent();
	return(tvar);
}

t_arg		*pointer_add(t_arg *tvar, va_list all_arg)
{
	void				*n_tmp;
	t_arg				tmp;

	tvar->pref = add_char(tvar->pref, '#');
	tmp = *tvar;
	n_tmp = va_arg(all_arg, void*);
	tmp.flag = 'l';
	tmp.base = 16;
	tvar->ret = add_c_ui((unsigned long int) n_tmp, &tmp);
	return(tvar);
}

t_arg		*wchar_add(t_arg *tvar, va_list all_arg)
{
	wchar_t n;

	n = (wchar_t)va_arg(all_arg, wint_t);
	tvar->wlen = 1;
	tvar->ret = add_c_wc(n);
	return (tvar);
}

t_arg		*wstr_add(t_arg *tvar, va_list all_arg)
{
	wchar_t		*n;

		tvar->wlen = 0; 
	n = va_arg(all_arg, wchar_t*);
	while (*n)
	{
		tvar->wlen++; 
		if (!tvar->ret)
			tvar->ret = ft_strdup(add_c_wc(*n));
		else
			tvar->ret = ft_strjoin_free(tvar->ret , add_c_wc(*n));
		n++;
	}
	return (tvar);
}
