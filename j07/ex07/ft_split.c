#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(char *str, char *charset, int i)
{
	int j;
	
	j = 0;
	while (str[i] && charset[j] && str[i] == charset[j])
	{
		i++;
		j++;
	}
	if (j == ft_strlen(charset))
		return (1);
	else
		return (0);
}

int	ft_strlen_tw(char *str, char *charset)
{
	int i;
	int len;
	
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && (ft_check(str, charset, i) == 1))
			i = i + ft_strlen(charset);
		while (str[i] && (ft_check(str, charset, i) == 0))
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	ft_strlen_w(char *str, char *charset, int i)
{
	int len;
	int j;

	len = 0;
	j = 0;
	while (str[i] && charset[j] && !ft_check(str, charset, i))
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**mat;
	int	i;
	int	j;
	int	k;

	if ((mat = (char**)malloc(sizeof(char*) * ft_strlen_tw(str, charset) + 1)) == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (ft_check(str, charset, i) == 1))
			i = i + ft_strlen(charset);
		if (str[i])
		{
			k = 0;
			if ((mat[j] = (char*)malloc(sizeof(char) * ft_strlen_w(str, charset, i) + 1)) == NULL)
				return (0);
			while (str[i] && (ft_check(str, charset, i) == 0))
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

int	main(void)
{
	char str[99] = "abcDDdefgDD";
	char charset[99] = "DD";
	int i;
	char **mat;

//	printf("%d\n", ft_check(str, charset, 9));
//	printf("%d\n", ft_strlen_tw(str, charset));
	i = 0;
	mat = ft_split(str, charset);
	while (mat[i])
	{
		printf("%s\n", mat[i]);
		i++;
	}
	return (0);
}
