/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:01 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/09 15:06:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ss(t_swap *s)
{
    if (s->filltab1[0] == 0 && s->filltab1[1] == 0)
        return;
	else
	{
    s->tmp = s->tab1[0];
    s->tab1[0] = s->tab1[1];
    s->tab1[1] = s->tmp;
	s->tmp = s->filltab1[0];
    s->filltab1[0] = s->filltab1[1];
    s->filltab1[1] = s->tmp;
	if (s->filltab2[0] == 0 && s->filltab2[1] == 0)
        return;
	s->tmp = s->tab2[0];
    s->tab2[0] = s->tab2[1];
    s->tab2[1] = s->tmp;
	s->tmp = s->filltab2[0];
    s->filltab2[0] = s->filltab2[1];
    s->filltab2[1] = s->tmp; 
	}
	s->move += 1;
    write(1, "ss\n", 3);
	
}

void ft_sa(t_swap *s)
{
    if (s->filltab1[0] == 0 && s->filltab1[1] == 0)
        return ;
    s->tmp = s->tab1[0];
    s->tab1[0] = s->tab1[1];
    s->tab1[1] = s->tmp;
	s->tmp = s->filltab1[0];
    s->filltab1[0] = s->filltab1[1];
    s->filltab1[1] = s->tmp; 
	s->move += 1;
    write(1, "sa\n", 3);
}

void ft_sb(t_swap *s)
{
    if (s->filltab2[0] == 0 && s->filltab2[1] == 0)
        return ;
    s->tmp = s->tab2[0];
    s->tab2[0] = s->tab2[1];
    s->tab2[1] = s->tmp;
	s->tmp = s->filltab2[0];
    s->filltab2[0] = s->filltab2[1];
    s->filltab2[1] = s->tmp;
	s->move += 1;
    write(1, "sb\n", 3);
}

void ft_pa(t_swap *s)
{
	if (s->filltab2[0] == 0)
	return ;

}

void ft_pb(t_swap *s)
{
	return ;
}