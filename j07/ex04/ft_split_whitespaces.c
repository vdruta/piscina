#include <stdlib.h>
#include <stdio.h>

int	ft_strlen_tw(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_strlen_w(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	char	**mat;
	int	i;
	int	j;
	int	k;

	mat = malloc(sizeof(char*) * ft_strlen_tw(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			k = 0;
			mat[j] = malloc(sizeof(char) * ft_strlen_w(str, i) + 1);
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			{
				mat[j][k] = str[i];
				i++;
				k++;
			}
			mat[j][k] = '\0';
			j++;
		}
	}
	mat[j] = 0;
	return (mat);
}

int	main()
{
	char str[100] = "Ia sa vedem cat de bine	merge \t acest\n	program";
	char **mat;
	int i;

	mat = ft_split_whitespaces(str);
	i = 0;
	while (mat[i])
	{
		printf("%s", mat[i]);
		i++;
	}
	return (0);
}
