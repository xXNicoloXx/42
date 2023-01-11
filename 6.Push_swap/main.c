/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:34 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/11 14:17:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_eff(t_swap *s, int value)
{
	int len;
	int i;
	int pos0;
	int pos1;
	int pos2;
	int pos3;
	int pos4;
	int pos5;
	int pos6;
	int pos7;
	int pos8;
	int pos9;

	len = 0;
	// value ++;
	while (s->filltab1[len] != value + 0  && len < s->len)
		len++;
	if (len < s->len)
		pos0 = len;
	else 
		pos0 = s->len;
	len = 0;
	while (s->filltab1[len] != value + 1  && len < s->len)
		len++;
	if (len < s->len)
		pos1 = len;
	else 
		pos1 = s->len;
	len = 0;
	while (s->filltab1[len] != value + 2  && len < s->len)
		len++;
	if (len < s->len)
		pos2 = len;
	else 
		pos2 = s->len;
	len = 0;
	while (s->filltab1[len] != value + 3  && len < s->len)
		len++;
	if (len < s->len)
		pos3 = len;
	else 
		pos3 = s->len;
	len = 0;
	while (s->filltab1[len] != value + 4  && len < s->len)
		len++;
	if (len < s->len)
		pos4 = len;
	else 
		pos4 = s->len;
	len = 0;
	while (s->filltab1[len] != 0)
		len++;
	fprintf(stderr, "0 \t= %d(%d)\t len = %d(value = %d)\n", pos0, (len - pos0) + 1, len, value + 0);
	fprintf(stderr, "1 \t= %d(%d)\t len = %d(value = %d)\n", pos1, (len - pos1) + 1, len, value + 1);
	fprintf(stderr, "2 \t= %d(%d)\t len = %d(value = %d)\n", pos2, (len - pos2) + 1, len, value + 2);
	fprintf(stderr, "3 \t= %d(%d)\t len = %d(value = %d)\n", pos3, (len - pos3) + 1, len, value + 3);
	fprintf(stderr, "4 \t= %d(%d)\t len = %d(value = %d)\n\n\n", pos4, (len - pos4) + 1, len, value + 4);

	i = 0;
	while (i < s->len)
	{
		if (pos0 == i || pos1 == i ||pos2 == i ||pos3 == i ||pos4 == i)
			return (0);
		else if ((len - pos0) + 1 == i || (len - pos1) + 1 == i ||(len - pos2) + 1 == i ||(len - pos3) + 1 == i ||(len - pos4) + 1 == i)
			return (1);
		else
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
	int index;
    
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
	i = 1;
	index = 0;
	while (i < s->len - 1 && s->filltab1[0] != 0)
	{
		// printf("val act = [%d]\tindex = %d\t i = %d\n", s->filltab1[0], index, i);
		// j = -1;
   		// while (++j < argc - 1)
		// {
		// 	printf("\n---------------------------------------\n");
		// 	printf("%d\t", s->tab1[j]);
		// 	printf("%d\t", s->filltab1[j]);
		// 	printf("|\t" );
		// 	printf("%d\t", s->tab2[j]);
		// 	printf("%d", s->filltab2[j]);
		// }
		// printf("\n---------------------------------------\n\n\n\n\n");
		if(i <= s->filltab1[0] && s->filltab1[0] <= i + 4)
		{
			printf("PUUUUSSSSHHHHHHHHHH\n\n\n\n\n");
			index++;
			ft_pb(s);
		}
		if (ft_verif_eff(s, i) == 0)
			ft_ra(s);
		else
			ft_rra(s);
		if (index > 4)
		{
		index = 0;
		i +=5;
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
