/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:34:02 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/21 17:05:53 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


void	ft_inter(char **v)
{
	int	i;
	int	j;
	int	leni;
	int	lenj;
	char	lettre;
	int	verif;

	verif = 0;
	
	leni = lenstr(v[1]);
	lenj = lenstr(v[2]);
	
	i = 0;
	j = 0;
	while(i < leni)
	{
		if (v[1][i] != '\0')
		{
			lettre = v[1][i];
			while(i < leni)
			{
				if (lettre == v[1][i])
					v[1][i] = '\0';
				i++;
			}
			i = 0;
			while (j < lenj) 
			{
				if (lettre == v[2][j])
				{
					verif = 1;
					v[2][j] = '\0';
				}
				j++;
			}
			j = 0;
			if (verif == 1)
			{
				verif = 0;
				write (1, &lettre, 1);
			}
			
		}
		else
			i++;
	}
}


int	main(int c, char **v)
{
	if(c == 3)
		ft_inter(v);
}
