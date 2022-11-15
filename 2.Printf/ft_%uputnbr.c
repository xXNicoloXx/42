/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:46:43 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/07 17:39:48 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pourcentu(unsigned long nb)
{
	if (nb < 10)
	{
			nb = nb + 48;
			write(1, &nb, 1);
	}
	else
	{
		ft_pourcentu(nb / 10);
		ft_pourcentu(nb % 10);
	}
}
