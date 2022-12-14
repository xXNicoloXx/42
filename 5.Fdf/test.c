/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:59 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/12 19:49:18 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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
		m->initm[y] = ft_calloc(sizeof(t_pixel),(m->x + 1));
		while (ligne[i] != '\n' && ligne[i] != '\0')
		{
			if (ft_isdigit(ligne[i]) || ligne[i] == '-')
			{
				//printf("\tmap[%d][%d] = %d\n",y, x , map[y][x]);
				m->initm[y][x].y = y * m->z;
				m->initm[y][x].x = x * m->z;
				m->initm[y][x].z = ft_atoi(ligne + i);

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

void	ft_copy_map(t_map *map)
{
	int fd;

	fd = open(MAP, O_RDONLY);
	map->y = ft_y_map(fd, &map->x);
	map->initm = malloc(sizeof(t_pixel *) * (map->y + 1));	
	fd = open(MAP, O_RDONLY);
	ft_fill_map(map, fd);
}

void ft_map(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	m->m = malloc(sizeof(t_pixel *) * (m->y + 1));	
	while (y < m->y)
	{
		m->m[y] = ft_calloc(sizeof(t_pixel),(m->x + 1));
		while (x < m->x)
		{
			m->m[y][x].y = y * m->z;
			m->m[y][x].x = x * m->z;
			m->m[y][x].z = m->initm[y][x].z *m->hauteur;
			x++;
		}
		y++;
		x = 0;
	}

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
			if (m->m[y][x].h < m->minh)
				m->minh = m->m[y][x].h;

			if (m->maxh < m->m[y][x].h)
				m->maxh = m->m[y][x].h;
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
	m->varcos = cos(m->r/57.2958);
	m->varsin = sin(m->r/57.2958);
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
void ft_incl(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			//printf("m = %f\t%f\n", m->m[y][x].x * cos(m->r), m->m[y][x].y * sin(m->r));
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
			m->m[y][x].x = m->m[y][x].x + m->winx/2 + m->movex;
			m->m[y][x].y = m->m[y][x].y + m->winy/2 + m->movey;
			x++;
		}
		y++;
		x = 0;
	}

}
void ft_clean(t_map *m)
{
	int y;
	int x;

	y = 0;
	x = 0;
	write(1, "Clean\n", 7);
	mlx_destroy_image(m->mlx, m->img.i);
	m->img.i = mlx_new_image(m->mlx, m->winx, m->winy);
}

int suite(t_map *m);

// int	ft_key(int keycode, t_map *m) // Mac
// {
// 	ft_clean(m);
// 	if (keycode == 126)
// 			m->i = m->i + 5;
// 	else if (keycode == 125)
// 			m->i = m->i - 5;
// 	else if (keycode == 123)
// 			m->r = m->r - 5;
// 	else if (keycode == 124)
// 			m->r = m->r + 5;
// 	else if (keycode == 1)
// 			m->z = m->z - 5;
// 	else if (keycode == 13)
// 			m->z = m->z + 5;
			
// 	fprintf(stderr, "code %d\n", keycode);
// 	write(1, "coucou\n", 7);
// 	suite(m);
// 	// mlx_destroy_window(m->mlx, m->mlx_win);
// 	return 0;
// }
void ft_zoom(int keycode, int x, int y, t_map *m)
{
	ft_clean(m);
	if (keycode == 5)
			m->z -= m->z*0.2;
	else if (keycode == 4)
			m->z += m->z*0.2;
	suite(m);
}

void	ft_key(int keycode, t_map *m) //linux
{
	fprintf(stderr, "code %d\n", keycode);
	ft_clean(m);
	if (keycode == 65362)
			m->i = m->i + 5;
	else if (keycode == 65364)
			m->i = m->i - 5;
	else if (keycode == 65361)
			m->r = m->r - 5;
	else if (keycode == 65363)
			m->r = m->r + 5;
	else if (keycode == 61)
		m->hauteur = m->hauteur + m->hauteur * 0.3;
	else if (keycode == 45)
		m->hauteur = m->hauteur - m->hauteur *0.3;
	else if (keycode == 32)
		ft_intimap(m);
	else if (keycode == 48)
	{
			m->i = 90;
			m->r = 0;
	}
	else if (keycode == 119)
			m->movey = m->movey + 10;
	else if (keycode == 115)
			m->movey = m->movey - 10;
	else if (keycode == 97)
			m->movex = m->movex + 10;
	else if (keycode == 100)
			m->movex = m->movex - 10;
	

		

	suite(m);
	// mlx_destroy_window(m->mlx, m->mlx_win);
	return ;
}

void ft_print_map(t_map *m)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			if (x < m->x - 1)
			{	
				m->hcolor1 = m->m[y][x].h;
				m->hcolor2 = m->m[y][x+1].h;	
				ft_ligne(m->m[y][x].x, m->m[y][x].y, m->m[y][x+1].x, m->m[y][x+1].y, m);
			}
			if (y < m->y -1)
			{
				m->hcolor1 = m->m[y][x].h;
				m->hcolor2 = m->m[y+1][x].h;
				ft_ligne(m->m[y][x].x, m->m[y][x].y, m->m[y+1][x].x, m->m[y+1][x].y, m);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

int suite(t_map *m)
{	
	float t1 = clock();
	ft_map(m);
	float t2 = clock();
	printf("Map \t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_hauteur(m);
	t2 = clock();
	printf("Hauteur\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_centre(m);
	t2 = clock();
	printf("Centre\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_rota(m);
	t2 = clock();
	printf("Rota\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_incl(m);
	t2 = clock();
	printf("Incl\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_move(m);
	t2 = clock();
	printf("Move\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_init_color(m);
	t2 = clock();
	printf("Color\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_print_map(m);
	t2 = clock();
	printf("Draw\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0);
	t2 = clock();
	printf("put img\t\t\t%.1f\n", (t2 - t1)/1000);
	t1 = clock();
	ft_monitoring(m);
	// printf("x = 0 -> %d \t y = 0 -> %d  h = %.0f \t H = %.0f  \n\n", m->x, m->y, m->minh, m->maxh);
	// printf("I = \t\t\t%.1f°\tR = \t\t\t%.1f\tZ = \t\t\t%.1fx°\n\n", m->i, m->r, m->z);
	t2 = clock();
	printf("end\t\t\t%.1f\n", (t2 - t1)/1000);
	return 0;
}

void ft_intimap(t_map *m)
{

	m->winx = 2520;
	m->winy = 1480;
	m->z = 1;
	m->r = 45;
	m->i = 45;
	m->hauteur = 0.01;
	m->movex = 0;
	m->movey = 0;
	float t1 = clock();
	ft_copy_map(m);
	float t2 = clock();
	printf("copy map\t\t%.1f\n\n\n", (t2 - t1)/1000);
	m->z = m->winx / sqrt((m->x*m->z) * (m->x*m->z) + (m->y*m->z) * (m->y*m->z));
	m->hauteur = m->z / 100;
	m->minh = 0;
	m->maxh = 0;
}

int main(void)
{
	int color;
	t_map m;

	ft_intimap(&m);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, m.winx, m.winy, "FDF");
	mlx_string_put(m.mlx,  m.mlx_win, 5, 13, 0xffffff, "Loading ...");

	ft_init_color(&m);
	


	m.img.i = mlx_new_image(m.mlx, m.winx, m.winy);
	m.img.data = mlx_get_data_addr(m.img.i , &m.img.p, &m.img.size, &m.img.e);
	// ft_map(&m);
	suite(&m);
	ft_tab_color(&m);
	mlx_key_hook(m.mlx_win, ft_key, &m);
	mlx_mouse_hook(m.mlx_win, ft_zoom, &m);
	mlx_do_key_autorepeaton(m.mlx);
	mlx_loop(m.mlx);
}
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && ./a.out
//gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -I./ -L./ -lmlx -lm -lXext -lX11
//clear && gcc ft_isdigit.c test.c ft_atoi.c ft_calloc.c get_next_line_utils.c get_next_line.c ligne.c -lmlx -lm -lXext -lX11 -I ./minilibx/ -L ./minilibx && valgrind --leak-check=full --show-leak-kinds=all  ./a.out
// APPLE gcc  *.c -I ./ -L ./ -lmlx -framework OpenGL -framework AppKit && ./a.out || grep "error"