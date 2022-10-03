/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:22:13 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/24 22:50:29 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush2.h"

int	ft_ifnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*no_zero_bro(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] == '0')
		i++;
	return (&nbr[i]);
}

int	main(int argc, char **argv )
{
	t_dictionary	*dict;
	int				output;

	output = 0;
	if (argc > 1 && argc < 4 && ft_ifnbr(argv[1]) == 1)
	{
		if (argc == 2)
			dict = generate_dict("numbers.dict");
		else if (argc == 3)
			dict = generate_dict(argv[2]);
		if (dict == NULL || !can_dict_print_nb(argv[1], dict))
			output = ft_putstr("Dict Error\n");
		else
		{
			printnbr(no_zero_bro(argv[1]), dict);
			write(1, "\n", 1);
		}
		free_tab(dict);
	}
	else
		output = ft_putstr("Error\n");
	return (output);
}
