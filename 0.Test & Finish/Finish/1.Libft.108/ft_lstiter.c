/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:14:53 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/17 17:42:28 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*adresse;

	adresse = lst;
	while (adresse->next != NULL)
	{
		(*f)(adresse->content);
		adresse = adresse->next;
	}
	(*f)(adresse->content);
}
