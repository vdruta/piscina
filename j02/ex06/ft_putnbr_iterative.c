void    ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long	n;
	int	size;

	n = nb;
	size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (n >= 10)
	{
		size = size * 10;
		n = n / 10;	
	}
	n = nb;
	if (n < 0)
		n = -n;
	while (size >= 1)
	{
		ft_putchar(n / size + '0');
		n = n % size;
		size = size / 10;
	}
}
