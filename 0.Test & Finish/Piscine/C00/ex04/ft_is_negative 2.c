/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negtaive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:10 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/07 14:55:40 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int c)
{
	char	a;

	if (c < 0)
	{
		a = 78;
		write(1, &a, 1);
	}
	if (c >= 0)
	{
		a = 80;
		write(1, &a, 1);
	}
}
