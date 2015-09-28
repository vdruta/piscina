void    ft_putchar(char c);

void	ft_test_combinations(int i, int j, int k)
{
	if (i < j && j < k)
	{

		if (i == '7' && j == '8' && k == '9')
		{
			ft_putchar(i);
			ft_putchar(j);
			ft_putchar(k);
		}
		else
		{
			ft_putchar(i);
			ft_putchar(j);
			ft_putchar(k);
			ft_putchar(',');
			ft_putchar(' ');
		}
	}

}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '7')
	{
		while (j <= '8')
		{
			while (k <= '9')
			{
				ft_test_combinations(i, j, k);
				k++;
			}
			j++;
			k = '0';
		}
		i++;
		j = '0';
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
