/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:43 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/13 19:00:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_len(char *strfind)
{
	int	i;

	i = 0;
	while (strfind[i] != '\0')
		i++;
	return (i);
}

int	ft_while(char *str, char *to_find, int j, int i)
{
	int	verif;
	int	len;

	verif = 0;
	len = ft_len(to_find);
	while (j < len)
	{
		if (str[i + j] != to_find[j])
			break ;
		else
			verif++;
		j++;
	}
	return (verif);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_len(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			if (ft_while(str, to_find, j, i) == len)
				return (&str[i]);
		}	
	i++;
	}
	return (NULL);
}
