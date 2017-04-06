/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:45:12 by ybenoit           #+#    #+#             */
/*   Updated: 2017/04/06 10:46:38 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define ARG "DdiuUoOxXSscC%ZRp"
# define NUM "1234567890"
# define PREF "0#-+ "
# define FINT  "Ddi\0"
# define FUINT  "uUoOxX\0"
# define FUINTO  "Oou\0"
# define FSTR  "s\0"
# define FCHAR  "cC\0"
# define FWCHAR  "C\0"
# define FPERCENT  "%ZR\0"
# define FPOINTER  "p\0"
# define FCHARTAB  "S\0"

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct			s_arg
{
	int					argend;
	char				type;
	int					base;
	int					sign;
	int					value;
	int					dot;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					zero;
	int					space;
	int					sharp;
	int					right;
	int					more;
	int					p;
	int					p0;
	int					p_end;
	int					wlen;
	int					str;
	size_t				arg_len;
	int					spec;
	wchar_t				*wchar;
	char				*ret;
	int					res;
}						t_arg;

typedef struct			s_func
{
	char				*type;
	t_arg				(*f)(t_arg my_arg);
}						t_func;

typedef struct			s_funf
{
	char				*flag;
	t_arg				(*f)(t_arg my_arg, va_list all_arg);
}						t_funf;


t_func			*ft_init_func(t_func *my_func);
t_funf			*ft_init_funf(t_funf *my_funf);
int				ft_printf(const char *format, ...);
size_t			ft_countparams(const char *format);
char			*ft_checkmaj(char *nbr);
int				ft_checkprecise(const char *format, int i);
void			ft_print_args(t_func *my_func, t_arg e);
t_arg			ft_init_value(t_arg e, va_list all_arg, t_funf *my_funf);
char			*add_c_i(intmax_t n);
char			*add_c_ui(uintmax_t n, t_arg *e);
char			*add_c_c(int n);
char			*add_c_s(char *str);
char			*add_percent();
char			search_pflag(const char *format, int i);
t_arg			*init_pflag(t_arg *e, const char *format);
t_func			*ft_init_func(t_func *my_func);
t_arg			im_t(t_arg e, va_list allarg);
t_arg			uim_t(t_arg e, va_list allarg);
t_arg			ch_add(t_arg e, va_list allarg);
t_arg			str_add(t_arg e, va_list allarg);
t_arg			percent_add(t_arg e, va_list allarg);
t_arg			pointer_add(t_arg e, va_list allarg);
t_arg			wchar_add(t_arg e, va_list allarg);
t_arg			wstr_add(t_arg e, va_list allarg);
char			add_char(char *str, char c);
char			*add_c_wc(wchar_t n);
t_arg			*init_precision(t_arg *e, const char *format);
t_arg			parse_args(const char *format, t_arg e);
t_arg			*init_flag(t_arg *e, const char *format);
int				print_char(char c, int i);
t_arg			putd(t_arg e);
t_arg			putx(t_arg e);
t_arg			putp(t_arg e);
t_arg			puto(t_arg e);
t_arg			putch(t_arg e);
t_arg			putst(t_arg e);
t_arg			putpercent(t_arg e);
t_arg			putwstr(t_arg e);
char			*do_upper(char *str);
int				print_base_prefix(int base, int maj);
t_arg			print_arg(t_arg e, t_func *my_func);
int				wlen(int n);
t_arg			*str_precision(t_arg *e);
int				print_sign(t_arg *e);
int				rprint(int fd, const char *str, int n);
void			delete_char(char *str, char c);
t_arg			init_e(t_arg e);
void			print_debug(t_arg e);
t_arg			*d_precision(t_arg *e);
int				howmanytoprint(t_arg *e);
t_arg			*treat_flag_base(t_arg *e);
#endif
