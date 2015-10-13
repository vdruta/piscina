#include "ft_stock_par.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(char *str)
{
	int	i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(dest) * ft_strlen(str) + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*acav;
	int			i;

	i = 0;
	acav = (t_stock_par*)malloc(sizeof(acav) * (ac + 1));
	while (i < ac)
	{
		acav[i].size_param = ft_strlen(av[i]);
		acav[i].str = av[i];
		acav[i].copy = ft_strdup(av[i]);
		acav[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	acav[i].str = 0;
	return(acav);
}
