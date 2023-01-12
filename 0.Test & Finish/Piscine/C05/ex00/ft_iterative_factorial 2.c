/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:26:10 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/19 12:04:33 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		i;
	long	final;

	final = nb;
	i = 1;
	if (0 < nb)
	{
		while (i < nb)
		{	
			final = final * i;
			i++;
		}
		return (final);
	}
	if (nb == 0)
		return (1);
	else
		return (0);
}
