/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:57:28 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 18:57:00 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_x_map(char *ligne, int xmax)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ligne[i] != '\n' && ligne[i] != '\0')
	{
		if (ligne[i] != ' ')
		{
			x++;
			while (ligne[i] != ' ' && ligne[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (xmax < x)
		xmax = x;
	return (xmax);
}

int	ft_y_map(int fd, int *xmax)
{
	int		y;
	char	*ligne;

	y = 0;
	ligne = get_next_line(fd);
	while (ligne)
	{
		*xmax = ft_x_map(ligne, *xmax);
		y++;
		free(ligne);
		ligne = get_next_line(fd);
	}
	free(ligne);
	close(fd);
	return (y);
}

int	ft_fill_map_pt2(t_map *m, char *ligne, int y)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
		m->initm[y] = ft_calloc(sizeof(t_pixel), (m->x));
	while (ligne[i] != '\n' && ligne[i] != '\0')
	{
		if (ligne[i] != ' ')
		{
			m->initm[y][x].y = y * m->z;
			m->initm[y][x].x = x * m->z;
			m->initm[y][x].z = ft_atoi(ligne + i);
			x++;
			while (ligne[i] != ' ' && ligne[i] != '\0')

				i++;
		}
		else
			i++;
	}
}

void	ft_fill_map(t_map *m, int fd)
{
	int		y;
	char	*ligne;

	y = 0;
	ligne = get_next_line(fd);
	while (ligne)
	{
		ft_fill_map_pt2(m, ligne, y);
		y++;
		free(ligne);
		ligne = get_next_line(fd);
	}
	free(ligne);
}

int ft_copy_map(t_map *map)
{
	int	fd;

	fd = open(map->pathmap.currentmap, O_RDONLY);
	if (fd == -1)
	{
		fd = open("./test_maps/ERROR_MAP.fdf", O_RDONLY);
		map->pathmap.currentmap = "./test_maps/ERROR_MAP.fdf";
	}
	map->y = ft_y_map(fd, &map->x);
	map->initm = malloc(sizeof(t_pixel *) * (map->y));
	if (!(map->initm))
		return (-1);
	fprintf(stderr, "icci pote\n");
	fd = open(map->pathmap.currentmap, O_RDONLY);
	ft_fill_map(map, fd);
	return (1);
}
