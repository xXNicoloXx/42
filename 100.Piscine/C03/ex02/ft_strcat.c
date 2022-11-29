/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:28:27 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/13 11:41:53 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	strlen1(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\0'))
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	lendest;
	int	i;

	lendest = strlen1(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (dest);
}
