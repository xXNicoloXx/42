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

#include <unistd.h>

void	ft_putchar(char c)
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
