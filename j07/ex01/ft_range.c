#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;
	
	if (min >= max)
		return (NULL);
	tab = (int*)malloc(sizeof(*tab) * (max - min) + 1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

void	ft_putnbr(int a)
{
	char	*str;
	int	i;
	long	nbr;

	i = 0;
	nbr = a;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr == 0)
		write(1, "0", 1);
	while (nbr > 0)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	main(void)
{
	int a;
	int b;
	int *tab;
	int i;

	a = -10;
	b = 42;
	tab = ft_range(a, b);
	i = 0;
	while (i < b - a)
	{
		ft_putnbr(tab[i]);
		write(1, " ", 1);
		i++;
	}
	return (0);
}
