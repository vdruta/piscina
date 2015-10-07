#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int i;
	int j;

	len = 0;
	while (to_find[len])
	{
		len++;
	}
	if (len == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j + 1 == len)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int	main()
{
	char str[] = "abcDEFghijklmDEFnopqrstuvwxyz";
	//char fnd[] = "";
	char fnd[] = "DEF";
	printf("%s", ft_strstr(str, fnd));
	return (0);
}
