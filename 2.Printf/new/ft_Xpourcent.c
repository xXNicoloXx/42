/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xpourcent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:27:16 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/20 17:24:21 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rec(long int nbr, char *base)
{
	if (nbr < 16)
		write (1, &base[nbr], 1);
	else
	{
		ft_rec(nbr / 16, base);
		ft_rec(nbr % 16, base);
	}
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	long int	nb;

	nb = (long int)nbr;
	len = 16;
	if (!(len == 0 || len == 1))
	{
		if (nb < 0)
		{
			//nb = -nb;
			//write(1, "-", 1);
		}
		ft_rec(nb, base);
	}
}
