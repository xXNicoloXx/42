/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:49:32 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/21 11:57:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}



void	ft_union(char **v)
{
	int	leni;
	int	i;
	int	lenj;
	int	j;
	char	lettre;

	i = 0;
	j = 0;
	leni = ft_len(v[1]);
	lenj = ft_len(v[2]);
	while (i < (leni))
	{
		if(v[1][i] != '\0')
		{
			write(1, &v[1][i], 1);
			lettre = v[1][i];
			v[1][i] ='\0';
			i++;
			while (i <= leni)
			{
				if (v[1][i] == lettre)
					v[1][i] = '\0';
				i++;
			}
			i++;
			while (j <= lenj)
			{	if (v[2][j] == lettre)
					v[2][j] = '\0';
				j++;
			}
		
		i=0;
		j=0;
		}
		else
			i++;
	}
	j = 0;
	while (j < lenj)
	{
		if (v[2][j] != '\0')
		{
			write(1, &v[2][j], 1);
			lettre = v[2][j];
			v[2][j] ='\0';
			j++;
			while (j <= lenj)
			{
				if (v[2][j] == lettre)
					v[2][j] = '\0';
				j++;
			}
		j = 0;
		}
		else
			j++;
	}
}



int	main(int c, char **v)
{
	if (c == 3)
		ft_union(v);
}
