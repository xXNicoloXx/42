/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:55 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 16:11:22 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int character)
{
	if (64 < character && character < 91)
	{
		return (character + 32);
	}
	return (character);
}

// int main(void)
// {
// 	int i = -2;
// 	while (i<130)
// 	{
//         printf("%c \t", tolower(i));
//     	printf("%c \t %c\n", ft_tolower(i),i);
// 		i++;
// 	}
// }
