/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:55 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 17:32:26 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int str)
{	
	if (!((47 < str && str < 58) || (64 < str && str < 91)
			|| (96 < str && str < 123)))
		return (0);
	return (1);
}

/*int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d \t", isalnum(i));
		printf("%d \t %c\n", ft_isalnum(i),i);
		i++;
	}
}*/
