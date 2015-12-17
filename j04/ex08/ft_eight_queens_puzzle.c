/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:17:15 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/17 18:10:01 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_mod(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}

int		ft_valid(int vf, int *tab)
{
	int	i;

	i = 0;
	while (i < vf)
	{
		if (tab[i] == tab[vf])
			return (0);
		if (ft_mod(tab[i], tab[vf]) == ft_mod(i, vf))
			return (0);
		i++;
	}
	return (1);
}

void	ft_back(int vf, int *tab, int *ok)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		tab[vf] = i;
		if (ft_valid(vf, tab))
		{
			if (vf == 7)
				(*ok)++;
			else
				ft_back(vf + 1, tab, ok);
		}
		i++;
	}
}

int		ft_eight_queens_puzzle(void)
{
	int	tab[8];
	int	ok;
	
	ok = 0;
	ft_back(0, tab, &ok);
	return (ok);
}

int		main(void)
{
	int x;

	x = ft_eight_queens_puzzle();
	printf("%d", x);
	return (0);
}
