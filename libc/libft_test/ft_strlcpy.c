/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:40:57 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/14 13:27:17 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	printf("size t = %lu\n", size);
	while (size && src[i] && dst[i])
	{
		dst[i] = src[i];
		printf("str[%lu]=%c\n",i, src[i]);
		i++;
		size--;
		
	}
	
	if (size == 0)
		dst[i -1] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char src[] = "coucou";
// 	char dest[10]; 
// 	memset(dest, 'A', 10);
// 	char ftsrc[] = "coucou";
//     char ftdest[10];
// 	memset(ftdest, 'A', 10);
//     int nbr = 2;
//     int i = 0;
//     printf("\n\nde = |%s| %ld\n",dest ,strlcpy(dest, src, nbr));
//     printf("ft = |%s| %ld\n",ftdest ,ft_strlcpy(ftdest, ftsrc, nbr));
// 	printf("nb\tstrlen = %ld strdup = %d\t| A? = %c \t|%d\n",strlen(src),strcmp(src, dest), dest[strlen(src) + 1], dest[strlen(src) + 1]);
// 	printf("ft\tstrlen = %ld strdup = %d\t| A? = %c \t|%d\n",strlen(ftsrc),strcmp(ftsrc, ftdest), ftdest[strlen(ftsrc) + 1], ftdest[strlen(ftsrc) + 1]);
// 	while (i < 20)
// 	{
// 		printf("%c|%c\t %d|%d\n",ftdest[i],dest[i], ftdest[i],dest[i]);
// 		i++;
// 	}

// 	if (ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A')
// 		printf("LTES DGO");
// }