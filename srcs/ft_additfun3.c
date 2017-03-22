#include "../includes/ft_printf.h"

int			print_char(char c, int i)
{
	char	ret[i];
	int		j;

	if (i <= 0)
		return (0);
	j = 0;
	while (j < i)
		ret[j++] = c;
	write(1, ret, i);
	return (i);
}

int			print_base_prefix(int base, int maj)
{
	char		b[2];

	if (base == 16)
	{
		b[0] = '0';
		b[1] = (maj == 1) ? 'X' : 'x';
		write(1, b, 2);
	}
	else if (base == 8)
	{
		b[0] = '0';
		write(1, b, 1);
	}
	return ((base == 16) ? 2 : 1);
}

char		*do_upper(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		ft_toupper(str[i]);
	return (str);
}

int			print_sign(t_arg *tvar)
{
	if (tvar->sign == -1)
		write(1, "-", 1);
	else
		write(1, "+", 1);
	return (1);
}
