/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:30:21 by ngriveau          #+#    #+#             */
/*   Updated: 2022/07/27 16:30:23 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_doop(char *p, char *op, char *d)
{
    int pr;
    int de;
    int resu;
    int i = 0;

    pr = atoi(p);
    de = atoi(d);
    if (op[i] == '+')
        printf("%d", resu = pr + de);
    else if (op[i] == '-')
        printf("%d", resu = pr - de);
    else if (op[i] == '*')
        printf("%d", resu = pr * de);
    else if (op[i] == '/')
        printf("%d", resu = pr / de);
    else if (op[i] == '%')
        printf("%d", resu = pr % de);

}



int main (int c, char **v)
{
    if (c == 4)
        ft_doop(v[1], v[2], v[3]);
}
