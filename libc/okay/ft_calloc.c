/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:33:14 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 17:30:32 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	count;
	char	*str;

	count = nitems * size;
	str = malloc(nitems * size);
	if (str == NULL)
		return (NULL);
	else
	{
		while (count)
		{
			str[count - 1] = '\0';
			count--;
		}
	}
	return (str);
}

// int main(void)
// {
//     char *test;
//     char *ft;
//     size_t i = 0;
//     size_t items = 10;
//     size_t size = 1;
//     size_t count = items * size; 
//     test = calloc(items,size);
//     ft = ft_calloc(items,size);
//     while (count)
//     {
//         printf("|%ld|\t", items);
//         printf("|%c|\t", test[i]);
//         printf("|%c|\n", ft[i]);
//         items--;
//         i++;
//         count--;
//     }
//     free(test);
//     free(ft);
// }