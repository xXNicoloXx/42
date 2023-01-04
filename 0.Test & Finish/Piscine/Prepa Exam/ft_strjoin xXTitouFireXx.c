/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:37:46 by tchevrie          #+#    #+#             */
/*   Updated: 2022/07/19 17:32:19 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_counter(int size, char **strs, char *sep)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	count = count + i * (size - 1);
	return (count);
}

void	ft_string_sep(char *m, int *k, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		m[*k] = sep[i];
		(*k)++;
		i++;
	}
}

void	ft_chain_linker(int size, char *m, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			m[k] = strs[i][j];
			j++;
			k++;
		}
		if (i < size - 1)
			ft_string_sep(m, &k, sep);
		i++;
	}
	m[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*m;

	if (size < 1)
	{
		m = malloc(sizeof(char));
		*m = '\0';
		return (m);
	}
	m = malloc (sizeof(char) * ft_counter(size, strs, sep) + 1);
	ft_chain_linker(size, m, strs, sep);
	return (m);
}
