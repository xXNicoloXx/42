/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/10 12:39:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_eff(t_swap *s, int value)
{
	int len;
	int pos;

	len = 0;
	while (s->filltab1[len] != value + 1)
		len++;
	pos = len;
	while (s->filltab1[len] != 0)
		len++;
	// printf("pos = %d/%d(/2=%d)(value = %d)\n", pos, len, len/2, value+1);
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
    int i;
	int j;
    
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
   		// while (++j < argc)
		// {
		// 	printf("\n---------------------------------------\n");
		// 	printf("%d\t", s->tab1[j]);
		// 	printf("%d\t", s->filltab1[j]);
		// 	printf("|\t" );
		// 	printf("%d\t", s->tab2[j]);
		// 	printf("%d", s->filltab2[j]);
		// }
		// printf("\n---------------------------------------\n\n\n\n\n");
		// if (s->filltab1[0] > s->filltab1[1])
		// 	ft_sa(s);
		if (i == s->filltab1[0] - 1)
		{
			ft_pb(s);
			i++;
		}
		else
		{
			if (ft_verif_eff(s, i) == 0)
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
