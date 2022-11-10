/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:53:31 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 19:19:10 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = -1;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n && ptr1[i] == ptr2[i])
	{
		i++;
		n--;
	}
	if ((ptr1[i] - ptr2[i]) < 0)
		return (-1);
	else if (((ptr1[i] - ptr2[i]) > 0))
		return (42);
	else
		return (0);
}

// int main(void)
// {
//     char test[] = "bqsub";
//     char cmpp[] = "bq8ouA";
//     int nb = 6;
//     printf("|%d|\n",ft_memcmp(test, cmpp, nb));
//     printf("|%d|",memcmp(test, cmpp, nb));
// }