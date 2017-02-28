#include "../includes/ft_printf.h"

void		print_char(char c, int i)
{
	char	ret[i];
	int		j;

	if (i <= 0)
		return;
	j = 0;
	while (j < i)
		ret[j++] = c;
	write(1, ret, i);
}

void		print_base_prefix(int base, int maj)
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
}

char		*do_upper(char *str)
{
	while (*str)
	{
		ft_toupper(*str);
		str++;
	}
	return (str);
}
