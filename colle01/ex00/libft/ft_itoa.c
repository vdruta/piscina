/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:32:54 by vdruta            #+#    #+#             */
/*   Updated: 2015/11/02 14:40:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_skip_sign(char *dst, char *str, int i)
{
	size_t j;

	j = 0;
	while (j < ft_strlen(str))
	{
		dst[j] = str[i];
		i--;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

static char		*ft_char_strrev(char c, char *str)
{
	int		i;
	size_t	j;
	char	*dst;

	dst = (char*)malloc(sizeof(*dst) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
		i++;
	j = 1;
	i--;
	if (c == '-')
	{
		dst[0] = c;
		while (j <= ft_strlen(str))
		{
			dst[j] = str[i];
			i--;
			j++;
		}
		dst[j] = '\0';
		return (dst);
	}
	else
		return (ft_skip_sign(dst, str, i));
}

static long		ft_nsize(long nb)
{
	long size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size = 1;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size = size + 1;
		nb = nb / 10;
	}
	return (size);
}

static char		*ft_nb_is_zero(char *v)
{
	v[0] = '0';
	v[1] = '\0';
	return (v);
}

char			*ft_itoa(int n)
{
	char	*v;
	int		i;
	char	s;
	long	nb;

	nb = n;
	i = 0;
	if (!(v = (char*)malloc(sizeof(*v) * (ft_nsize(nb) + 1))))
		return (NULL);
	s = '+';
	if (nb < 0)
	{
		nb = -nb;
		s = '-';
	}
	if (nb == 0)
		return (ft_nb_is_zero(v));
	while (nb > 0)
	{
		v[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	v[i] = '\0';
	return (ft_char_strrev(s, v));
}
