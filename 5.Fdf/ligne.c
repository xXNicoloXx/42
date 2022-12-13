/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/13 10:58:47 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "fdf.h"

int ft_color_line(float nbpix, float pospix, t_map *m)
{
	float tmp;
	float deltah;
	if (m->lenline < 0)
		m->lenline *= -1;

	deltah = (float)m->maxh - (float)m->minh;
	// printf("deltah = %f\tlen = %.1f \ti =%.1f\th1 = %f\th2 = %f\n", deltah, nbpix, pospix, 100*(m->hcolor1 - m->minh)/deltah , 100*(m->hcolor2 - m->minh)/deltah);
	if (m->hcolor1 < m->hcolor2)
	{
		if (nbpix < 0)
			nbpix *= -1;
		if (pospix < 0)
			pospix *= -1;
		tmp = (((100*(m->hcolor2 - m->minh)/deltah) - (100*(m->hcolor1 - m->minh)/deltah))/nbpix);
		printf("tmp = %f(%d)(%d) nbpix = %d\ti=%d\n",tmp, (int)(100*(m->hcolor1 - m->minh)/deltah), (int)(100*(m->hcolor2 - m->minh)/deltah), (int)nbpix, (int)pospix);
		return (m->color[(int)((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix)]);
	}
	else if (m->hcolor1 > m->hcolor2)
	{
		tmp = (((100*(m->hcolor1 - m->minh)/deltah) - (100*(m->hcolor2 - m->minh)/deltah))/nbpix);
		// printf("tmp = %f(%d)(%d) nbpix = %d\ti=%d\n",tmp, (int)(100*(m->hcolor1 - m->minh)/deltah), (int)(100*(m->hcolor2 - m->minh)/deltah), (int)nbpix, (int)pospix);
		return (m->color[(int)((100*(m->hcolor1 - m->minh)/deltah) - tmp * pospix)]);
	}
	else 
	{
		tmp = (100*(m->hcolor2 - m->minh)/deltah);
		if (tmp == 100)
			tmp -= 1;
		// printf("color[%d] = %d\n", tmp, m->color[tmp]);
		return(m->color[(int)tmp]);
	}
		
	// m->maxh/100*m->hcolor1 - m->minh
	return (0x101010);
}

void ft_ligne(float ax, float ay, float bx, float by, t_map *m)
{
	float dx;
	float dy;
	float unity;
	float i;
	float tmp;
	// printf("\n\nax = %.0f\tay = %.0f\tbx = %.0f\tby = %.0f\n", ax, ay, bx, by);
	if (bx < ax)
	{
		tmp = bx;
		bx = ax;
		ax = tmp;
		tmp = by;
		by = ay;
		ay = tmp;
	}
	
	
	// printf("ax = %.0f\tay = %.0f\tbx = %.0f\tby = %.0f\n", ax, ay, bx, by);
	dx = (float)bx - (float)ax;
	dy = (float)by - (float)ay;
	// printf("dx = %.0f\tdy = %.0f\n", (float)dx, (float)dy);
	unity = dy / dx;
	// printf("unity = %.3f\n", unity);
	i = 0;
	if (dy == 0)
	{
		// printf("0\n");
		// printf("dx = %f\n", dx);
		while (i++ < dx)
		{
			// if (98 < (ytmp - (int)ytmp))
			//  	ft_draw(m, ax, ytmp+1, ft_color_line(ax, ay, bx, by, m));
			// printf("ax = %f ay %f\n", ax, ay);
			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		return ;
	}
	else if ((0 < unity && unity < 1))
	{
		while (i++ < dx)
		{
			// if (98 < (ytmp - (int)ytmp))
			//  	ft_draw(m, ax, ytmp+1, ft_color_line(ax, ay, bx, by, m));
			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		return ;
	}
	else if (-1 <= unity && unity < 0)
	{
		while (i++ < dx)
		{
			//printf("test");

			// if (98 < (ytmp - (int)ytmp))
			//  	ft_draw(m, ax, ytmp+1, ft_color_line(ax, ay, bx, by, m));
			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		return ;
	}
	else if (1 <= unity)
	{
		while (i < dy)
		{
			// if (2 < (ax - (int)ax)*100)
			// 	ft_draw(m, ax, ytmp+1, ft_color_line(ax, ay, bx, by, m));
			ft_draw(m, ax, ay, ft_color_line(dy, i, m));
			ay++;
			ax = ax + (1 / unity);
			i++;
		}
		return ;
	}
	else
	{
		while (i> dy)
		{
			// if (2 < (ax - (int)ax)*100)
			// 	ft_draw(m, ax, ytmp+1, ft_color_line(ax, ay, bx, by, m));
			ft_draw(m, ax, ay, ft_color_line(dy, i, m));
			ay--;
			ax = ax - (1 / unity);
			i--;
		}
	}
}
// int main (void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	int	 color;
	

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1000, 800, "");
// 	ft_ligne(100, 100, 200, 120, 0xff0000, mlx_win, mlx);
// 	ft_ligne(100, 100, 120, 200, 0x00ff00, mlx_win, mlx);
// 	ft_ligne(100, 100, 200, 80, 0x0ff0ff, mlx_win, mlx);
// 	ft_ligne(100, 100, 120, 0, 0xffffff, mlx_win, mlx);
	
// 	ft_ligne(100, 100, 0, 120, 0xff0000, mlx_win, mlx);
// 	ft_ligne(100, 100, 80, 200, 0x00ff00, mlx_win, mlx);
// 	ft_ligne(100, 100, 0, 80, 0x0ff0ff, mlx_win, mlx);
// 	ft_ligne(100, 100, 80, 0, 0xffffff, mlx_win, mlx);


// 	ft_ligne(100, 100, 100, 0, 0xff80ff, mlx_win, mlx);
// 	ft_ligne(100, 100, 100, 200, 0xff80ff, mlx_win, mlx);
// 	ft_ligne(100, 100, 0, 100, 0xff80ff, mlx_win, mlx);
// 	ft_ligne(100, 100, 200, 100, 0xff80ff, mlx_win, mlx);

// 	ft_ligne(100, 100, 0, 0, 0x8fffff, mlx_win, mlx);
// 	ft_ligne(100, 100, 0, 200, 0x8f0000, mlx_win, mlx);
// 	ft_ligne(100, 100, 200, 0, 0xffff00, mlx_win, mlx);
// 	ft_ligne(100, 100, 200, 200, 0x0000ff, mlx_win, mlx);
	
// 	int i = 0;
// 	int j = 0;

// 	while (i < 200)
// 	{
// 		ft_ligne(100, 100, i, 0, 0xff0000, mlx_win, mlx);
// 		i = i+11;
// 	}
// 	while (j < 200)
// 	{
// 		ft_ligne(100, 100, 200, j, 0x00ff00, mlx_win, mlx);
// 		j = j+11;
// 	}
// 	while (i > 0)
// 	{
// 		ft_ligne(100, 100, i, 200, 0x0000ff, mlx_win, mlx);
// 		i = i-11;
// 	}
// 	while (j > 0)
// 	{
		
// 		ft_ligne(100, 100, 0, j, 0xffffff, mlx_win, mlx);
// 		j = j-11;
// 	}
	
	
// 	// 


	

// 	//ft_ligne(10, 10,200, 20, 0xffffff, mlx_win, mlx);
// }