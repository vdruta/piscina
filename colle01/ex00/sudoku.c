#include "sudoku.h"

int	ft_valid_possibility(int vfi, int vfj, char **tab)
{
	int i;
	int j;

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
	return (1);
}

void	ft_find_a_free_spot(int *vfi, int *vfj, char **tab)
{
	int i;
	int j;

	i = *vfi;
	j = *vfj;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
			{
				*vfi = i;
				*vfj = j;
				return ;
			}
			j++;
		}
		i++;
	}
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

void	ft_go_next(int vfi, int vfj, char **tab, char **tab2)
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
		ft_back(vfi, vfj, tab, tab2);
}

void	ft_back(int vfi, int vfj, char **tab, char **tab2)
{
	char c;
	int i;
	int x;
	int y;

	x = vfi;
	y = vfj;
	c = '1';
	while (c <= '9')
	{
		tab[vfi][vfj] = c;
		if (ft_valid_possibility(vfi, vfj, tab))
		{
			if (ft_tab_contains_only_1_to_9(tab))
			{
				ft_putendl("done");
				i = 0;
				while (tab[i])
				{
					ft_putendl(tab[i]);
					i++;
				}
				tab2 = tab;
			}
			else
			{
				ft_go_next(vfi, vfj + 1, tab, tab2);
			}
		}
		c++;
	}	
	tab[x][y] = '.';
}

int	main(int argc, char**argv)
{
	int i;
	int j;
	char **tab;
	char **tab2;

	i = 1;
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	tab = (char**)malloc(sizeof(*tab) * argc);
	tab2 = (char**)malloc(sizeof(*tab) * argc);
	while (i < argc)
	{
		tab[i - 1] = argv[i];
		i++;
	}
	tab[i - 1] = 0;
	//print initial tab - just for fun.
	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}

	ft_go_next(0, 0, tab, tab2);

	return (0);
}
