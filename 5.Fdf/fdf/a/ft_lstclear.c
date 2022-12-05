/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:44:55 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/17 17:41:38 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*adresse;
	t_list	*adresseback;

	adresse = *lst;
	if (lst == NULL && *lst == NULL)
		return ;
	while (adresse->next != NULL)
	{
		if ((*del) != NULL)
			(*del)(adresse->content);
		adresseback = adresse;
		adresse = adresse->next;
		free(adresseback);
	}
	if ((*del) != NULL)
		(*del)(adresse->content);
	free(adresse);
	*lst = NULL;
}
