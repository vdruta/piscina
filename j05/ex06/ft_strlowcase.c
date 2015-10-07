#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	char str[] = "aAbcdEf Ala Bala PORTOCALA";

	printf("%s", ft_strlowcase(str));
	return (0);
}
