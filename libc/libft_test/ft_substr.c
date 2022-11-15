/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:54:39 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/15 12:07:25 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	if (len < start || ((size_t) ft_strlen(s)) <= start)
		return (ft_strdup(""));
	if (((size_t) ft_strlen(s)) <= len)
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else if (((size_t) ft_strlen(s)) > len)
		str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len > 0 && s[start] != '\0')
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
// 	int start = 8;
// 	int len = 10;
// 	printf("ft = %s\n",ft_substr(test,start,len));
// }
