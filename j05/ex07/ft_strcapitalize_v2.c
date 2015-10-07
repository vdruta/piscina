#include <stdio.h>

int		ft_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && !ft_is_alpha(str[i - 1]))
			str[i] = str[i] - 32;
		if (str[i] >= 'A' && str[i] <= 'Z' && ft_is_alpha(str[i - 1]))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "salut, ce faci? 42cuvinte patruzeci-doi; cincizeci+si+unu";

	printf("%s", ft_strcapitalize(str));
	return (0);
}
