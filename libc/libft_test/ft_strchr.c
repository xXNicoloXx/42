/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:42:06 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/14 09:47:02 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int lettre)
{
	int	i;
	unsigned char ch;

	i = 0;
	ch = (unsigned char) lettre;
	//printf("%d | %c\n ", lettre, lettre);
	while (str[i] != ch)
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

//     printf("1:%s\n", strchr("tripoulle", 't' + 256));
//     printf("2:%s", ft_strchr("tripoulle", 't' + 256));    
	
// }
