/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/10 18:09:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_eff(t_swap *s, int value, int valuemax)
{
	int len;
	int pos;
	int posmax;

	len = 0;
	while (s->filltab1[len] != value && len < s->len)
		len++;
	if (len < s->len)
		pos = len;
	else 
		pos = s->len;
	len = 0;
	while (s->	filltab1[len] != valuemax && len < s->len)
		len++;
	if (len < s->len)
		posmax = len;
	else 
		posmax = s->len;
	posmax = len;
	while (s->filltab1[len] != 0)
		len++;
	fprintf(stderr, "min = %d(%d)/%d(value = %d)\n", pos, len-pos + 1, len, value);
	fprintf(stderr, "max = %d(%d)/%d(value = %d)\n", posmax,  len-posmax + 1, len, valuemax);
	if (len/2 < pos)
	{
		return (1);
	}
	else
	{
		return (0);
	}
		
}

void ft_init_fill_tab(t_swap *s)
{
	int i;
	int value;
	int j;
	int k;
	
	i = -1;
    while (++i < s->len - 1)
	{
		j = 0;
		k = 1;
		while (j < s->len - 1)
		{
			if (s->tab1[j] < s->tab1[i])
				k++;
			j++;
		}
		s->filltab1[i] = k;
	}
    i = -1;
    while (++i < s->len - 1)
		s->filltab2[i] = 0;
}

int ft_push_swap(int argc, char **argv, t_swap *s)
{
	int j;
	int i;
    int ibot;
	int itop;
    
    s->len = argc;
	s->move = 0;
    s->tab1 = malloc(sizeof(int) * s->len - 1);
    s->tab2 = malloc(sizeof(int) * s->len - 1);
    s->filltab1 = malloc(sizeof(int) * s->len - 1);
    s->filltab2 = malloc(sizeof(int) * s->len - 1);
    i = -1;
    while (++i < s->len - 1)
		s->tab1[i] = ft_atoi(argv[i + 1]);
	ft_init_fill_tab(s);
	ibot = s->len/2;
	itop = s->len/2 + 1;
	printf("i = %d\timax = %d\n", ibot, itop);
	i = 0;

	while (i < s->len - 1)
	{
		printf("val act = [%d][%d][%d]\n", ibot, itop, s->filltab1[0]);
		j = -1;
   		while (++j < argc - 1)
		{
			printf("\n---------------------------------------\n");
			printf("%d\t", s->tab1[j]);
			printf("%d\t", s->filltab1[j]);
			printf("|\t" );
			printf("%d\t", s->tab2[j]);
			printf("%d", s->filltab2[j]);
		}
		printf("\n---------------------------------------\n\n\n\n\n");
		if (itop == s->filltab1[0])
		{
			printf("ici %d\n", s->filltab1[0] - 1);
			ft_pb(s);
			i++;
			itop++;
		}
		else if (ibot == s->filltab1[0])
		{
			printf("la %d\n", s->filltab1[0] - 1);
			ft_pb(s);
			ft_rb(s);
			i++;
			ibot--;
		}
		else
		{
			if (ft_verif_eff(s, ibot, itop) == 0)
				ft_ra(s);
			else
				ft_rra(s);
		}
	}
	i = -1;
	while (++i < s->len - 1)
		ft_pa(s);
}


int main(int argc, char **argv)
{
    t_swap s;
    int i;

    i = -1;
    ft_push_swap(argc, argv, &s);

    i = -1;
	// printf("\n\n");
    // while (++i < argc - 1)
	// {
    //     printf("---------------------------------------\n");
    //     printf("%d\t", s.tab1[i]);
    //     printf("%d\t", s.filltab1[i]);
    //     printf("|\t" );
    //     printf("%d\t", s.tab2[i]);
    //     printf("%d\n", s.filltab2[i]);
	// }
    // printf("---------------------------------------\n");
	// printf("nombre de coups = %d", s.move);
}
