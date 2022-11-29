/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:28:16 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/21 19:53:57 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_non_print(unsigned char str)
{
	char	*base;

	base = "0123456789abcdef";
	if (str < 16)
		write(1, &base[str], 1);
	else
	{
		ft_non_print(str / 16);
		ft_non_print(str % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (31 < str[i] && str[i] < 127)
		{
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			write(1, "\\", 1);
			if (0 < str[i] && str[i] < 16)
				write(1, "0", 1);
			ft_non_print(str[i]);
			i++;
		}
	}
}
