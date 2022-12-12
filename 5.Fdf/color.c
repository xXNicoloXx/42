/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:56:24 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/12 16:45:20 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_color(int nbr, t_map *m)
{
    int tmp;

    tmp = nbr/1048576;
    nbr = nbr - 1048576 * tmp;
    m->img.r = tmp * 16;
    tmp = nbr/65536;
    nbr = nbr - 65536 * tmp;
    m->img.r += tmp;
    tmp = nbr/4096;
    nbr = nbr - 4096 * tmp;
    m->img.g = tmp * 16;
    tmp = nbr/256;
    nbr = nbr - 256 * tmp;
    m->img.g += tmp;
    tmp = nbr/16;
    nbr = nbr - 16 * tmp;
    m->img.b = tmp * 16;
    m->img.b += nbr;
}

void ft_draw(t_map *m, float x, float y, int color)
{
    unsigned long pixel;
	x = roundf(x);
	y = roundf(y);
    ft_color(color, m);
    pixel = (y * m->img.size) + (x * 4);
	if ((m->img.size) * m->winy < pixel - 5 || x <= 0 || y <= 0 || y > m->y * m->winy || x > m->winx)
		return ;
	
    if (m->img.e == 1)        // Most significant (Alpha) byte first
    {
        m->img.data[pixel + 0] = 0;
        m->img.data[pixel + 1] = m->img.r;
        m->img.data[pixel + 2] = m->img.g;
        m->img.data[pixel + 3] = m->img.b;
    }
    else if (m->img.e == 0)   // Least significant (Blue) byte first
    {
        m->img.data[pixel + 0] = m->img.b;
        m->img.data[pixel + 1] = m->img.g;
        m->img.data[pixel + 2] = m->img.r;
        m->img.data[pixel + 3] = 0;
    }
}

// int main(void)
// {
//     t_map m;
//     ft_color(0xffffff, &m);
//     printf("r = %d\n",m.img.r);
//     printf("g = %d\n",m.img.g);
//     printf("b = %d\n",m.img.b);
// }
