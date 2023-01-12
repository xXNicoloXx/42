/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:02:25 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 15:02:38 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include <unistd.h>
 #include <stdio.h>

int lencom(char *comp)
{
    int i;

    i = 0;
    while (comp[i])
        i++;
    return (i);
    printf("i = %d\n", i);
    }


int    wd(char *comp, char *str)
{
    int i;
    int j;
    int len;

    len = lencom(comp);
    //printf("len = %d", len);
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == comp[j])
        {
            j++;
        }

        i++;
    }

    if (j == len)
        {
            j = 0;
            while(comp[j])
            {
                write(1, &comp[j], 1);
                j++;
            }
            return (0);
        }
    write(1 ,"\n", 1);
}

int main(int c,char **v)
{
    if (c == 3)
        wd(v[1], v[2]);
    else
        write(1 ,"\n" ,1);
}
