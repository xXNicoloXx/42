/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:43:35 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/22 12:04:29 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


void	ft_rot(char *str)
{
	int	j;
	int	tz;

	j = 0;	
	while (str[j] != '\0')
	{
		if (('a' <= str[j] && str[j] <= 'z') || ('A' <= str[j] && str[j] <= 'Z')) 
		{
			tz = 1;
			while (tz <= 13)
			{
				if (str[j] == 'z'|| str[j] == 'Z')
					str[j] = str[j] - 26;
				str[j] = str[j] + 1;
				//printf("j = %c\n", str[j]);
				tz++;
			}
		}
		write(1, &str[j], 1);
		//write(1, "\n", 1);
	j++;
	}
}


int	main(int c, char **v)
{
	if (c == 2)
		ft_rot(v[1]);
}

