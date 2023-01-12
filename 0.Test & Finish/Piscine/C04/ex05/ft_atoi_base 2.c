/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:11:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/16 23:02:14 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

long int	ft_atoi(char *str, int len, char *base);

int	lenbase(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		while (str[j] != '\0')
		{
			if (((str[i] == str[j] && i != j) || str[i] == '-'
					|| str[i] == '+'
					|| str[i] == ' '
					|| ('\t' <= str[i] && str[i] <= '\r')))
				return (0);
			j++;
		}
	i++;
	j = i + 1;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;

	len = lenbase(base);
	if (!(len == 0 || len == 1))
	{
		return (ft_atoi(str, len, base));
	}
	return (0);
}

int	ft_atoi_verif(char *str, int i)
{	
	while (('\t' <= str[i] && str[i] <= '\r') || (str[i] == ' '))
		i++;
	return (i);
}

long int	ft_atoi(char *str, int len, char *base)
{
	int			i;
	int			j;
	int			signe;
	long int	nb;

	signe = 1;
	j = -1;
	i = 0;
	nb = 0;
	i = ft_atoi_verif(str, i);
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -signe;
	while ((base[++j] != '\0') || (str[i] != '\0' ))
	{
		if (str[i] == base[j])
		{
			nb = nb * len + j;
			j = -1;
			i++;
		}
		if (j == len)
			break ;
	}
	return (nb * signe);
}
