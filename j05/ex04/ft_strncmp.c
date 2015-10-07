#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char		s1[] ="xxxads";
	char		s2[] ="xxxAsd";
	unsigned int	n;
	char		c;
	char		d;

	n = 4;
	c = 'a';
	d = 'A';
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d", c - d);
	return (0);
}
