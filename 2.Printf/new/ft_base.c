/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:35:30 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/18 20:16:52 by nicolasgriv      ###   ########.fr       */
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


		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
		}
		ft_rec(nb, base);
}