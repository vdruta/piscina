#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 42;
	b = 9;
	div = 0;
	mod = 0;	
	ft_div_mod(a, b, &div, &mod);
	printf("%d" " " "%d", div, mod);
	return (0);
}
