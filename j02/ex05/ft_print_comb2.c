void    ft_putchar(char c);

void	ft_write(char a, char b, char c, char d)
{
	if (a == '9' && b =='8' && c == '9' && d == '9')
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(d);
	}
	else
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(d);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_check(char a, char b, char c, char d)
{
	if (a < c)
	{
		ft_write(a, b, c, d);
	}
	else
	{
		if (a == c && b < d)
		ft_write(a, b, c, d);
	}
}

void	ft_print_all(char a, char b, char c, char d)
{
	while (a <= '9')
	{
		while (b <= '9')
		{
			while (c <= '9')
			{
				while (d <= '9')
				{
					ft_check(a, b, c, d);
					d++;
				}
				c++;
				d = '0';
			}
			b++;
			c = '0';
		}	
		a++;
		b = '0';
	}
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	ft_print_all(a, b, c, d);
}
