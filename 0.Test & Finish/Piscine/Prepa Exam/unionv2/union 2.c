/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:14:31 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 23:14:32 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_len(char *str)
{
    int i;
    while (str[i] != '\0')
        i++;
    return (i);
}

int ft_union(char *a, char *b)
{
    int i;
    int j;   
    int lena;
    int lenb;
    char    lettre;

    i = 0;
    j = 0;
    lena = ft_len(a);
    lenb = ft_len(b);
    //printf("lena = %d lenb = %d\n", lena, lenb);
    while (i < lena)
    {
        if (a[i] != '\0')
        {
            lettre = a[i];
            a[i] = '\0';
            write(1, &lettre, 1);
            while (i < lena)
            {
                if (a[i] == lettre)
                    a[i] = '\0';
                i++;
            }
            j = 0;
            while (j < lenb)
            {
                if (b[j] == lettre)
                    b[j] = '\0';
                j++;
            }
            
        i = 0;
        }
        else
            i++;
    }
    i = 0;
    j = 0;
    while (j < lenb)
    {
        if (b[j] != '\0')
        {
            lettre = b[j];
            b[j] = '\0';
            write(1, &lettre, 1);
            while (j < lenb)
            {
                if (b[j] == lettre)
                    b[j] = '\0';
                j++;
            }
            j = 0;
        }
        else
            j++;
    }
}


int main(int c, char **v)
{
    if (c == 3)
        ft_union(v[1], v[2]);
    
}