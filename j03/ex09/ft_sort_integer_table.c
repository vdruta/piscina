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

int	main(void)
{
	int tab[5] = {10, 7, 9, 0, 11};
	int l;

	l = 5;
	ft_sort_integer_table(tab, l);
	return (0);
}
