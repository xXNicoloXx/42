/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:10 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/10 13:59:16 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aff(char a, char b, char c, char d)
{
	char	e;

	e = ' ';
	if (a == '7' && b == '8' && c == '9')
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, &e, 1);
	}
}

void	nb_print(char a, char b, char c, char d)
{
	if (a != b && a != c && b != c)
	{
		if (b < c)
		{
			if (a < b)
			{
				aff(a, b, c, d);
			}
		}
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = 47;
	b = 47;
	c = 47;
	d = 44;
	while (a < 57)
	{
		a++;
		b = 47;
		while (b < 57)
		{
			b++;
			c = 47;
			while (c < 57)
			{
				c++;
				nb_print(a, b, c, d);
			}
		}
	}
}
