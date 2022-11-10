/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:29 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 18:33:04 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strchr(char *str, int lettre)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (str[i] != lettre)
	{
		if (str[i] == '\0')
			return (NULL);
		i--;
	}
	return (&str[i]);
}

//  int main (void)
//  {
//      char *texte = "376126521657241627416719781641337638127418";
//      int lettre = '7';

//      printf("1:%s\n", strrchr(texte, lettre));
//      printf("2:%s", ft_strchr(texte, lettre));    
//  }
