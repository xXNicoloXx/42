/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/09 18:25:30 by ngriveau         ###   ########.fr       */
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

int	ftcount(int i, int j, const char *s1, const char *set)
{
	int	count;

	count = ft_strlen(s1);
	j = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (set[j] != '\0' && i > 0)
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ftmymalloc(int count, char *str)
{
	if (count <= 0)
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		printf("count = %d", count);
		str = malloc(sizeof(char) * count);
		if (str == NULL)
			return (NULL);
		str[count - 1] = '\0';
	}
	return (str);
}

int	ftmyi(int i, int j, const char *s1, const char *set)
{
	while (set[j] != '\0' && i > 0)
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
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
	count = ftcount(i, j, s1, set);
	i = ftmyi(i, j, s1, set);
	str = ftmymalloc(count, str);
	if (count <= 0)
		return (str);
	while (count)
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
//     printf("|%s|\n",ft_strtrim("1111231321321", "123"));
// }