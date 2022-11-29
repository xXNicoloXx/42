/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:29:12 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 21:30:35 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_len(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}


void ft_inter(char *a, char *b)
{
    int j;
    int k;
    int lena;
    int lenb;
    char lettre;
    int verif;

    j = 0;
    k = 0;
    lettre = 0;
    verif = 0;
    lena = ft_len(a);
    lenb = ft_len(b);

    while (j <= lena)
    {
        //printf("%s\n", a);
        if (a[j] != '\0')
        {
            lettre = a[j];
            a[j] = '\0';
            j = 0;
            //printf("lettre = %c\n", lettre);
            while (j <= lena)
            {
                if (a[j] == lettre)
                    a[j] = '\0';
                j++;
            }
            k = 0;
            while (k <= lenb)
            {
                if (b[k] == lettre)
                {
                    b[k] = '\0';
                    verif = 1;
                }
                k++;
            }
            if (verif == 1)
            {
                verif = 0;
                write(1, &lettre, 1);
            }
            j = 0;
        }
        else
            j++;
        //printf("j = %d", j);
    }
    

}


int main(int c, char **v)
{
    if (c == 3)
        ft_inter(v[1], v[2]);
    return(0);
}