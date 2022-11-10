/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:41:46 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 18:23:30 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		n--;
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// printf("%p\n",ft_memchr("Bonjour les amis", 'r', 6));
// printf("%p",memchr("Bonjour les amis", 'r', 6));
// }