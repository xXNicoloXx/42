/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pc_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:46:43 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/21 11:53:00 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pc_u(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_pc_idu(nb);
	else
	{
		ft_putnbr_pc_u(nb / 10);
		ft_putnbr_pc_u(nb % 10);
	}
}

int	ft_pc_u(unsigned int nbr, int nbrch)
{
	ft_putnbr_pc_u(nbr);
	if (nbr <= 0)
		nbrch++;
	while (0 < nbr)
	{
		nbr = nbr / 10;
		nbrch++;
	}
	return (nbrch);
}
