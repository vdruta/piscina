void	ft_putchar(char c);

int	ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base [1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		j = 0;	
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int	fin_nbr[100];
	int	i;
	long	baselen;

	n = nbr;
	i = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	if(ft_checkbase(base))
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n == 0)
			ft_putchar(base[0]);
		while (n > 0)
		{	
			fin_nbr[i] = n % baselen;
			n = n / baselen;
			i++;
		}
		i--;
		while (i >= 0)
		{
			ft_putchar(base[fin_nbr[i]]);
			i--;
		}
	}
}

int	main()
{
	ft_putnbr_base(-2147483648, "0123456789");
	return (0);
}
