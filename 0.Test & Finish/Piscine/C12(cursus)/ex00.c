/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:58 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/16 18:23:12 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
    t_list *new;
    
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

int main(void)
{
    return (0);
}
