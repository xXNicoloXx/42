/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/12 14:18:55 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_eff(t_swap *s, int imin, int imax)
{
	int i;

	i = 0; 
	while (1)
	{
		if (imin <= s->filltab1[i] && s->filltab1[i] < s->len)
		{
			return (0);
		}
		if ( s->len <= s->filltab1[s->len -  i - 1] && s->filltab1[s->len -  i] < imax)
		{
			return (1);
		}
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

void ft_sort_5(t_swap *s)
{
	int i;
	int index;
	int sizeb;
	int pos1;
	int pos2;

	printf("SORT 5\n");
	i = 0;
	sizeb = s->len - 1;
	index = s->len - 1;	
	pos1 = -1;
	pos2 = -1;
	while (i < 5)
		i = i;
}

ft_cut_10_to_5(t_swap *s)
{
	int move;
	int push;
	int i;

	i = s->len;
	push = 0;
	move = 0;

	while (push != 5)
	{
		if (s->len < s->filltab1[0]
	}
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
	imin = s->len / 2 - 10;
	imax = s->len / 2 + 10;
	while (s->filltab1[0] != 0)
	{
		// printf("val act = [%d]\n", s->filltab1[0]);
		j = -1;
   		// while (++j < argc - 1)
		// {
		// 	// printf("\n---------------------------------------\n");
		// 	printf("%d\t", s->tab1[j]);
		// 	printf("%d\t", s->filltab1[j]);
		// 	printf("|\t" );
		// 	printf("%d\t", s->tab2[j]);
		// 	printf("%d\n", s->filltab2[j]);
		// }
		// printf("imin = %d\tvaleurs = %d\t imax = %d\nn",imin ,s->filltab1[0], imax);
		if(imin < s->filltab1[0] && s->filltab1[0] <= imax)
		{
			// printf("PUUUUSSSSHHHHHHHHHH\n\n\n\n\n");
			if (s->verifrb == 1)
			{
				ft_rb(s,0);
				s->verifrb = 0;
			}
			ft_pb(s);
			// printf("OHOH |%d|\t|%d|\t|%d|\n", imin, s->filltab1[0], s->len / 2);
			if (imin <= s->filltab2[0] && s->filltab2[0] <= s->len / 2)
			{
				s->verifrb = 1;
				indeximin++;
			}
			else
				indeximax++;
				
		}
		else
		{
			if (ft_verif_eff(s, imin, imax) == 0)
			{
				if (s->verifrb == 1)	
				{
					ft_rr(s);
					s->verifrb = 0;
				}
				else
					ft_ra(s, 0);
			}
			else
				ft_rra(s);
		}
		// fprintf(stdout, "imin = %d\timax = %d\n", imin, imax);
		if (indeximax == 10)
		{
			imax += 10;
			indeximax = 0;
		}
		if (indeximin == 10)
		{
			imin -= 10;
			indeximin = 0;
		}	
	}

	if (s->verifrb == 1)	
	{
		ft_rb(s, 0);
		s->verifrb = 0;
	}
	ft_cut_10_to_5(s);
	// ft_sort_5(s);

}

int main(int argc, char **argv)
{
    t_swap s;
    int i;

    i = -1;
    ft_push_swap(argc, argv, &s);

    // i = -1;
	// printf("s->len = %d\n", s.len);
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
