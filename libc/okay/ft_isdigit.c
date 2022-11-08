/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:17 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 13:23:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int str)
{	
	if (!((47 < str && str < 58)))
		return (0);
	return (1);
}

/*int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d \t", isdigit(i));
		printf("%d \t %c\n\n", ft_isdigit(i),i);
		i++;
	}
}*/
