/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:09:07 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 19:10:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(char *src, char *cmp, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		k = i;
		while (src[k] == cmp[j] && cmp[j] != '\0')
		{
			k++;
			j++;
		}
		if (k > n)
			return (0);
		if (cmp[j] == '\0')
			return (&src[i]);
		i++;
		j = 0;
	}
	return (0);
}

// int main(void)
// {
//	 int i = 0;
//     while (i < 20)
//     {
//     char *srcstr = "Bonjour les amis comment ca va ?";
//     char *cmpstr = "s";
//     printf("%s\n", strnstr(srcstr, cmpstr, i));
//     printf("%s\n\n\n", ft_strnstr(srcstr, cmpstr, i));
//     i++;
//     }
// }