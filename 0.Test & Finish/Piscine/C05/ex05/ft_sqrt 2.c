/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:08:07 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 11:46:54 by ngriveau         ###   ########.fr       */
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
		if (nb == (carre))
		{
			return (basecarre);
		}
	basecarre++;
	carre = basecarre;
	carre = carre * carre;
	}
	return (0);
}
