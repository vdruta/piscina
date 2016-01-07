/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:37:34 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/07 13:44:49 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_a;
char *g_p;
char g_array[2048];

void	ft_solve(char c)
{
	int ok;

	ok = 0;
	if (c == '[')
	{
		while (*g_a)
		{
			if (*g_a == '[')
				ok++;
			if (*g_a == ']')
				ok--;
			if (ok == 0)
				return ;
			g_a++;
		}
	}
	else
	{
		while (*g_a)
		{
			if (*g_a == ']')
				ok++;
			if (*g_a == '[')
				ok--;
			if (ok == 0)
				return ;
			g_a--;
		}
	}
}

void	ft_interpret(char c)
{
	if (c == '>')
		g_p++;
	else if (c == '<')
		g_p--;
	else if (c == '+')
		*g_p = *g_p + 1;
	else if (c == '-')	
		*g_p = *g_p - 1;
	else if (c == '.')
		write(1, g_p, 1);
	else if (c == '[')
	{
		if (*g_p == 0)
			ft_solve('[');
	}	
	else if (c == ']')
	{
		if (*g_p != 0)
			ft_solve(']');
	}	
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		g_a = argv[1];
		g_p = g_array;
		while (*g_a)
		{
			ft_interpret(*g_a);
			g_a++;
		}	
	}
}
