/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:36:35 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/07 16:32:56 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "fdf.h"

int ft_x_map(char *ligne, int xmax)
{
    int i;
    int x;
	
	i = 0;
	x = 0;
	while (ligne[i] != '\n' && ligne[i] != '\0')
	{
		if (ft_isdigit(ligne[i]))
		{
			x++;
			// printf("x = %d\n",x);
			while (ft_isdigit(ligne[i]))
				i++;
		}
		else
			i++;
	}
	if (xmax < x)
		xmax = x;
	return (xmax);
}

int ft_y_map(int fd, int *xmax)
{
    int y;
    char *ligne;
    
    y = 0;
    while (ligne = get_next_line(fd))
    {
		*xmax = ft_x_map(ligne, *xmax);
		//printf("xmax = %d\n",*xmax);
		free(ligne);    
        y++;
	}
	close(fd);
    return (y);
}


void ft_fill_map(int xmax, int fd, int **map)
{
    int i;
	int y;
	int x;
	char *ligne;
	
	y = 0;
    i = 0;
    x = 0;
	while (ligne = get_next_line(fd))
	{
		// printf("\t%s", ligne);
    	map[y] = ft_calloc(sizeof(int *),(xmax + 1));
		while (ligne[i] != '\n' && ligne[i] != '\0')
		{
			if (ft_isdigit(ligne[i]) || ligne[i] == '-')
			{
				//printf("\tmap[%d][%d] = %d\n",y, x , map[y][x]);
				map[y][x] = ft_atoi(ligne + i);
				//printf("\tmap[%d][%d] = %d\n",y, x , map[y][x]);
				x++;
				while (ft_isdigit(ligne[i]) || ligne[i] == '-')
					i++;
			}
			else
				i++;
		}
		i = 0;
		x = 0;
		y++;
	}
}

void	ft_map(t_map *map)
{
    int fd;

    fd = open("./test_maps/42.fdf", O_RDONLY);
	map->y = ft_y_map(fd, &map->x);
    map->map = malloc(sizeof(int *) * (map->y + 1));    
    fd = open("./test_maps/42.fdf", O_RDONLY);
    ft_fill_map(map->x, fd, map->map);
}

void ft_pu_pix(void *mlx, void *mlx_win, int x, int y, t_map map)
{
	int size = 50;
	int i = 0;
	int j = 0;
	int color;
	// if (map.map[y][x] == 0)
	// 	color = 0xf00000;
	// else
	// 	color = 0xff990f;
	while (i < size)
	{
		while(j < size)
		{
			mlx_pixel_put(mlx, mlx_win, x*size + j, y*size + i, map.map[y][x]*10000);
			j++;
		}
		j = 0;
		i++;
		
	}
}
int main (void)
{
	int x = 0;
	int y = 0;
	int color;

	t_map m;
	
	m.y = 0;
	m.x = 0;
	m.z = 40;
	m.r = 1.57079632679;
	m.d = 500;
    ft_map(&m);
	printf("------  x = %d, y = %d  ------  \n\n", m.x, m.y);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, 1920, 1080, "FDF");
	while (y < m.y)
	{
		while (x < m.x)
		{
			color = (m.map[y][x] + 1) *5000;
			if (m.map[y][x] != m.map[y][x+1])
				color = 4 * 5500;
			mlx_pixel_put(m.mlx, m.mlx_win, m.d+x*m.z + y*m.z*sin(m.r), m.d+y*m.z+x*m.z*-sin(m.r), 0xff0000);
			printf("cos = %f, sin = %f\n",  cos(m.r), -sin(m.r));
			printf("woydgwiuydviwuyvdiuwyvdiwu = %f\n", m.z*tan(m.r));
			ft_ligne(m.d+x*m.z + y*m.z*sin(m.r), m.d+y*m.z+x*m.z*-sin(m.r),m.d+x*m.z + y*m.z*sin(m.r) + m.z, m.d+y*m.z+x*m.z*-sin(m.r) - m.z*sin(m.r), 0xffffff, m.mlx_win, m.mlx);
			color = (m.map[y][x] + 1) *5000;
			if (y < m.y-1 && (m.map[y][x] != m.map[y + 1][x]))
				color = 4 * 5500;
			//ft_ligne(x*m.z, y*m.z, x*m.z+sin(m.r)*m.z, y*m.z+cos(m.r)*m.z, color, m.mlx_win, m.mlx);
			
			x++;
		}
		y++;
		x = 0;
	}
	ft_ligne(0, 980, 980, 0, 0xffffff, m.mlx_win, m.mlx);

	mlx_loop(m.mlx);
}
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && ./a.out














// int main (void)
// {
// 	int x = 0;
// 	int y = 0;
// 	int color;

// 	t_map m;
	
// 	m.y = 0;
// 	m.x = 0;
// 	m.z = 50;
// 	m.r = 0;
//     ft_map(&m);
// 	printf("------  x = %d, y = %d  ------  \n\n", m.x, m.y);
// 	m.mlx = mlx_init();
// 	m.mlx_win = mlx_new_window(m.mlx, 1920, 1080, "FDF");
// 	while (y < m.y)
// 	{
// 		while (x < m.x)
// 		{
// 			color = (m.map[y][x] + 1) *5000;
// 			if (m.map[y][x] != m.map[y][x+1])
// 				color = 4 * 5500;
// 			printf("cos = %f, sin = %f\n", cos(m.r)*m.z, -sin(m.r) *m.z);
// 			ft_ligne(x*m.z, y*m.z, x*m.z+(cos(m.r)*m.z), y*m.z-sin(m.r)*m.z, color, m.mlx_win, m.mlx);
// 			color = (m.map[y][x] + 1) *5000;
// 			if (y < m.y-1 && (m.map[y][x] != m.map[y + 1][x]))
// 				color = 4 * 5500;
// 			ft_ligne(x*m.z, y*m.z, x*m.z+sin(m.r)*m.z, y*m.z+cos(m.r)*m.z, color, m.mlx_win, m.mlx);
			
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	mlx_loop(m.mlx);
// }
// //c