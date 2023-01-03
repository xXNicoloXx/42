/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:07:05 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/03 12:22:27 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mouse_move(int x, int y, t_map *m)
{
	static int	x1;
	static int	y1;

	if (m->mouse_move == 1)
	{
		ft_clean(m);
		m->mouse_move = 0;
		m->r += (x - x1) / 30;
		m->i += (y - y1) / 30;
		ft_all(m);
	}
	else
	{
		m->mouse_move = 1;
		x1 = x;
		y1 = y;
	}
}

int	ft_zoom(int keycode, int x, int y, t_map *m)
{
	fprintf(stderr, "code %d\n", keycode);
	if (keycode != 1)
		ft_clean(m);
	if (keycode == 5)
		m->z -= m->z * 0.2;
	else if (keycode == 4)
		m->z += m->z * 0.2;
	else if (keycode == 1)
	{
		ft_mouse_move(x, y, m);
		return (1);
	}	
	ft_all(m);
	return (1);
}

void	ft_key_pt3(int keycode, t_map *m)
{
	if (keycode == Touch_S)
			m->movey = m->movey - 30;
	else if (keycode == Touch_D)
			m->movex = m->movex + 30;
	else if (keycode == Touch_A)
			m->movex = m->movex - 30;
	else if (keycode == Touch_C)
			m->setupcolor += 1;
	else if (keycode == ESC || keycode == -16779872)
	{
		ft_free_map(m, 1);
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		exit(0);
	}
	else if (keycode == Touch_M)
			m->verifmonitor *= -1;
}

void	ft_key_pt2(int keycode, t_map *m)
{
	if (keycode == Touch_One)
	{
		m->r = 0;
		m->i = 0;
	}
	else if (keycode == Touch_Tow)
	{
		m->i = 90;
		m->r = 0;
	}
	else if (keycode == Touch_Three)
	{
		m->r = 45;
		m->i = 20;
	}
	else if (keycode == Touch_Four)
	{
		m->r = -45;
		m->i = 20;
	}
	else if (keycode == Touch_Six)
		ft_annimation(m);
	else if (keycode == Touch_W)
			m->movey = m->movey + 30;
}

int	ft_key(int keycode, t_map *m)
{
	if (keycode == Touch_UpArrow)
			m->i = m->i + 5;
	else if (keycode == Touch_DownArrow)
			m->i = m->i - 5;
	else if (keycode == Touch_LeftArrow)
			m->r = m->r - 5;
	else if (keycode == Touch_RightArrow)
			m->r = m->r + 5;
	else if (keycode == Touch_Plus)
	{
		m->hauteur = m->hauteur + m->hauteur * 0.3;
		m->minh = 0;
		m->maxh = 0;
	}
	else if (keycode == Touch_Moins)
	{
		m->minh = 0;
		m->maxh = 0;
		m->hauteur = m->hauteur - m->hauteur * 0.3;
	}
	ft_key_pt2(keycode, m);
	ft_key_pt3(keycode, m);
	ft_clean(m);
	ft_all(m);
	return (1);
}
