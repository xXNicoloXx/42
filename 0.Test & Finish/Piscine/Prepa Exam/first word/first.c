/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:15:58 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/21 12:53:24 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_first(char *pha)
{
	int	i;

	i = 0;
	while(pha[i] == 32 || pha[i] == 9)
	{
		i++;
	}
	while((pha[i] != 9) && (pha[i] != 32) && (pha[i] != '\0'))
	{
		write(1, &pha[i], 1);
		i++;
	}


}




int	main(int c, char **v)
{
	printf("c = %d\n", c);
	if (c == 2)
		ft_first(v[1]);
}
