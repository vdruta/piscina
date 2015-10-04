#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		if (tab[i % size] > tab[i % size + 1])
			ft_swap(&tab[i % size], &tab[i % size + 1]);
		i++;
	}
}
