/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnico.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:16:31 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/26 10:21:35 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	separateur(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	nbrmot(char *str, char *charset)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (str[i] != '\0')
	{
		while (separateur(str[i], charset) == 0 && str[i] != '\0')
			i++;
		if (separateur(str[i], charset) == 1 && str[i] != '\0')
			comp++;
		while (separateur(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	return (comp);
}

int	ftlenmot(char *str, char *charset)
{
	int	i;
	int	lenmot;

	lenmot = 0;
	i = 0;
	while (separateur(str[i], charset) == 0 && str[i] != '\0')
		i++;
	while (separateur(str[i], charset) == 1 && str[i] != '\0')
	{
		i++;
		lenmot++;
	}
	return (lenmot);
}

char	*word(char *str, char *charset)
{
	int		i;
	int		j;
	char	*mot;

	i = 0;
	j = 0;
	mot = malloc(sizeof(char) * ftlenmot(str, charset) + 1);
	while (separateur(str[i], charset) == 0 && str[i] != '\0')
	{
		i++;
	}
	while (separateur(str[i], charset) == 1 && str[i] != '\0')
	{
		mot[j] = str[i];
		i++;
		j++;
	}
	mot[j] = '\0';
	return (mot);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**tab;

	i = 0;
	j = 0;
	size = nbrmot(str, charset);
	tab = malloc(sizeof(char *) * (size + 1));
	while (str[i] != '\0')
	{
		while (separateur(str[i], charset) == 0 && str[i] != '\0')
			i++;
		if (separateur(str[i], charset) == 1 && str[i] != '\0')
		{
			*(tab + j) = word((str + i), charset);
			j++;
		}
		while (separateur(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}

int main (int c, char **v)
{
    char **tab;
    if (c == 3)
    {
       tab = ft_split(v[1], v[2]);
        printf("%s\n", tab[0]);
        printf("%s\n", tab[1]);
        printf("%s\n", tab[2]);
        printf("%s\n", tab[3]);
        printf("%s\n", tab[4]);
        printf("%s\n", tab[5]);
        printf("%s\n", tab[6]);
        printf("%s\n", tab[7]);
    }


}