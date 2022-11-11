/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:41:37 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 18:32:28 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = malloc(sizeof(char) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[i] == '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
