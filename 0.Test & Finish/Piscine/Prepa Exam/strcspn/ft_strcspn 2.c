/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:28:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 18:28:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(s[i] != '\0')
    {   
        j = 0;
        while(reject[j] != '\0')
        {
            if (s[i] == reject[j])
            {
                i = (size_t) i;
                return (i);
            }
        j++;
        }
    i++;
    }
    return(i);
}

int main(void)
{
    char    *titou = "";
    char    *list = "mo";

    printf("%ld\n", ft_strcspn(titou, list));
    printf("%ld", strcspn(titou, list));
    
}