/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:08:13 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:38 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	long int	carre;
	int			basecarre;

	carre = 0;
	basecarre = 0;
	while (carre <= nb)
	{
	basecarre++;
	carre = basecarre;
	carre = carre * carre;
	}
	return (basecarre);
}

int	ft_is_prime(int nb)
{
	int	sqrt;
	int	i;

	i = 2;
	sqrt = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	while (i < sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (ft_is_prime(nb) == 0)
	{
		nb++;
	}
	return (nb);
}
