/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:27:16 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/16 16:50:05 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_rec(long int nbr, int len, char *base)
{
	if (nbr < len)
		write (1, &base[nbr], 1);
	else
	{
		ft_rec(nbr / len, len, base);
		ft_rec(nbr % len, len, base);
	}
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	int			len;
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
		ft_rec(nb, len, base);
	}
}
