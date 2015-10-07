#include <stdio.h>

int	ft_alphabet(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return(0);
}

int	ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_alphabet(str[i]))
			return(0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char str[] = "patruzecisidoi";

	printf("%d", ft_str_is_alpha(str));
	return (0);
}
