/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:30:41 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 17:34:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int str)
{	
	if (!(-1 < str && str < 128))
		return (0);
	return (1);
}

/*int main(void)
{
	int i = -4;
	while (i<130)
	{
		printf("%d \t", isascii(i));
		printf("%d \t %c\n", ft_isascii(i),i);
		i++;
	}
}*/
