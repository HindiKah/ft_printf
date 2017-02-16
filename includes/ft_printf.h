/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:45:12 by ybenoit           #+#    #+#             */
/*   Updated: 2017/02/13 15:31:08 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define FINT  "di\0"
# define FUINT  "uoxX\0"
# define FSTR  "s\0"
# define FCHAR  "cC\0"
# define FPERCENT  "%\0"
# define FPOINTER  "p\0"
# define FCHARTAB  "S\0"

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct			s_arg
{
	int					index;
	int					argend;
	char				type;
	int					base;
	int					sign;
	int					value;
	int					dot;
	char				flag;
	char				*pref;
	int					p;
	int					p0;
	int					p_end;
	int					wlen;
	int					str;
	int					truearg;
	char				*ret;
}						t_arg;

typedef struct			s_func
{
	char				pflag;
	t_arg				*(*f)(t_arg *my_arg);
}						t_func;

typedef struct			s_funf
{
	char				*flag;
	t_arg				*(*f)(t_arg *my_arg, va_list all_arg);
}						t_funf;


t_func			*ft_init_func(t_func *my_func);
t_funf			*ft_init_funf(t_funf *my_funf);
int				ft_printf(const char *format, ...);
size_t			ft_countparams(const char *format);
void			ft_putlong(long c);
char			*ft_intobinarie(int c);
char			*ft_cutbin(char *bin);
char			*ft_checkmaj(char *nbr);
void			ft_putfloat(double nbr, int p);
int				ft_checkprecise(const char *format, int i);
int				*ft_checkprecision(const char *format, int i);
t_arg			*ft_create_tvar(t_arg *tvar, const char *format);
t_arg			*ft_init_tvar(t_arg *tvar, const char *format, int p);
void			ft_print_args(t_func *my_func, t_arg tvar);
t_arg			*ft_check_flag(t_arg *tvar,  const char *format, int i);
t_arg			*ft_check_tandp(t_arg *tvar, const char *format, int i);
t_arg			*ft_init_value(t_arg *tvar, va_list all_arg, t_funf *my_funf);
t_arg			*flag_0(va_list all_arg, t_arg *tvar);
t_arg			*flag_h(va_list all_arg, t_arg *tvar);
t_arg			*flag_hh(va_list all_arg, t_arg *tvar);
t_arg			*flag_l(va_list all_arg, t_arg *tvar);
t_arg			*flag_ll(va_list all_arg, t_arg *tvar);
t_arg			*flag_j(va_list all_arg, t_arg *tvar);
t_arg			*flag_z(va_list all_arg, t_arg *tvar);
char			*add_c_i(int n);
char			*add_c_ui(uintmax_t n, t_arg *tvar);
char			*add_c_c(int n);
char			*add_c_s(char *str);
char			*add_percent();
char			search_pflag(const char *format, int i);
t_arg			*init_pflag(t_arg *tvar, const char *format);
t_arg			*pflag_0(t_arg *tvar);
t_arg			*pflag_none(t_arg *tvar);
t_arg			*pflag_pc(t_arg *tvar);
t_arg			*pflag_sharp(t_arg *tvar);
t_arg			*pflag_less(t_arg *tvar);
t_arg			*pflag_more(t_arg *tvar);
t_arg			*ft_do_all_fun(t_funf *my_funf, t_func *my_func, va_list all_arg, t_arg *tvar);
t_func			*ft_init_func(t_func *my_func);
char			*add_less(char *nb);
char			*add_more(char *nb);
int 			width_index(const char *format, int i, char b, char e);
t_arg			*im_t(t_arg *tvar, va_list allarg);
t_arg			*uim_t(t_arg *tvar, va_list allarg);
t_arg			*ch_add(t_arg *tvar, va_list allarg);
t_arg			*str_add(t_arg *tvar, va_list allarg);
t_arg			*percent_add(t_arg *tvar, va_list allarg);
t_arg			*pointer_add(t_arg *tvar, va_list allarg);
t_arg			*wchar_add(t_arg *tvar, va_list allarg);
t_arg			*wstr_add(t_arg *tvar, va_list allarg);
char			*add_char(char *str, char c);
char			*add_c_wc(wchar_t n);
t_arg			*init_precision(t_arg *tvar, const char *format);
const char		*whatisnext_c(const char *format, char c);
t_arg			*treat_precision(t_arg *tvar, int i, int j, int k);
t_arg			*parse_args(t_arg *tvar, const char *format);
t_arg			*init_flag(t_arg *tvar, const char *format);
char			*insert_char(char *str, char c);
#endif
