#include "./includes/ft_printf.h"
#include <locale.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>

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

	//	ft_printf("%S%S", L"Α α", L"Β β");
	ft_putnbr(printf("%.4x", 42));
	printf("\n");
	ft_putnbr(ft_printf("%.4x", 42));

	/*	ft_putnbr(ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
		L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
		L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
		ft_printf("\n");
		ft_putnbr(printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
		L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
		L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
		*/
	return (0);
}
