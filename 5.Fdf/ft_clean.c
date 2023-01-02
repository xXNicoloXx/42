/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:11:57 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:12:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
