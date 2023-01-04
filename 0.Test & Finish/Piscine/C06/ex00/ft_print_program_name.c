/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:49:13 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/14 19:24:51 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

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

int	main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	(void) argc;
}
