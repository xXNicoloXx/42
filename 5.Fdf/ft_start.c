/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:59 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 19:39:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_all(t_map *m)
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
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0); //
	ft_monitoring(m);
}

int	ft_intivalue(t_map *m)
{
	ft_init_path_map(m);
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
	// printf("code = %d\n",ft_copy_map(m));
	if (ft_copy_map(m) == -1)
	{
		fprintf(stderr, "initvalue -1\n");
		return (-1);
	}
	m->z = m->winx / sqrt(pow(m->x * m->z, 2) + pow(m->y * m->z, 2));
	m->hauteur = m->z / 1000;
	m->minh = 0;
	m->maxh = 0;
	return (1);
}

int	ft_cross_close(t_map *m)
{
	ft_free_map(m, 1);
	mlx_destroy_image(m->mlx, m->img.i);
	mlx_destroy_window(m->mlx, m->mlx_win);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		color;
	t_map	m;


	m.pathmap.indexmap = 0;
	m.setupcolor = 0;
	m.verifmonitor = 1;
	m.pathmap.currentmap = argv[1];
	m.pathmap.map0 = argv[1];
	if (ft_intivalue(&m) == -1)
	{
		write(1, "MALLOC ERROR", 13);
		return (-1);
	}
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, m.winx, m.winy, "FDF");
	mlx_string_put(m.mlx, m.mlx_win, 5, 13, 0xffffff, "Loading ...");
	m.img.i = mlx_new_image(m.mlx, m.winx, m.winy);
	m.img.data = mlx_get_data_addr(m.img.i, &m.img.p, &m.img.size, &m.img.e);
	ft_all(&m);
	mlx_hook(m.mlx_win, 2, 1L << 0, &ft_key, &m);
	mlx_hook(m.mlx_win, 17, 1L << 0, &ft_cross_close, &m);
	mlx_mouse_hook(m.mlx_win, &ft_zoom, &m);
	mlx_do_key_autorepeaton(m.mlx);
	mlx_loop(m.mlx);
	return (1);
}
