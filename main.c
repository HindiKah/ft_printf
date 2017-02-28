#include "./includes/ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	//char *coucou = "coucou";
	if (argc == 35135131)
	{
		ft_putstr(argv[0]);
		return (0);
	}
	int i = -0;
	int j = 5;
//	ft_printf("%0d   ", -1 );
//	ft_printf("%+10i", -1278 );
	//ft_printf(" %10hd  %#10hx  ", 1278, 1234);
	//ft_printf("%  x   \n", 123);
	/*
	printf("0        1         2          3\n");
	printf("123456789012345678901234567890123456\n");
	printf("||||||||||||||||||||||||||||||||||||\n");
	printf("%  9.6d|   \n", 1);
	printf("%9.6d|   \n", 1);
	printf("%    .6d|   \n", 1);
	printf("%.6d|   \n", 1);
	*/
	//printf("printf === > %+010i",i);
//	ft_printf(" le mien %p\n", i)
	//printf("\n\n\t bin1 = %s\n", ft_itoabase(test, 2));
//	printf("|% d| |% -  +   43d| %", 42, 42, 42);
	//ft_putnbr(ft_atoi("              010"));
	//t_arg *tvar;
	//parse_args(tvar,"  %+- 010d %-010.5X  %d");
	/*
	  */
	//printf("TEST REAL ONE---> %d\n\n", 1000000000000000000);
	//ft_printf("%#.20x\n", 123);
	//printf("%#.20x\n", 123);
//	printf("hello||%C||world\n", 400);

	//printf("hello||%C||world\n", &i);


//	printf("true|%#.x, %.10x|\n", 0, 0);
//printf("Pret = %d\n",  printf("p|%C|", L'我'));
 
	//ft_printf("%#10.9llx blabla |%10.2s|", -42, "coucou");
	

	  //ft_printf("%10.10%", "test");
		ft_printf("%#-6.2x|\n", 4);
		printf("%#-6.2x|", 4);
	return (0);
}
