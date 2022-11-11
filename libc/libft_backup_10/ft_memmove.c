/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:35:29 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 12:59:40 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned long	adresse1;
	unsigned long	adresse2;

	i = 0;
	adresse1 = (unsigned long) src;
	adresse2 = (unsigned long) dest;
	if (adresse1 < adresse2)
	{
		while (n)
		{
			*((unsigned char *)dest + n - 1) = *((unsigned char *)src + n - 1);
			n--;
		}
	}
	else
	{
		while (n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *) src + i);
			n--;
			i++;
		}
	}
}
