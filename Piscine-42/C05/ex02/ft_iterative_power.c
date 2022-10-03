/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:06:43 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 11:58:42 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_iterative_power(int nb, int power)
{	
	int	test;

	test = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (1 < power)
	{
		nb = nb * test;
		power--;
	}
	return (nb);
}
