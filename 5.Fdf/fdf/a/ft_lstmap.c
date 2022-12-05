/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:42 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/17 17:43:29 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*adretour;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	adretour = new;
	while (lst->next != NULL && lst)
	{
		if (!new)
			return (NULL);
		new->next = ft_lstnew((*f)(lst->next->content));
		new = new->next;
		lst = lst->next;
	}
	return (adretour);
}
