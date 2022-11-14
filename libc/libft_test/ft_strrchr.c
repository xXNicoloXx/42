/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:32:29 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/14 10:24:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int lettre)
{
	int	i;
	unsigned char ch;

	i = 0;
	ch = (unsigned char) lettre;
	if (ch == 0)
		return (&str[ft_strlen(str)]);
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
			return (NULL);
		i--;
	}
	return (&str[i]);
}

//  int main (void)
//  {
//      //char *texte = "tripouille";
//      int lettre = 'V';
// 	char * empty = (char*)calloc(1, 1);

//      printf("1:|%s|\n", strrchr(empty, lettre));
//      printf("2:|%s|", ft_strrchr(empty, lettre));    
//  }
