/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:12:57 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/10 11:53:33 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	tps;
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= size && j <= size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tps = tab[i];
				tab[i] = tab[j];
				tab[j] = tps;
				j = size + 2;
				i = 0;
			}
		j++;
		}	
	i++;
	j = i + 1;
	}
}
