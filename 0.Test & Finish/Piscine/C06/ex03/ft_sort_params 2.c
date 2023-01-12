/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:17:23 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 20:42:45 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <unistd.h>

void	ft_print(int c, char **a)
{
	int	i;
	int	g;

	i = 1;
	g = 0;
	while (i < c)
	{
		while (a[i][g] != '\0')
		{
			write(1, &a[i][g], 1);
			g++;
		}
		g = 0;
		write(1, "\n", 1);
		i++;
	}
}

void	ft_sort(int c, char **a)
{
	int		i;
	int		g;
	int		j;
	char	*temp;

	i = 1;
	g = 0;
	j = 2;
	while (j < c)
	{
		while (a[i][g] == a[j][g])
			g++;
		if (a[i][g] > a[j][g])
		{	
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i = 0;
		}
	g = 0;
	i++;
	j = i + 1;
	}
	ft_print(c, a);
}

int	main(int argc, char **argv)
{
	ft_sort(argc, argv);
}
