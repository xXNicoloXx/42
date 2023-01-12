/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:44:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/28 12:44:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int *ft_range(int start, int end)
{
    int i;
    int j;
    int len;
    int    *tab;

    len = end - start + 1;
    i = 0;
    printf("len = %d\n", len);
    tab = malloc(sizeof(int) * len + 1);
    while (i < len)
    {
       tab[i] = start;
       printf("tab[%d] = %d\t start = %d\n", i, tab[i], start);
       start++;
       i++;
    }
    return (tab);
}

int main(void)
{
    int *b = ft_range(1, 3);
    printf("%d ",b[0]);
    printf("%d ",b[1]);
    printf("%d ",b[2]);
}
