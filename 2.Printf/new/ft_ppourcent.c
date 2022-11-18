/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:37:14 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/18 19:41:37 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pourcentP(unsigned long nbr, int nbrch)
{
	if (nbr == 0)
	{
		ft_writestr("(nil)", nbrch);
		return (nbrch + 5);
    }
	ft_writestr("0x", nbrch);
    ft_print_pourcent_base(nbr, nbrch);
	if (nbr == 0)
		return (nbrch + 5);
	else
		return (nbrch + 14);
		 
}	
int	ft_print_pourcent_base(unsigned long nbr, int nbrch)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		nbrch = nbrch + ft_writechar(base[nbr], nbrch);
	}
	else
	{
		ft_print_pourcent_base(nbr / 16, nbrch);
		ft_print_pourcent_base(nbr % 16, nbrch);
		
	}
	return (nbrch);

}