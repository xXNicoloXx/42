/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:40:57 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 19:32:41 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (size && dst[i])
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i - 1] = '\0';
	i = 0;
	while (!(src[i] == '\0'))
	{
		i++;
	}
	return (i);
}

/*int main(void)
{
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char dest[] = "0123465789000000000000000000000";
	char ftsrc[] = "abcdefghijklmnopqrstuvwxyz";
    char ftdest[] = "0123465789000000000000000000000";
    int nbr = 257;
    
    printf("  dest = %s %ld\n",dest ,strlcpy(dest, src, nbr));
    printf("ftdest = %s %ld",ftdest ,strlcpy(ftdest, ftsrc, nbr));
}*/