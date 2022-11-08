/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:37 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/07 15:27:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> 
#include <stdio.h> 
#include <stddef.h>

void	t_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}
