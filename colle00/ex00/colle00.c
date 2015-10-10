void	ft_putchar(char c);

void	ft_top_bottom(int x)
{
	int j;

	j = 0;
	while (j <= x - 1)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		j++;
	}
}

void	ft_middle(int x)
{
	int j;

	j = 0;
	while (j <= x - 1)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		j++;
	}
}

void	colle(int x, int y)
{
	int i;

	i = 0;
	while (i <= y - 1)	
	{
		if (i == 0 || i == y - 1)
		{
			ft_top_bottom(x);
			ft_putchar('\n');
		}
		else
		{
			ft_middle(x);
			ft_putchar('\n');
		}
		i++;
	}
}
