/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pc_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:27:16 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/21 11:47:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base_pc_x(unsigned long nbr, char *base)
{
	if (nbr < 16)
		write (1, &base[nbr], 1);
	else
	{
		ft_print_base_pc_x(nbr / 16, base);
		ft_print_base_pc_x(nbr % 16, base);
	}
}

int	ft_pc_x(long nbr, char *base, int nbrch)
{
	unsigned long	nb;

	nb = (unsigned long) nbr;
	ft_print_base_pc_x(nb, base);
	return (ft_len_nbr_pc_x(nb, nbrch));
}

int	ft_len_nbr_pc_x(unsigned long nbr, int nbrch)
{	
	if (nbr == 0)
		return (1);
	while (0 < nbr)
	{
		nbr = nbr / 16;
		nbrch++;
	}
	return (nbrch);
}
