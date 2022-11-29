/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:37:09 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/21 14:10:58 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_last(char *v)
{
	int	i;

	i = 0;
	while (v[i] != '\0')
		i++;
	i--;
	printf("i = %d\n", i);
	while (v[i] == ' ' || v[i] == '\t' )
		i--;
	
	printf("i = %d\n", i);
	while (v[i] != ' ' &&  v[i] != '\t' )
		i--;	
	printf("i = %d\n", i);
	i++;
	while (v[i] != ' ' &&  v[i] != '\t' )
	{
		write(1, &v[i], 1);
		i++;
	}
}

int	main(int c, char **v)
{
	if (c == 2)
		ft_last(v[1]);

}
