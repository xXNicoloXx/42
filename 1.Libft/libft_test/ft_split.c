/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:29:02 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/15 14:50:26 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloctab(char const *str, char c)
{
	int		i;
	int		mot;
	char	**tab;

	i = 0;
	mot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			mot ++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}	
	}
	tab = malloc(sizeof(char *) * (mot + 1));
	tab[mot] = '\0';
	return (tab);
}

static char	**ft_mallocmot(char const *str, char **tab, char c)
{
	int	i;
	int	j;
	int	mot;

	i = 0;
	j = 0;
	mot = -1;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j = i;
			mot++;
			while (str[i] != c && str[i] != '\0')
				i++;
			tab[mot] = malloc(sizeof(char) * (i - j + 1));
			tab[mot][i - j] = '\0';
		}
		else
			i++;
	}
	return (tab);
}

static char	**ft_str_to_tab(char const *str, char **tab, char c)
{
	int	i;
	int	j;
	int	mot;

	i = 0;
	j = 0;
	mot = -1;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j = 0;
			mot++;
			while (str[i] != c && str[i] != '\0')
			{
				tab[mot][j] = str[i];
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	tab = ft_malloctab(str, c);
	tab = ft_mallocmot(str, tab, c);
	tab = ft_str_to_tab(str, tab, c);
	return (tab);
}

// int main(void)
// {
// 	int i;
// 	i = 0; 
//     char **tab = ft_split("Tripouille", ' ');
// 	while (i < 2)
// 	{
// 	printf("|%s|\n" , tab[i]);
// 	i++;
// 	}
// 	free(tab[0]);
// 	free(tab[1]);
// 	free(tab);
// }
