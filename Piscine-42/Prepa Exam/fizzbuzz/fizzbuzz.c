/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:43:52 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/28 16:43:53 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int i)
{
    if (i < 10)
    {
        i = i + '0';
        write(1, &i, 1);
    }
    else
    {
        ft_putnbr(i / 10);
        ft_putnbr(i % 10);
    }
}

int ft_5(int i)
{
    i = i % 5;
    if (i == 0)
        return (1);
    else
        return(0);    
}

int ft_3(int i)
{
    i = i % 3;
    if (i == 0)
        return (1);
    else
        return(0);    
}

void ft_fizzbuzz(void)
{
    int i;
    int j;


    i = 1;
    while(i <= 100)
    {
        if (ft_3(i) == 1 && ft_5(i) == 1)
            write(1, "fizzbuzz", 8);
        else if (ft_3(i) == 1)
            write(1, "fizz", 4);
        else if (ft_5(i) == 1)
            write(1, "buzz", 4);
        else
        {
            ft_putnbr(i);
        }
        write(1, "\n", 1);
        i++;
            

    } 
}

int main(void)
{
    ft_fizzbuzz();
}