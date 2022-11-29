/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:58:03 by snaji             #+#    #+#             */
/*   Updated: 2022/07/24 20:47:31 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

int	is_c_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_split_len(char *str, char *charset)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (str[0] == 0)
		return (len);
	if (!is_c_sep(str[0], charset))
		len = 1;
	while (str[i] != 0)
	{
		if (is_c_sep(str[i - 1], charset) && !is_c_sep(str[i], charset))
			len++;
		i++;
	}
	return (len);
}

void	malloc_and_cpy(char *str, char *charset, char **split, int j)
{
	int		i;

	i = 0;
	while (!is_c_sep(str[i], charset) && str[i] != 0)
		i++;
	split[j] = malloc((i + 1) * sizeof(char));
	i = 0;
	while (!is_c_sep(str[i], charset) && str[i] != 0)
	{
		split[j][i] = str[i];
		i++;
	}
	split[j][i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	i = 1;
	split = malloc((get_split_len(str, charset) + 1) * sizeof(char *));
	if (is_c_sep(str[0], charset) == 0)
	{
		malloc_and_cpy(str, charset, split, j);
		j = 1;
	}
	while (str[i] != 0)
	{
		if (is_c_sep(str[i - 1], charset) && !is_c_sep(str[i], charset))
		{
			malloc_and_cpy(&str[i], charset, split, j);
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
