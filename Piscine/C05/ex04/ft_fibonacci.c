/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:42:42 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 14:52:08 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{	
	int	valeur;

	if (index < 0)
		return (-1);
	if (0 <= index)
		valeur = 0;
	if (1 <= index)
		valeur = 1;
	if (2 <= index)
		valeur = 1;
	if (3 <= index)
	{
		valeur = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (valeur);
}
