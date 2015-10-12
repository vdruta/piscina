#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	i = 0;
	tab = (int*)malloc(sizeof(*tab) *(max - min));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (tab = NULL)
		return (0);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
