/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/12 17:02:21 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_monitoring(t_swap *s)
{
	int j;

	j = 0;
	while (++j < s->len - 1 - 50)
	{
		printf("%d\t", s->tab1[j]);
		printf("%d\t", s->filltab1[j]);
		printf("|\t" );
		printf("%d\t", s->tab2[j]);
		printf("%d\n", s->filltab2[j]);
	}
	printf("coups: %d\n", s->move);
}

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

void ft_sort_5_a(t_swap *s, int max)
{
	int len;

	len = 0;
	while (s->filltab1[len] != 0)
		len++;
	s->verifrb = 0;
	while (1)
	{
		int j = -1;
   		while (++j < s->len - 1 - 50)
		{
			// printf("\n---------------------------------------\n");
			printf("%d\t", s->tab1[j]);
			printf("%d\t", s->filltab1[j]);
			printf("|\t" );
			printf("%d\t", s->tab2[j]);
			printf("%d\n", s->filltab2[j]);
		}
		printf("max = %d\n", max);

		if (s->filltab1[1] == max - 4)
		{	
			ft_sa(s);
			ft_pb(s);
		}
		else if (s->filltab1[0] == max - 3)
			ft_pb(s);
		else if (s->filltab1[0] == max - 2 && s->filltab2[0] ==  max - 3 && s->filltab2[1] ==  max - 4)
			ft_pb(s);
		else if (s->filltab1[0] == max)
		{
			s->verifrb += 1;
			ft_ra(s, 0);
		}
		else if (s->filltab1[0] == max - 1 && s->filltab1[1] ==  max - 2)
		{
			s->verifrb += 1;
			ft_ra(s, 0);
		}
		else if (s->filltab1[1] == max - 3)
			ft_sa(s);
		else if (s->filltab2[0] == max - 4 && s->filltab2[1] == max - 3)
			ft_sb(s);
		else if (s->filltab2[0] == max - 2 && s->filltab2[1] ==  max - 3 && s->filltab2[2] ==  max - 4 && s->filltab1[0] == max-1 && s->filltab1[1] ==  max)
		{
			ft_pa(s);
			ft_pa(s);
			ft_pa(s);
			break ;
		}

		else if (s->filltab2[0] == max - 2 && s->filltab2[1] ==  max - 3 && s->filltab2[2] ==  max - 4)
		{
			while (s->verifrb)
			{
				ft_rra(s);
				s->verifrb--;
			}
			if (s->filltab1[0] == max)
				ft_sa(s);
		}
		
	}
}

void ft_sort_5_b(t_swap *s, int max)
{
	int len;

	len = 0;
	s->verifrb = 0;
	while (s->filltab2[len] != 0)
		len++;
	while (1)
	{
		int j = -1;
   		while (++j < s->len - 1 - 70)
		{
			// printf("\n---------------------------------------\n");
			printf("%d\t", s->tab1[j]);
			printf("%d\t", s->filltab1[j]);
			printf("|\t" );
			printf("%d\t", s->tab2[j]);
			printf("%d\n", s->filltab2[j]);
		}
		printf("max = %d\n", max);
		printf("\ncoucou = %d(%d)\n", max - 4, max);
		if (s->filltab2[0] == max || s->filltab2[0] == max - 1)
			ft_pa(s);
		else if(s->filltab1[0] == max && s->filltab1[1] == max - 1)
			ft_sa(s);
		else if (s->filltab2[1] == max)
			ft_sb(s);
		else if (s->filltab1[0] == max - 1 && s->filltab1[1] == max && s->filltab2[0] == max - 2)
			ft_pa(s);
		else if (s->filltab2[0] == max - 4 && s->filltab2[1] == max - 3)
			ft_sb(s);
		else if (s->filltab1[0] == max - 2 && s->filltab1[1] == max - 1 && s->filltab1[2] == max && s->filltab2[0] == max - 3)
			ft_pa(s);
		else if (s->filltab1[0] == max - 3 && s->filltab1[1] == max - 2 && s->filltab1[2] == max - 1 && s->filltab1[3] == max)
			ft_pa(s);
		else if (s->filltab1[0] == max - 4 && s->filltab1[1] == max - 3 && s->filltab1[2] == max - 2 && s->filltab1[3] == max - 1 && s->filltab1[4] == max)
			break ;
	}
}

void ft_cut_10_to_5(t_swap *s)
{
	int move;
	int push;
	int len;
	int i;

	len = s->len - 1 + 5;
	i = 0;
	printf("i = %d\n\n", i);
	while (i < 2)
	{
		len -= 5;
		printf("len = %d\n\n\n", len);
		push = 0;
		move = 0;
		while (push != 5)
		{
			printf("push = %d\n", push);
			int j = -1;
			while (++j < s->len - 1)
			{
				// printf("\n---------------------------------------\n");
				printf("%d\t", s->tab1[j]);
				printf("%d\t", s->filltab1[j]);
				printf("|\t" );
				printf("%d\t", s->tab2[j]);
				printf("%d\n", s->filltab2[j]);
			}
			if (len - 5  < s->filltab2[0] &&  s->filltab2[0] <= len)	
			{
				push++;
				ft_pa(s);
			}
			else
			{
				move++;
				ft_rb(s, 0);
			}
		}
		while (move)
		{
			ft_rrb(s);
			move--;
		}

		ft_sort_5_a(s, len);
		len -= 5;
		ft_sort_5_b(s, len);
		i++;
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

}

int main(int argc, char **argv)
{
    t_swap s;
    int i;

    i = -1;
    ft_push_swap(argc, argv, &s);

    i = -1;
	printf("s->len = %d\n", s.len);
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
