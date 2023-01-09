/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/09 19:54:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    int i;
	int j;
    
    printf("argc = %d\n\n\n", argc-1);
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
	i = 0;
	while (i < s->len - 1)
	{
		j = -1;
		printf("\n\n");
   		while (++j < argc - 1)
		{
			printf("\n---------------------------------------\n");
			printf("%d\t", s->tab1[j]);
			printf("%d\t", s->filltab1[j]);
			printf("|\t" );
			printf("%d\t", s->tab2[j]);
			printf("%d", s->filltab2[j]);
		}
		printf("\n---------------------------------------\n\n\n");
		if (i == s->filltab1[0] - 1)
		{
			ft_pb(s);
			i++;
		}
		else
			ft_ra(s);

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
    printf("START \n");
    ft_push_swap(argc, argv, &s);
    printf("\n\nEND \n");

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
