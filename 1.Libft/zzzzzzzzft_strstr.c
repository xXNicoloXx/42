/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:26:19 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 16:27:23 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *src, char *cmp )
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		printf("\t\t%c\n", src[i]);
		k = i;
		while (src[k] == cmp[j] && cmp[j] != '\0')
		{
			k++;
			j++;
		}
		if (cmp[j] == '\0')
			return (&src[i]);
		i++;
		j = 0;
	}
	return (0);
}

// int main(void)
// {
//     char *srcstr = "1234";
//     char *cmpstr = "2";

//     printf("|%s|\n", strstr(srcstr, cmpstr));
//     printf("|%s|\n", ft_strstr(srcstr, cmpstr));
// }