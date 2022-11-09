/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:42:06 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/09 11:42:44 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(char *str, int lettre)
{
	int	i;

	i = 0;
	while (str[i] != lettre)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}
// int main (void)
// {
//     char *texte = "ciuyguyguygciuyguygcd";
//     int lettre = 'g';

//     printf("1:%s\n", strchr(texte, lettre));
//     printf("2:%s", ft_strchr(texte, lettre));    
// }
