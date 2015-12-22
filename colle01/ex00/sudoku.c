#include "sudoku.h"

int	ft_valid_possibility(int vfi, int vfj, char **tab)
{
	int i;
	int j;

	/* check in line*/
	j = 0;
	while (j < vfj)
	{
		if (tab[vfi][j] == tab[vfi][vfj])
			return (0);
		j++;
	}
	j++;
	while (j < 9)
	{
		if (tab[vfi][j] == tab[vfi][vfj])
			return (0);
		j++;
	}
	/* check in column*/
	i = 0;
	while (i < vfi)
	{
		if (tab[i][vfj] == tab[vfi][vfj])
			return (0);
		i++;
	}
	i++;
	while (i < 9)
	{
		if (tab[i][vfj] == tab[vfi][vfj])
			return (0);
		i++;
	}
	/* check small square*/
	i = (vfi / 3) * 3;
	j = (vfj / 3) * 3;
	while (i < 3 * ((vfi / 3) + 1))
	{
		j = (vfj / 3) * 3;
		while (j < 3 * ((vfj / 3) + 1))
		{
			if (tab[i][j] == tab[vfi][vfj] && i != vfi && j != vfj)
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

int	ft_tab_contains_only_1_to_9(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_back(int vfi, int vfj, char **tab, int *ok)
{
	char	c;
	int	i;
	int	j;

	c = '1';
	while (c <= '9')
	{
		tab[vfi][vfj] = c;
		if (ft_valid_possibility(vfi, vfj, tab))
		{
			if (ft_tab_contains_only_1_to_9(tab))
			{
				(*ok)++; //count number of valid sudokus.
				i = 0;
				while (tab[i])
				{
					j = 0;
					while (tab[i][j])
					{
						write(1, &tab[i][j], 1);
						write(1, " ", 1);
						j++;
					}
					write(1, "\n", 1);
					i++;
				}
			}
			else
				ft_go_next(vfi, vfj + 1, tab, ok);
		}
		c++;
	}
	tab[vfi][vfj] = '.';
}

void	ft_go_next(int vfi, int vfj, char **tab, int *ok)
{
	if (vfj == 9)
	{
		vfi++;
		vfj = 0;
	}
	while (tab[vfi][vfj] != '.' && vfi < 9)
	{
		vfj++;
		if (vfj == 9)
		{
			vfi++;
			vfj = 0;
		}
	}
	if (vfi < 9)
		ft_back(vfi, vfj, tab, ok);
}

int	main(int argc, char**argv)
{
	int i;
	int j;
	char **tab;
	int ok;

	ok = 0;
	i = 1;
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	tab = (char**)malloc(sizeof(*tab) * argc);
	while (i < argc)
	{
		tab[i - 1] = argv[i];
		i++;
	}
	tab[i - 1] = 0;
	ft_go_next(0, 0, tab, &ok);
	if (ok != 1) //TODO print from main 
		write(1, "Erreur\n 1+ solutions", 20);
	return (0);
}
