/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/14 16:54:34 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftcountpt2(int i, int j, const char *s1, const char *set)
{
	j = 0;
	while (set[j] != '\0')
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

static int	ftcount(int i, int j, const char *s1, const char *set)
{
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
	i++;
	return (i);
}

static char	*ftmymalloc(int count, char *str)
{
	free(str);
	if (count <= 0)
	{
		str = malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		//printf("count = %d", count);
		str = malloc(sizeof(char) * count + 1);
		if (str == NULL)
			return (NULL);
		str[count] = '\0';
	}
	return (str);
}

static int	ftmyi(int i, int j, const char *s1, const char *set)
{
	//printf("\t\t%d%d\n",i,j);
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	//printf("i = %d \n",i);
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
	count = ftcount(i, j, s1, set) - ftcountpt2(i, j, s1, set);
	//printf("count = %d\n", count);
	i = ftmyi(i, j, s1, set);
	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
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
//     printf("|%s|\n",ft_strtrim("   xxxtripouille", " x"));
// }