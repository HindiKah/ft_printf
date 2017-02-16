#include "libft.h"

char		*ft_strmaj(char *str)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = str[i] - 'a' + 'A';
	}
	return (str);
}
