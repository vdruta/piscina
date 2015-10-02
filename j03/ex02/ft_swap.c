#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int a;
	int b;

	a = 0;
	b = 42;
	ft_swap(&a, &b);
	printf("%d" "%d", a, b);
	return (0);
}
