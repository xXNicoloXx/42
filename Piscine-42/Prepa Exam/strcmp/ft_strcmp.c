/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:13:41 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 17:13:42 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] == s2[i])
            i++;
        else
            return (s1[i] - s2[i]);
    }
    return (0);
}

int main(void)
{
    char    *titou = "salok";
    char    *titouconard = "salok";


    printf("%d",ft_strcmp(titou, titouconard));
}