void    ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 'z';
	while (i >= 'a')
	{
		ft_putchar(i);
		i--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return(0);
}
