void    ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
