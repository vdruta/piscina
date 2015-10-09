#include <stdio.h>

int	ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ( base[i] == '+' || base[i] == '-')
			return (0);
		if ( base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_str(char *str, char *base)
{
	int i;
	int j;
	int ok;

	i = 0;
	j = 0;
	ok = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			ok = ok + 1;
		while (base[j])
		{
			if (str[i] == base[j])
				ok = ok + 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (i != ok)
		return (0);
	return (1);
}

int	get_nbr(char *str, char *base, int i)
{
	int nb;
	int j;

	nb = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				nb *= 10;
				nb += j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (nb);
}

int	ft_power(int nb, int power)
{
	int res;

	res = 1;
	if (power == 0)
		return (1);
	while (power)
	{
		res *= nb;
		power--;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int s;
	int nbr;
	int nbr_final;
	int size_base;

	i = 0;
	s = 1;
	nbr_final = 0;
	size_base = 0;
	if (ft_check_str(str, base) && ft_check_base(base))
	{
		while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32)
			i++;
		if (str[i] == '-')
		{
			s = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		nbr = get_nbr(str, base, i);
		while (base[size_base])
			size_base++;
		i = 0;
		nbr *= 10;
		while ((nbr /= 10) > 0)
			nbr_final += (nbr % 10) * ft_power(size_base, i++);
	}
	return (nbr_final * s);
}

int	main (void)
{
	char str[] = "-eqweq";
	char base[] = "qwerty";

	printf("%d", ft_check_str(str, base));
	printf("\n");
	printf("%d", ft_check_base(base));
	printf("\n");
	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
