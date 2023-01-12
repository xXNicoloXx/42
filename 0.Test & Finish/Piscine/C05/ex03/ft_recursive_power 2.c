/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:53:17 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 11:52:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{	
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (0 < power)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
