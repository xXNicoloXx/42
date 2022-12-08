/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:59 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/08 18:29:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <X11/X.h>

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


void ft_fill_map(t_map *m, int fd)
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
		m->m[y] = ft_calloc(sizeof(t_pixel),(m->x + 1));
		while (ligne[i] != '\n' && ligne[i] != '\0')
		{
			if (ft_isdigit(ligne[i]) || ligne[i] == '-')
			{
				//printf("\tmap[%d][%d] = %d\n",y, x , map[y][x]);
				m->m[y][x].y = y * m->z;
				m->m[y][x].x = x * m->z;
				m->m[y][x].z = ft_atoi(ligne + i) + 10;

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

	fd = open(MAP, O_RDONLY);
	map->y = ft_y_map(fd, &map->x);
	map->m = malloc(sizeof(t_pixel *) * (map->y + 1));	
	fd = open(MAP, O_RDONLY);
	ft_fill_map(map, fd);
}
void ft_hauteur(t_map *m)
{
	float tmpy;
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].h = m->m[y][x].z;
			x++;
		}
		y++;
		x = 0;
	}
}


void ft_rota(t_map *m)
{
	float tmpx;
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			tmpx = m->m[y][x].x;
			m->m[y][x].x = m->m[y][x].x * cos(m->r/57.2958) + m->m[y][x].y * -sin(m->r/57.2958);
			m->m[y][x].y = tmpx * sin(m->r/57.2958) + m->m[y][x].y * cos(m->r/57.2958);
			x++;
		}
		y++;
		x = 0;
	}
}
void ft_incl(t_map *m)
{
	float tmpy;
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			//printf("m = %f\t%f\n", m->m[y][x].x * cos(m->r), m->m[y][x].y * sin(m->r));
			tmpy = m->m[y][x].y;
			m->m[y][x].y = m->m[y][x].z * -cos(m->i/57.2958) + m->m[y][x].y * sin(m->i/57.2958);
			x++;
		}
		y++;
		x = 0;
	}
}

void ft_centre(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = m->m[y][x].x - m->x*m->z/2;
			m->m[y][x].y = m->m[y][x].y - m->y*m->z/2;

			x++;
		}
		y++;
		x = 0;
	}

}

void ft_move(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = m->m[y][x].x + m->winx/2;
			m->m[y][x].y = m->m[y][x].y + m->winy/2;
			x++;
		}
		y++;
		x = 0;
	}

}
void ft_clean(t_map *m)
{
	int y;

	y = 0;
	while (y < m->winy)
	{
		ft_ligne(0, y, m->winx , y , 0, m->mlx_win, m->mlx);
		y++;
	}
	return 0;
}

int suite(t_map *m);

int	ft_zoom(int keycode, t_map *m)
{
	fprintf(stderr, "code %d\n", keycode);
	fprintf(stderr, "Touche %c\n", keycode);
	write(1, "coucou\n", 7);
	m->r = m->r + 10;
	ft_clean(m);
	suite(m);

	// mlx_destroy_window(m->mlx, m->mlx_win);
	return 0;
}

int suite(t_map *m)
{	
	printf("zoom = %f", m->z);
	int x = 0;
	int y = 0;
	// printf("Map\n");
	ft_map(m);
	// printf("Map OK\nHauteur\n");
	ft_hauteur(m);
	// printf("Hauteur OK\nCentre\n");
	ft_centre(m);
	// printf("Centre OK\nRota\n");
	ft_rota(m);
	// printf("Rota OK\nIncl\n");
	ft_incl(m);
	// printf("Incl OK\nMove\n");
	ft_move(m);
	// printf("Move ok\n Affichage\n");
	// printf("x = 0 -> %d \t y = 0 -> %d    \n\n", m->x, m->y);
	// printf("I = %.1f°\tR = %.1f\tZ = %.1fx°  \n", m->i, m->r, m->z);
	while (y < m->y-1)
	{
		while (x < m->x-1)
		{
			ft_ligne(m->m[y][x].x, m->m[y][x].y, m->m[y][x+1].x, m->m[y][x+1].y, m->m[y][x].h * 5000, m->mlx_win, m->mlx);
			ft_ligne(m->m[y][x].x, m->m[y][x].y, m->m[y+1][x].x, m->m[y+1][x].y, m->m[y][x].h * 5000, m->mlx_win, m->mlx);
			x++;
		}
		y++;
		x = 0;
	}
	printf("\n1\n");
	// mlx_hook(m->mlx_win, KeyPres, KeyPressMask, )
	printf("2\n");
	return 0;

}



int main(void * mlxptr, void* mlxwinptr)
{
	int color;
	t_map m;

	m.winx = 1920;
	m.winy = 1080;
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, m.winx, m.winy, "FDF");
	
	m.y = 0;  
	m.x = 0;
	m.z = 20;
	m.r = 50;
	m.i = 50;
	color = 0xffffff;

	

	
	suite(&m);
	printf("fin\n");
	mlx_key_hook(m.mlx_win, ft_zoom, &m);
	mlx_loop(m.mlx);
	printf("test");
}

//push
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && ./a.out
//gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -I./ -L./ -lmlx -lm -lXext -lX11
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && valgrind --leak-check=full --show-leak-kinds=all  ./a.out