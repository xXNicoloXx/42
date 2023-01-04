/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:04:47 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 23:04:48 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_max(int *tab, int len)
{
    if (len == 0)
        return (0);
    int i;
    int temp;
    
    i = 0;
    temp = tab[0];
    while (i < len)
    {
        if (temp < tab[i])
            temp = tab[i];
        i++;
    }
    return(temp);
    
}

int main(void)
{
    int tab[] = {1,4,9,10,99,5,3,84,6,59,12,4};
    int len = 12;
    printf("%d",ft_max(tab, len));

}
