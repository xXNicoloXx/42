/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:24:33 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/16 19:00:10 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return ;
    new->next = *begin_list;
    new->data = data;
    *begin_list = new;
}

// int main(void)
// {
//     t_list *nico = malloc(sizeof(t_list));
//     nico->data = "caca";
//     nico->next = 0;
//     printf("%p\n",nico);
//     printf("%p\n",nico->next);
//     ft_list_push_front(&nico, 0);
//     printf("%p\n",nico);
//     printf("%p\n",nico->next);
// }