/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:31:01 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/09 19:12:25 by ngriveau         ###   ########.fr       */
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
    write(1, "SS\n", 3);
	
}

void ft_sa(t_swap *s)
{
    if (s->filltab1[0] == 0 || s->filltab1[1] == 0)
        return ;
    s->tmp = s->tab1[0];
    s->tab1[0] = s->tab1[1];
    s->tab1[1] = s->tmp;
	s->tmp = s->filltab1[0];
    s->filltab1[0] = s->filltab1[1];
    s->filltab1[1] = s->tmp; 
	s->move += 1;
    write(1, "SA\n", 3);
}

void ft_sb(t_swap *s)
{
    if (s->filltab2[0] == 0 || s->filltab2[1] == 0)
        return ;
    s->tmp = s->tab2[0];
    s->tab2[0] = s->tab2[1];
    s->tab2[1] = s->tmp;
	s->tmp = s->filltab2[0];
    s->filltab2[0] = s->filltab2[1];
    s->filltab2[1] = s->tmp;
	s->move += 1;
    write(1, "SB\n", 3);
}

void ft_pa(t_swap *s)
{
	int i;

	i = s->len;
	if (s->filltab2[0] == 0)
		return ;
	while (s->filltab1[i] == 0 && 0 <= i)
		i--;
	i++;
	while (i > 0)
	{
		s->tab1[i] = s->tab1[i - 1];
		s->filltab1[i] = s->filltab1[i - 1];
		i--;
	}
	s->tab1[i] = s->tab2[i];
	s->filltab1[i] = s->filltab2[i];
	while (i < s->len)
	{
		s->tab2[i] = s->tab2[i + 1];
		s->filltab2[i] = s->filltab2[i + 1];
		i++;
	}
	s->tab2[i] = 0;
	s->filltab2[i] = 0;
	s->move += 1;
    write(1, "PA\n", 3);

}

void ft_pb(t_swap *s)
{
	int i;

	i = s->len;
	if (s->filltab1[0] == 0)
		return ;
	while (s->filltab2[i] == 0 && 0 <= i)
		i--;
	i++;
	while (i > 0)
	{
		s->tab2[i] = s->tab2[i - 1];
		s->filltab2[i] = s->filltab2[i - 1];
		i--;
	}
	s->tab2[i] = s->tab1[i];
	s->filltab2[i] = s->filltab1[i];
	while (i < s->len)
	{
		s->tab1[i] = s->tab1[i + 1];
		s->filltab1[i] = s->filltab1[i + 1];
		i++;
	}
	s->tab1[i] = 0;
	s->filltab1[i] = 0;
	s->move += 1;
    write(1, "PB\n", 3);

}

void ft_ra(t_swap *s)
{
	int i;
	int lentab;
	int vtab;
	int itab;

	i = 0;
	lentab = 0;
	while (s->tab1[lentab] != 0)
		lentab++;
	lentab--;
	vtab = s->tab1[i];
	itab = s->filltab1[i];
	while (i < lentab)
	{
		s->tab1[i] = s->tab1[i + 1];
		s->filltab1[i] = s->filltab1[i + 1];
		i++;
	}
	s->tab1[i] = vtab;
	s->filltab1[i] = itab;
	s->move += 1;
    write(1, "RA\n", 3);
}

void ft_rb(t_swap *s)
{
	int i;
	int lentab;
	int vtab;
	int itab;

	i = 0;
	lentab = 0;
	while (s->tab2[lentab] != 0)
		lentab++;
	lentab--;
	vtab = s->tab2[i];
	itab = s->filltab2[i];
	while (i < lentab)
	{
		s->tab2[i] = s->tab2[i + 1];
		s->filltab2[i] = s->filltab2[i + 1];
		i++;
	}
	s->tab2[i] = vtab;
	s->filltab2[i] = itab;
	s->move += 1;
    write(1, "RA\n", 3);
}

void ft_rra(t_swap *s)
{
	int i;
	int lentab;
	int vtab;
	int itab;

	i = 0;
	lentab = 0;
	while (s->tab1[lentab] != 0)
		lentab++;
	lentab--;
	vtab = s->tab1[i];
	itab = s->filltab1[i];
	while (i < lentab)
	{
		s->tab1[i] = s->tab1[i + 1];
		s->filltab1[i] = s->filltab1[i + 1];
		i++;
	}
	s->tab1[i] = vtab;
	s->filltab1[i] = itab;
	s->move += 1;
    write(1, "RA\n", 3);
}

void ft_rrb(t_swap *s)
{
	int i;
	int vtab;
	int itab;

	i = 0;
	vtab = s->tab2[i];
	itab = s->filltab2[i];
	while (i < s->len - 2)
	{
		s->tab2[i] = s->tab2[i + 1];
		s->filltab2[i] = s->filltab2[i + 1];
		i++;
	}
	s->tab2[i] = vtab;
	s->filltab2[i] = itab;
	s->move += 1;
    write(1, "RB\n", 3);
}