/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:41 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/10 12:10:35 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{	
	int	i;

	i = 0;
	while (!(str[i] == '\0'))
	{
		write(1, &str[i], 1);
		i++;
	}
}
