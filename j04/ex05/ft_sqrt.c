#include <stdio.h>

int	ft_sqrt(int nb)
{
	int x;

	x = 0;
	while (x * x <= nb)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}

int	main(void)
{
	printf("%d", ft_sqrt(100000000));
	return (0);
}
