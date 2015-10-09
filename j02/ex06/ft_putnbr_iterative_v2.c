void    ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long	n;
	int	i;
	char	str[100];

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	if (n == 0)
		ft_putchar('0');
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(str[i]);
}
