/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipourcent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:46:43 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/18 20:09:07 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_putchar(char c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < -2147483647)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
		return ;
	}	
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}	
	if (nb < 10)
		ft_putchar(nb);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int ft_pourcent_i(int nbr, int nbrch)
{
	ft_putnbr(nbr);
	if (nbr <= 0)
		nbrch++;
	while (0 < nbr)
	{
		nbr = nbr / 10;
		nbrch++;
	}
	return (nbrch);
	
}
