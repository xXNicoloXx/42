/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/05 02:03:36 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_monitoring_invalid_map(t_map *m)
{
	int		c;
	char	*t;

	t = MSG_INVALID_MAP;
	c = 0xffffff;
	mlx_string_put(m->mlx, m->mlx_win, m->winx / 2 - 100, m->winy / 2, c, t);
}

void	ft_monitoring_display_info_pt2(t_map *m, char *value)
{
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 6, 0xffffff, "I: ");
	value = ft_itoa((int)m->i);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 6, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 7, 0xffffff, "Z: ");
	value = ft_itoa((int)m->z);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 7, 0xffffff, value);
	free(value);
}

void	ft_monitoring_display_info_pt1(t_map *m)
{
	char	*value;

	mlx_string_put(m->mlx, m->mlx_win, 5, 13, 0xffffff, "x: ");
	value = ft_itoa((int)m->x);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 2, 0xffffff, "z: ");
	value = ft_itoa((int)m->y);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 2, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 3, 0xffffff, "h: ");
	value = ft_itoa((int)m->minh);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 3, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 4, 0xffffff, "H: ");
	value = ft_itoa((int)m->maxh);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 4, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 5, 0xffffff, "R:");
	value = ft_itoa((int)m->r);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 5, 0xffffff, value);
	free(value);
	ft_monitoring_display_info_pt2(m, value);
}

void	ft_monitoring_fade_color(t_map *m)
{
	int	c;
	int	y;
	int	x;

	c = 99;
	y = m->winy -100;
	while (y <= m->winy)
	{
		x = m->winx -7;
		while (x <= m->winx)
		{
			mlx_pixel_put(m->mlx, m->mlx_win, x, y, m->color[c]);
			x++;
		}
		c--;
		y++;
	}
}

void	ft_monitoring(t_map *m)
{
	int		i;
	int		j;

	if (m->verifmonitor != 1)
		return ;
	i = 0;
	j = 0;
	if (m->y == 0 && m->x == 0)
		ft_monitoring_invalid_map(m);
	else
	{
		ft_monitoring_fade_color(m);
		ft_monitoring_display_info_pt1(m);
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 11, 0xffffff, " WASD   |  MOVE");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 10, 0xffffff, "<- ->   |  ROTATE ");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 9, 0xffffff, " v ^    |  INCLINATION ");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 8, 0xffffff, " -  +   |  RELIEF DOWN/UP");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 7, 0xffffff, "1 2 3 4 |  PREPOSITION");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 6, 0xffffff, " 5      |  ANNIMATION");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 5, 0xffffff, " X  C   |  CHANGE COLOR");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 4, 0xffffff, " N  M   |  CHANGE MAP ");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 3, 0xffffff, " I      |  INFO OM/OFF ");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 2, 0xffffff, " ESC    |  EXIT");
		mlx_string_put(m->mlx, m->mlx_win, 5, m->winy - 13 * 1, 0xffffff, "RIGHT CLICK x2 |  MOVE");
	}
}
