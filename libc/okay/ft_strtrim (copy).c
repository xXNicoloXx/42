/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/09 15:47:22 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\0'))
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = 0;
	j = 0;
	count = ft_strlen(s1);
	while (s1[i] != '\0')
		i++;
	i--;
	while (set[j] != '\0' && count > 0)
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
			count--;
		}
		else
			j++;
	}
	i = 0;
	j = 0;
	while (set[j] != '\0' && count > 0)
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
			count--;
		}
		else
			j++;
	}
	if (count <= 0)
		count = 1;
	str = malloc(sizeof(char) * count);
	if (str == NULL)
		return (NULL);
	j = 0;
	str[count] = '\0';
	while (count > 0)
	{
		str[j] = s1[i];
		i++;
		j++;
		count--;
	}
	return (str);
}

// int main(void)
// {
//     printf("|%s|\n",ft_strtrim("q    wdwdwdw \n \n \n \t  \n  \n dwdwd\t \n   \ndwd \ts", "`"));
// }