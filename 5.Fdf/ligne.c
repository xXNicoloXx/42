/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/06 15:14:13 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

void ft_ligne(float ax, float ay, float bx, float by, int color, void *mlx_win, void *mlx)
{
	float dx;
	float dy;
	float unity;
	float i;
	float ytmp;

	dx = bx - ax;
	dy = by - ay;
	unity = dy / dx;
	i = 0;
	ytmp = ay;
	if (unity < 1)
	{
		while (i++ < (int)dx)
		{
			if (98 < (ytmp - (int)ytmp))
			 	mlx_pixel_put(mlx, mlx_win, ax, ytmp+1, color);
			mlx_pixel_put(mlx, mlx_win, ax, ytmp, color);
			ytmp = ytmp + unity;
			ax++;
		}
	}
	else
	{
		while (i++ < (int)dy *2)
		{
			if (93 < (ax - (int)ax)*100)
				mlx_pixel_put(mlx, mlx_win, ax, ytmp+1, color);
			mlx_pixel_put(mlx, mlx_win, ax, ytmp, color);
			ytmp++;
			ax = ax + (1 / unity);
			i++;
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
// 	ft_ligne(50, 50, 90, 70, 0xffffff, mlx_win, mlx);
// 	ft_ligne(80, 80,500, 409, 0xffffff, mlx_win, mlx);

// 	//ft_ligne(10, 10,200, 20, 0xffffff, mlx_win, mlx);
// 	mlx_loop(mlx);
// }