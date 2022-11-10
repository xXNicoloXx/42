/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:56:36 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 18:24:51 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
/*int main (void)
{

    void *ptr[20] ;
    int value = 50;
    int n = 5;
	int test = 50;
    printf("%s\n\n", ft_memset(ptr, value, n));
	printf("%s", memset(ptr, value, test));
}*/