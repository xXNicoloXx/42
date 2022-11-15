/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zzzzzzzzzzzzzzzzzft_memmove.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:35:29 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/08 11:38:19 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_COUNT 10


void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t  i;
    unsigned long adresse1;
    unsigned long adresse2;

    i = 0;
    adresse1 = (unsigned long) src;
    adresse2 = (unsigned long) dest;
    if (adresse1 < adresse2)
    {
        //printf("+\n");
        while(n)
        {
            *((unsigned char *)dest + n - 1) = *((unsigned char *)src + n - 1);
            n--;
        }
    }
    else
        //printf("-\n");
        while(n)
        {
            //printf("n = %d,\ti = %d", i, n);
            *((unsigned char *)dest + i) = *((unsigned char *) src + i);
            n--;
            i++;
        }
        

    printf("\n%li \n%li\n\n\n\n",adresse1, adresse2);
    printf("d= %s \ns= %s", dest, src);
}


int main (void)
{
    char ch[] = "123456789";
    void *src = (void *) ch;
    void *dest = (void *) ch;
    printf("efef");
    ft_memmove(ch+1, ch, 9);
}   