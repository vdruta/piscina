#include "sudoku.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strlen_map(int argc, char **argv)
{
	int i;
	int len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = len + ft_strlen(argv[i]);
		i++;
	}
	return (len);
}

char	**ft_create_map(int argc, char **argv)
{
	int	i;
	char	**tab;
	int	j;
	int	k;

	i = 1;
	k = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ft_strlen_map(argc, argv) + 1)) == NULL)
		return (0);
	while (i < argc)
	{
		j = 0;
		if ((tab[k] = (char*)malloc(sizeof(char) * ft_strlen(argv[i]) + 1)) == NULL)
			return (0);
		while (argv[i][j])
		{
			tab[k][j] = argv[i][j];
			j++;
		}
		tab[k][j] = '\0';
//		if (j != 9)
//		{
//			write(1, "Erreurj\n", 8);
//			return (0);
//		}
		k++;
		i++;
	}
//	tab[k] = 0;
//	if (i != 10)
//	{
//		write(1, "Erreuri\n", 8);
//		return (0);
//	}
	return (tab);
}

int	ft_validate_map_chars(char **tab)
{
	int	i;
	int	j;
	
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!((tab[i][j] >= '0' && tab[i][j] <= '9') || tab[i][j] == '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char **tab;

	tab = ft_create_map(argc, argv);
	printf("%d", ft_validate_map_chars(tab));

	return (0);
}
