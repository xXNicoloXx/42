/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:27:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 19:27:06 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    int i;
    int j;
    char    *tab;

    i = 0;
    j = 0;
    tab = malloc(sizeof(char) * ft_strlen(src) + 1);
    while(src[i] != '\0')
    {
        tab[i] = src[i];
        i++;
    }
    tab[i] = '\0';
    return (tab);

}

int main()
{
    char    *test = "Bonjour les amis sasascomment ca va ?"; 
    printf("%s",ft_strdup(test));
}