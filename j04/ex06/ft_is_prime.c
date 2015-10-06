#include <stdio.h>

int	ft_is_prime(int nb)
{
	int i;
	
	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb) //it also works if (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	printf("%d", ft_is_prime(1299827));
	return (0);
}
