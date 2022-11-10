/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:02:07 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 17:34:08 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int str)
{	
	if (!((64 < str && str < 91) || (96 < str && str < 123)))
		return (0);
	return (1);
}

/*int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d\n", isalpha(i));
		printf("%d\n\n\n", ft_isalpha(i));
		i++;
	}
}*/
