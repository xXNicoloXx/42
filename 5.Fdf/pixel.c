/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:30:44 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/08 10:35:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void ft_pos_pixel(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	m->p = ft_calloc(sizeof(int**), m->y);
	while (y < m->y)
	{
		m->p[y] = ft_calloc(sizeof(int*), m->x);
		y++;
	}
	y = 0;
	while (y < m->y)
	{
		m->p[y][x] = ft_calloc(sizeof(int), 3);
		while (x < m->x)
		{
			m->p[y][x] = 1;						//y
			m->p[y][x] = x;						//x
			m->p[y][x] = m->map[y][x];			//z
			x++;
		}
		x = 0;
		y++;
	}
}


// void main(void)
// {
    
// }

m.p[x][x][1] = 

[25, 25, 45][564,365,654]
[56464,6464,54]