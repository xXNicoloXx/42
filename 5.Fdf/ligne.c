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

int ft_color_line_with_map(float nbpix, float pospix, t_map *m)
{
	int color;
	int deltah;

	deltah = (float)m->maxh - (float)m->minh;
	if (m->MapColVerif == 2)
	{
		printf("1 = %.0f, 2 = %.0f\n",m->hcolor1, m->hcolor2 );
		// return 	((m->color[(int)(100*(m->hcolor2 - m->minh)/deltah)]*(pospix/nbpix)) + m->hcolor1 * (1-(pospix/nbpix)));
	}
	else if (m->MapColVerif == 3)
	{
		// printf("color = %.2f\n", (m->hcolor2 * (pospix/nbpix) + m->hcolor1 * (1-(pospix/nbpix))));
		return (m->hcolor2 * (pospix/nbpix) + m->hcolor1 * (1-(pospix/nbpix)));
		printf("color 1  = %.1f\t color 2 = %.1f\t nbr = %.0f \t pos = %.0f\n", m->hcolor1, m->hcolor2, nbpix, pospix);
	}
	return (0x505050);
}

int ft_color_line(float nbpix, float pospix, t_map *m)
{
	float tmp;
	float deltah;
	char *atoi;
	if (m->MapColVerif != 0)
		return (ft_color_line_with_map(nbpix,pospix, m));
	deltah = (float)m->maxh - (float)m->minh;
	// printf("deltah = %f\tlen = %.1f \ti =%.1f\th1 = %f\th2 = %f\n", deltah, nbpix, pospix, 100*(m->hcolor1 - m->minh)/deltah , 100*(m->hcolor2 - m->minh)/deltah);
	if (m->hcolor1 < m->hcolor2)
	{
		if (nbpix < 0)
			nbpix *= -1;
		if (pospix < 0)
			pospix *= -1;
		tmp = (((100*(m->hcolor2 - m->minh)/deltah) - (100*(m->hcolor1 - m->minh)/deltah))/nbpix);
		// printf("tmp = %f(%d)(%d) nbpix = %d\ti=%d\tcolor = %x\n",tmp, (int)(100*(m->hcolor1 - m->minh)/deltah), (int)(100*(m->hcolor2 - m->minh)/deltah), (int)nbpix, (int)pospix, m->color[(int)((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix)]);
		// printf(" < %.2f\n", ((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix));
		if (0 > (int)((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix))
			return (m->color[0]);
		else if  (99 < (int)((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix))
			return (m->color[99]);
		return (m->color[(int)((100*(m->hcolor1 - m->minh)/deltah) + tmp * pospix)]);
	}
	else if (m->hcolor1 > m->hcolor2)
	{
		tmp = (((100*(m->hcolor1 - m->minh)/deltah) - (100*(m->hcolor2 - m->minh)/deltah))/nbpix);
		// printf("tmp = %f(%d)(%d) nbpix = %d\ti=%d\n",tmp, (int)(100*(m->hcolor1 - m->minh)/deltah), (int)(100*(m->hcolor2 - m->minh)/deltah), (int)nbpix, (int)pospix);
		// printf("h1 = %.1f\thmin = %.1f\t deltah = %.1f> tmp = %.1f pospix = %.1f %.2f\n\n\n",m->hcolor1 , m->minh , deltah, tmp, pospix, ((100*(m->hcolor1 - m->minh)/deltah) - tmp * pospix));
		if (0 > (int)((100*(m->hcolor1 - m->minh)/deltah) - tmp * pospix))
			return (m->color[0]);
		else if  (99 < (int)((100*(m->hcolor1 - m->minh)/deltah) - tmp * pospix))
			return (m->color[99]);
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
}

void ft_ligne(float ax, float ay, float bx, float by, t_map *m)
{
	float dx;
	int reverse;
	float dy;
	float unity;
	float i;
	float tmp;
	if ((ax < 0 || ay < 0 || ax > m->winx || ay > m->winy) && (bx < 0 || by < 0 || bx > m->winx || by > m->winy))
		return ;
	reverse = 0;
	if (bx < ax)
	{
		tmp = bx;
		bx = ax;
		ax = tmp;
		tmp = by;
		by = ay;
		ay = tmp;
		reverse = 1;

	}
	
	
	dx = (float)bx - (float)ax;
	dy = (float)by - (float)ay;
	unity = dy / dx;
	i = 0;
	if (dy == 0)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{
			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		

	}
	else if ((0 < unity && unity < 1))
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{

			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
		

	}
	else if (-1 <= unity && unity < 0)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i++ < dx)
		{
			// printf("ici 3 ax =%.1f\tay = %.1f\tdx = %.1f\t i = %.1f\t", ax, ay , dx, i);

			ft_draw(m, ax, ay, ft_color_line(dx, i, m));
			ay = ay + unity;
			ax++;
		}
	}
	else if (1 <= unity)
	{
		if (reverse == 1)
		{
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i < dy)
		{

			ft_draw(m, ax, ay, ft_color_line(dy, i, m));
			ay++;
			ax = ax + (1 / unity);
			i++;
		}
		
	}
	else
	{
		if (reverse == 1)
		{			
			tmp = m->hcolor1;
			m->hcolor1 = m->hcolor2;
			m->hcolor2 = tmp;
		}
		while (i> dy)
		{

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