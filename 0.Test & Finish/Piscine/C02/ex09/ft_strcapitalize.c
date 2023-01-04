/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:42:22 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/25 17:45:08 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	if (*str == '\0')
		return (str);
	else
	{
		while (*(str + i) != '\0')
		{
			if (*(str + i) >= 65 && *(str + i) <= 90)
				*(str + i) = *(str + i) + 32;
			i = i + 1;
		}
		return (str);
	}
}

int	check(char c)
{
	if (c < 'a' || c > 'z')
	{
		if (c < 'A' || c > 'Z')
		{
			if (c < '0' || c > '9')
				return (1);
		}
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	str = ft_strlowcase(str);
	while (*(str + i) != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		else
		{	
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
			{
				if (check(*(str + i - 1)) == 1)
					*(str + i) = *(str + i) - 32;
			}	
		}
		i = i + 1;
	}
	return (str);
}
