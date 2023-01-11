/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/11 15:37:25 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_eff(t_swap *s, int imin, int imax)
{
	int i;

	i = 0; 
	while (1)
	{
		if (s->filltab1[i] == imin)
			return (0);
		if (s->filltab1[s->len -  i] == imax)
			return (1);
		i++;
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
	int imin;
	int indeximin;
	int imax;
	int indeximax;
    
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
	imin = s->len / 2 - 5;
	imax = s->len / 2 + 5;
	while (s->filltab1[0] != 0)
	{
		printf("val act = [%d]\n", s->filltab1[0]);
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
		if(imin <= s->filltab1[0] && s->filltab1[0] <= imax)
		{
			printf("PUUUUSSSSHHHHHHHHHH\n\n\n\n\n");
			ft_pb(s);
			printf("OHOH |%d|\t|%d|\t|%d|\n", imin, s->filltab1[0], s->len / 2);
			if (imin <= s->filltab2[0] && s->filltab2[0] <= s->len / 2)
			{
				fprintf(stderr, "s->filltab2[0] %d", s->filltab2[0]);
				ft_rb(s);
				indeximin++;
			}
			else
				indeximax++;
				
		}
		if (ft_verif_eff(s, imin, imax) == 0)
			ft_ra(s);
		else
			ft_rra(s);
		if (indeximax > 5)
		{
			imax += 5;
			indeximax = 0;
		}
		if (indeximin > 5)
		{
			imin -= 5;
			indeximin = 0;
		}	
	}

}


int main(int argc, char **argv)
{
    t_swap s;
    int i;

    i = -1;
    ft_push_swap(argc, argv, &s);

    i = -1;
	printf("\n\n");
    while (++i < argc - 1)
	{
        printf("---------------------------------------\n");
        printf("%d\t", s.tab1[i]);
        printf("%d\t", s.filltab1[i]);
        printf("|\t" );
        printf("%d\t", s.tab2[i]);
        printf("%d\n", s.filltab2[i]);
	}
    printf("---------------------------------------\n");
	printf("nombre de coups = %d", s.move);
}
