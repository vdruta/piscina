#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	len;
	int	count;
	char	ascii;

	len = 0;
	count = 0;
	while (str[len])
	{
		len++;
	}
	len = len - 1;
	while (count < len)
	{
		ascii = str[count];
		str[count] = str[len];	
		str[len] = ascii;

		count++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "abcdefg";

	printf("%s / ", str);
	ft_strrev(str);
	printf("%s", str);
	return (0);
}
