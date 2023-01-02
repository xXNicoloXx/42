/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:56:24 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/12 19:46:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_color(int nbr, t_map *m)
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
	
	if (m->img.e == 1)
	{
		m->img.data[pixel + 0] = 0;
		m->img.data[pixel + 1] = m->img.r;
		m->img.data[pixel + 2] = m->img.g;
		m->img.data[pixel + 3] = m->img.b;
	}
	else if (m->img.e == 0)
	{
		m->img.data[pixel + 0] = m->img.b;
		m->img.data[pixel + 1] = m->img.g;
		m->img.data[pixel + 2] = m->img.r;
		m->img.data[pixel + 3] = 0;
	}
}

void ft_tab_deg(t_map *m, int start, int end)
{
	int i;
	float pc;
	float diff;
	t_map c;
	
	ft_color(m->color[start], m);
	ft_color(m->color[end], &c);
	diff = end - start - 1;
	i = 0 ;
	while (i <= diff)
	{
		pc = ((i)/diff);
		m->color[start + i] = roundf((m->img.r*(1-pc)) + (c.img.r*pc))* 65536 + roundf((m->img.g*(1-pc)) + (c.img.g*pc)) * 256 + roundf((m->img.b*(1-pc)) + (c.img.b*pc));
		i++;
	}
}

void ft_tab_color(t_map *m)
{
	int i;
	int j;
	
	i = 0;
	while (i < 101)
	{
		if (m->color[i] != 0)
		{
			j = i;
			i++;		
			while (i <= 99 && m->color[i] == 0)
				i++;
			if (99 < i)
				return ;
			ft_tab_deg(m, j, i);				
		}
		else
			i++;
	}
}

void ft_setup_color_pt2(t_map *m)
{
	if (m->setupcolor == 4)
	{
		m->color[0] = 0x333333;
		m->color[99] = 0xffffff;
	}
	else if (m->setupcolor == 5)
	{
		m->color[0] = 0xff0000;
		m->color[15] = 0xffa500;
		m->color[30] = 0xffff00;
		m->color[45] = 0x00f000;
		m->color[60] = 0x0060ff;
		m->color[75] = 0x8b00f2;
		m->color[99] = 0xee82ee;
	}
	else if (m->setupcolor == 6)
	{
			m->color[0] = 0x000001;
	m->color[10] = 0x004C75;
	// m->color[61] = 0x0094E3;
	m->color[59] = 0x0094E3;
	m->color[61] = 0xe0cda9;
	m->color[63] = 0x72CC00;
	m->color[70] = 0x298000;			//worldmap
	m->color[78] = 0x4f3000;
	m->color[80] = 0xffffff;
	m->color[99] = 0xffffff;
	}
}

void ft_setup_color_pt1(t_map *m)
{
	if (m->setupcolor == 0)
	{
		m->color[0] = 0x0000ff;
		m->color[99] = 0xff0000;
	}
	else if (m->setupcolor == 1)
	{
		m->color[0] = 0xff00ff;
		m->color[99] = 0x0070ff;
	}
	else if (m->setupcolor == 2)
	{
		m->color[0] = 0xff0000;
		m->color[99] = 0xffff00;
	}
	else if (m->setupcolor == 3)
	{
		m->color[0] = 0x00ff00;
		m->color[99] = 0xff00ff;
	}
	else
		ft_setup_color_pt2(m);
}

void ft_init_color(t_map *m)
{
	int i;

	i = 0;
	while(i < 100)
	{
		m->color[i] = 0;
		i++;
	}
	if (m->setupcolor > 6)
		m->setupcolor = 0;
	ft_setup_color_pt1(m);
	ft_tab_color(m);
}
// int main(void)
// {
//	 t_map m;
//	 ft_color(0xffffff, &m);
//     printf("r = %d\n",m.img.r);
//     printf("g = %d\n",m.img.g);
//     printf("b = %d\n",m.img.b);
// }
	// m->color[0] = 0x000001;
	// m->color[10] = 0x004C75;
	// m->color[61] = 0x0094E3;
	// // m->color[59] = 0x0094E3;
	// // m->color[61] = 0xe0cda9;
	// m->color[63] = 0x72CC00;
	// m->color[70] = 0x298000;			//worldmap
	// m->color[78] = 0x4f3000;
	// m->color[80] = 0xffffff;
	// m->color[99] = 0xffffff;
	// m->color[0] = 0xff0000;		//42
	// m->color[99] = 0xffffff;//