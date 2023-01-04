/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:44:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/17 17:44:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*adresse;

	i = 1;
	adresse = lst;
	if (lst == 0)
		return (0);
	while (adresse->next != 0)
	{
		adresse = adresse->next;
		i++;
	}
	return (i);
}
