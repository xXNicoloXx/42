/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 16:48:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "fdf.h"

int	ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	if (nbpix < 0)
			nbpix *= -1;
	if (pospix < 0)
			pospix *= -1;
	tmp = 100 * (m->hcolor2 - m->minh) / deltah;
	tmp -= 100 * (m->hcolor1 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->hcolor1 - m->minh) / deltah) + tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	tmp = 100 * (m->hcolor1 - m->minh) / deltah;
	tmp -= 100 * (m->hcolor2 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->hcolor1 - m->minh) / deltah) - tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line(float nbpix, float pospix, t_map *m)
{
	float	tmp;
	float	deltah;

	deltah = (float)m->maxh - (float)m->minh;
	if (m->hcolor1 < m->hcolor2)
		return (ft_color_line_up(nbpix, pospix, deltah, m));
	else if (m->hcolor1 > m->hcolor2)
		return (ft_color_line_down(nbpix, pospix, deltah, m));
	else
	{
		tmp = (100 * (m->hcolor2 - m->minh) / deltah);
		if (tmp == 100)
			tmp -= 1;
		return (m->color[(int)tmp]);
	}
}

void ft_ligne(float ax, float ay, float bx, float by, t_map *m)
{
	float dx;
	int reverse;
	float dy;
	float unity;
	float i;
	float tmp;
	if ((ax < 0 || ay < 0 || ax > m->winx || ay > m->winy) && (bx < 0 || by < 0 || bx > m->winx || by > m->winy))
		return ;
	reverse = 0;
	if (bx < ax)
	{
		tmp = bx;
		bx = ax;
		ax = tmp;
		tmp = by;
		by = ay;
		ay = tmp;
		reverse = 1;

	}
	
	
	dx = (float)bx - (float)ax;
	dy = (float)by - (float)ay;
	unity = dy / dx;
	i = 0;
	if (dy == 0)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{
			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		

	}
	else if ((0 < unity && unity < 1))
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{

			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		

	}
	else if (-1 <= unity && unity < 0)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{
			// printf("ici 3 ax =%.1f\tay = %.1f\tdx = %.1f\t i = %.1f\t", ax, ay , dx, i);

			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
	}
	else if (1 <= unity)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i < dy)
		{

			ft_draw(m, ax, ay, ft_color_line(dy, i, m));
			ay++;
			ax = ax + (1 / unity);
			i++;
		}
		
	}
	else
	{
		if (reverse == 1)
		{			
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i> dy)
		{

			ft_draw(m, ax, ay, ft_color_line(dy, i, m));
			ay--;
			ax = ax - (1 / unity);
			i--;
		}
		
	}
}