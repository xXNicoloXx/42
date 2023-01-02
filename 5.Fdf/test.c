/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:59 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 18:58:59 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/X.h>

void	ft_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	m->m = malloc(sizeof(t_pixel *) * (m->y));
	while (y < m->y)
	{
		m->m[y] = ft_calloc(sizeof(t_pixel), (m->x));
		while (x < m->x)
		{
			m->m[y][x].y = y * m->z;
			m->m[y][x].x = x * m->z;
			m->m[y][x].z = m->initm[y][x].z ;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_hauteur(t_map *m)
{
	float	tmpy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].h = m->m[y][x].z ;
			if (m->m[y][x].h < m->minh)
			{
				m->minh = m->m[y][x].h;
			}
			if (m->maxh < m->m[y][x].h)
				m->maxh = m->m[y][x].h;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_rota(t_map *m)
{
	float	tmpx;
	int		x;
	int		y;

	x = 0;
	y = 0;
	m->varcos = cos(m->r / 57.2958);
	m->varsin = sin(m->r / 57.2958);
	while (y < m->y)
	{
		while (x < m->x)
		{
			tmpx = m->m[y][x].x;
			m->m[y][x].x = m->m[y][x].x * m->varcos + m->m[y][x].y * -m->varsin;
			m->m[y][x].y = tmpx * m->varsin + m->m[y][x].y * m->varcos;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_incl(t_map *m)
{
	int		x;
	int		y;
	float	varcos;
	float	varsin;

	x = 0;
	y = 0;
	varcos = cos(m->i / 57.2958);
	varsin = sin(m->i / 57.2958);
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].y = m->m[y][x].y * varsin;
			m->m[y][x].y += (m->m[y][x].z * m->hauteur) * m->z * -varcos;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_centre(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = m->m[y][x].x - m->x * m->z / 2;
			m->m[y][x].y = m->m[y][x].y - m->y * m->z / 2;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_move(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = (m->m[y][x].x + m->winx / 2) + m->movex;
			m->m[y][x].y = (m->m[y][x].y + m->winy / 2) + m->movey;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_free_map(t_map *m, int exit)
{
	int	y;

	y = 0;
	while (y < m->y)
	{
		free(m->m[y]);
		if (exit == 1)
			free(m->initm[y]);
		y++;
	}
	free(m->m);
	if (exit == 1)
		free(m->initm);
}

void	ft_clean(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (OS == 1)
	{
		while (y < m->winx)
		{
			while (x < m->winy)
			{
				ft_draw(m, x, y, 0);
				x++;
			}
			x = 0;
			y++;
		}
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0);
	}
	else
	{
		mlx_destroy_image(m->mlx, m->img.i);
		m->img.i = mlx_new_image(m->mlx, m->winx, m->winy);
	}
	ft_free_map(m, 0);
}

void	ft_annimationpt2(t_map *m)
{
	int	i;

	i = -1;
	while (++i < 360 / 3)
	{
		m->i += 0.65;
		m->r += 3;
		ft_clean(m);
		suite(m);
	}
	i = -1;
	while (++i < 360 / 3)
	{
		m->i -= 0.65;
		m->r += 3;
		ft_clean(m);
		suite(m);
	}
}

void	ft_annimation(t_map *m)
{
	int	inc;
	int	rot;

	inc = m->i;
	rot = m->r;
	m->i = 0;
	m->r = 0;
	ft_annimationpt2(m);
	ft_clean(m);
	m->i = inc;
	m->r = rot;
	suite(m);
}

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
		suite(m);
	}
	else
	{
		m->mouse_move = 1;
		x1 = x;
		y1 = y;
	}
}

void	ft_zoom(int keycode, int x, int y, t_map *m)
{
	if (keycode != 1)
		ft_clean(m);
	if (keycode == 5)
		m->z -= m->z * 0.2;
	else if (keycode == 4)
		m->z += m->z * 0.2;
	else if (keycode == 1)
	{
		ft_mouse_move(x, y, m);
		return ;
	}	
	suite(m);
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
	else if (keycode == ESC)
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

void	ft_key(int keycode, t_map *m)
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
	suite(m);
	return ;
}

void	ft_print_map_x(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y][x + 1].x;
	m->line.by = m->m[y][x + 1].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y][x + 1].h;
	ft_ligne(m);
}

void	ft_print_map_y(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y + 1][x].x;
	m->line.by = m->m[y + 1][x].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y + 1][x].h;
	ft_ligne(m);
}

void	ft_print_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			if (x < m->x - 1)
				ft_print_map_x(x, y, m);
			if (y < m->y -1)
				ft_print_map_y(x, y, m);
			x++;
		}
		y++;
		x = 0;
	}
}

void	suite(t_map *m)
{	
	if (m->i == 360)
		m->i = 0;
	if (m->i == -5)
		m->i = 355;
	if (m->r == 360)
		m->r = 0;
	if (m->r == -5)
		m->r = 355;
	ft_map(m);
	ft_hauteur(m);
	ft_centre(m);
	ft_rota(m);
	ft_incl(m);
	ft_move(m);
	ft_init_color(m);
	ft_print_map(m);
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0);
	ft_monitoring(m);
}

void	ft_intimap(t_map *m)
{
	m->winx = WIDTH;
	m->winy = HEIGHT;
	m->z = 1;
	m->r = 45;
	m->i = 20;
	m->hauteur = 0.02;
	m->movex = 0;
	m->movey = 0;
	m->x = 0;
	m->y = 0;
	m->mouse_move = 0;
	m->setupcolor = 0;
	m->verifmonitor = 1;
	ft_copy_map(m);
	m->z = m->winx / sqrt(pow(m->x * m->z, 2) + pow(m->y * m->z, 2));
	m->hauteur = m->z / 1000;
	m->minh = 0;
	m->maxh = 0;
}

int	main(void)
{
	int		color;
	t_map	m;

	ft_intimap(&m);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, m.winx, m.winy, "FDF");
	mlx_string_put(m.mlx, m.mlx_win, 5, 13, 0xffffff, "Loading ...");
	m.img.i = mlx_new_image(m.mlx, m.winx, m.winy);
	m.img.data = mlx_get_data_addr(m.img.i, &m.img.p, &m.img.size, &m.img.e);
	suite(&m);
	mlx_hook(m.mlx_win, 2, 1L<<0, ft_key, &m);
	mlx_mouse_hook(m.mlx_win, ft_zoom, &m);
	mlx_do_key_autorepeaton(m.mlx);
	mlx_loop(m.mlx);
}
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && ./a.out
//gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -I./ -L./ -lmlx -lm -lXext -lX11
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && valgrind --leak-check=full --show-leak-kinds=all  ./a.out
// APPLE gcc  *.c -I ./ -L ./ -lmlx -framework OpenGL -framework AppKit && ./a.out