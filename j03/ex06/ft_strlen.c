#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;	
	}
	return (i);
}

int	main(void)
{
	char *str;
	
	str = "abcdefg";
	printf("%d", ft_strlen(str));
	return (0);
}
