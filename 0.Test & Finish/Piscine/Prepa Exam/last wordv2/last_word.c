/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:19:07 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 22:19:07 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void last_word(char *str)
{
    int i;

    i = 0;
                    //printf("str[0] = %c", str[0]);
    while(str[i] != '\0')
    {
        i++;
    }
    i--;
                   // printf("1i = %d", i);
    while (str[i] == ' ' || str[i] == '\t')
    {
        i--;
    }
                   // printf("2i = %d", i);
    while(str[i] != ' ' && str[i] != '\t')
    {
        i--;
    }
    i++;
                   // printf("str[%d] = %c", i, str[i]);
    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++; 
    }
    
    
}

int main(int c, char **v)
{
    last_word("Bonjour les amis");
}

