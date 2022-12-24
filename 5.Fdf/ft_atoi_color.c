/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:49:25 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/11 11:18:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"


int	ft_atoi_color(const char *str, int x, int y, t_map *m)
{
	int	i;
	int j;
	int	signe;
	int	nb;
	int nbrcolor;

	signe = 1;
	i = 0;
	nb = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -signe;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == ',')
	{
		j = 0;
		i += 3;
		nbrcolor = 0;
		while (str[i + j] != ' ' && str[i + j + 1] != '\0')
			j++;
		while (j)
		{
			if ('0 ' <= str[i] && str[i] <= '9')
				nbrcolor += (str[i] - '0') * pow(16 , j-1);
			else if ('a' <= str[i] && str[i] <= 'f')
				nbrcolor += (str[i] - 87) * pow(16, j-1);
			i++;
			j--;
		}
		m->initm[y][x].color = nbrcolor;

	}
	else
		m->initm[y][x].color = -1;
	return (nb * signe);
}
// may la boss

// int main(void)
// {
// 	char *test = "    +286543554s";
// 	printf("%d\n", ft_atoi(test));
// 	printf("%d", atoi(test));
// }