#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	long	rez;
	int	rez2;

	i = 0;
	s = 1;
	rez = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		rez = rez * 10 + str[i] -'0';
		i++;
	}
	rez2 = rez * s;
	return (rez2);
}

int	main(void)
{
	char str[] = "    -2147483648";

	printf("%d", ft_atoi(str));
	return (0);
}
