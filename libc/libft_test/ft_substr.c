/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:54:39 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/11 11:41:30 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(len + 1));
	if (str == NULL)
		return (NULL);
	while (len)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

// int main (void)
// {
// 	char *test = "123456789";
// 	int start = 2;
// 	int len = 5;
// 	printf("ft = %s\n",ft_substr(test,start,len));
// }
