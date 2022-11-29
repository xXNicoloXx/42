/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:11:03 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/28 10:11:04 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int ft_atoi(char *str)
{
    int i;
    int signe;
    int nombre;

    i = 0;
    signe = 1;
    nombre = 0;
    if (str[i] == '-')
    {
        signe = -signe;
        i++;
    }
    while (str[i])
    {

        nombre = nombre * 10 + str[i] - '0';
        i++;
    }
    return (nombre * signe);
}

void ft_putnbr(int oui)
{
    if (oui < 10)
    {
        oui = oui + '0';
        write(1, &oui ,1);
    }
    else
    {
        ft_putnbr(oui / 10);
        ft_putnbr(oui % 10);
    }
}

int ft_prime(char *str)
{
    int nbr;
    int i;
    int tempon;
    int n;
    int final;
    int verif;
    int masque;

    i = 2;
    final = 0;
    nbr = ft_atoi(str);
    while(i <= nbr)
    {
        n = 2;
        verif = 1;
        while (n < i)
        {
            //printf("n = %d  i = %d\n", n, i);
            if (i % n == 0)
            {
                //printf("verif ok\n");
                verif = 0;
            }
    

        n++;
        }
        //printf("\n");
        if (verif == 1)
        {
            final = final + i;
        }
        i++;

    }
    ft_putnbr(final);
}

int main(int c, char **v)
{
    if (c == 2)
        ft_prime(v[1]);
}