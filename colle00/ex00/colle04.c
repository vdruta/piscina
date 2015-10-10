void	ft_putchar(char c);

void	ft_top(int x)
{
	int j;

	j = 0;
	while (j <= x - 1)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		j++;
	}
}

void	ft_bottom(int x)
{
	int j;

	j = 0;
	while (j <= x - 1)
	{

		if (j == 0)
			ft_putchar('C');
		else if (j == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
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
			ft_putchar('B');
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

		if (i == 0)
		{
			ft_top(x);
			ft_putchar('\n');
		}
		else if (i == y - 1)
		{
			ft_bottom(x);
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
