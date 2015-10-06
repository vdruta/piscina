#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int i;
	int t;

	i = 1;
	t = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (i <= power)
		{
			t = t * nb;
			i++;
		}
		return (t);
	}
}

int	main(void)
{
	printf("%d", ft_iterative_power(7, 4));
	return (0);
}
