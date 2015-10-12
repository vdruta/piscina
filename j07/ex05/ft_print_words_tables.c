void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
