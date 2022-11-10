/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:32:56 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 18:22:24 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int str)
{	
	if (!(31 < str && str < 127))
		return (0);
	return (1);
}

/*int main(void)
{
	int i = -2;
	while (i<129)
	{
		printf("%d \t", isprint(i));
		printf("%d \t %c\n", ft_isprint(i),i);
		i++;
	}
}*/
