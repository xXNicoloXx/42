/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:13:31 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/16 19:33:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i ;
    

    while (begin_list->next != NULL)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

int main(void)
{
    
}