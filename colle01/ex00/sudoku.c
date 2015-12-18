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
void	ft_back(int vfi, int vfj, char **tab)
{
	char c;
	int i;
	

	ft_find_a_free_spot(&vfi, &vfj, tab);
	c = '1';
	while (c <= '9')
	{
		tab[vfi][vfj] = c;
		if (ft_valid_possibility(vfi, vfj, tab))
		{
			printf("%c", c);
			if (ft_tab_contains_only_1_to_9(tab))
			{
				ft_putendl("done");
				i = 0;
			}
			else
			{
				vfj++;
				if (vfj == 9)
				{
					vfi++;
					vfj = 0;	
				}
				ft_back(vfi, vfj, tab);
			}
		}
		c++;
	}
}

int	main(int argc, char**argv)
{
	int i;
	int j;
	char **tab;
	
	i = 1;
	if (argc != 10)
		write(1, "Erreur\n", 7);
	tab = (char**)malloc(sizeof(*tab) * argc);
	while (i < argc)
	{
		tab[i - 1] = argv[i];
		i++;
	}
	tab[i - 1] = 0;
	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}

	ft_back(0, 0, tab);
	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
	return (0);
}
