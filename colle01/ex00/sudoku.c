#include "sudoku.h"

int	ft_valid_possibility(int vfi, int vfj, char **tab, char c)
{
	int i;
	int j;

	i = 0;
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
		j = 0;
		i++;
	}
}
void	ft_back(int vfi, int vfj, char **tab)
{
	char c;
	int i;
	
	i = 0;
	ft_find_a_free_spot(&vfi, &vfj, tab);
	c = '1';
	while (c <= '9')
	{
		tab[vfi][vfj] = c;
	//	printf("%c", tab[vfi][vfj]);
		if (ft_valid_possibility(vfi, vfj, tab, c))
		{

			if (vfi == 8 && vfj == 8)
			{
				ft_putendl("done");
				while (tab[i])
				{
					ft_putendl(tab[i]);
					i++;
				}
			}
			else
			{
				vfj++;
				if (vfj == 9)
				{
					vfi++;
					if (vfi == 9)
						exit(0);
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
