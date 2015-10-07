#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] -s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char s1[] ="xxxa";
	char s2[] ="xxxA";
	char c;
	char d;

	c = 'a';
	d = 'A';
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d", c - d);
	return (0);
}
