#include <stdio.h>

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char str1[] = "abc";
	char str2[] = "defghijklmn";
	
	printf("%s", ft_strncat(str1, str2, 3));
	return (0);
}
