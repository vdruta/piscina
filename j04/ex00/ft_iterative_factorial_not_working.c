#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;
//	int f;

	i = 1;
//	f = 1;
	if (nb == 0)
		return (1);
	if (nb >= 1)
	{
		while (i < nb)
		{
			nb = nb * i;
			i++;
		}
		return (nb);
	}
	else
		return (0);
}

int	main(void)
{
	int a;

	a = 5;
	printf("%d", ft_iterative_factorial(a));
	return (0);
}
