/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/13 15:48:03 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/X.h>

int ft_monitoring(t_map *m)
{
    int i;
    int j;
    char *value;
    i = 0;
    j = 0;
    if (m->y == 0 && m->x == 0)
	{
		printf("pas bon");
		mlx_string_put(m->mlx,  m->mlx_win, m->winx/2-100, m->winy/2, 0xffffff, "Error invalid map");
	}
    else
    {
    while (i < 95)
    {
        while (j < 50)
        {
            mlx_pixel_put(m->mlx, m->mlx_win, j,  i, 0x202020);
            j++;
        }
        j = 0;
        i++;
    }

	mlx_string_put(m->mlx,  m->mlx_win, 5, 13, 0xffffff, "x: ");
    value = ft_itoa(m->x);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13, 0xffffff, value);
    free(value);

    mlx_string_put(m->mlx,  m->mlx_win, 5, 13*2, 0xffffff, "z: ");
    value = ft_itoa(m->y);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13*2, 0xffffff, value);
    free(value);

    mlx_string_put(m->mlx,  m->mlx_win, 5, 13*3, 0xffffff, "h: ");
    value = ft_itoa(m->minh);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13*3, 0xffffff, value);
    free(value);

    mlx_string_put(m->mlx,  m->mlx_win, 5, 13*4, 0xffffff, "H: ");
    value = ft_itoa(m->maxh);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13*4, 0xffffff, value);
    free(value);
    mlx_string_put(m->mlx,  m->mlx_win, 5, 13 *5, 0xffffff, "R:");

    value = ft_itoa(m->r);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13 *5, 0xffffff, value);
    free(value);
    mlx_string_put(m->mlx,  m->mlx_win, 5, 13*6, 0xffffff, "I: ");
    value = ft_itoa(m->r);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13*6, 0xffffff, value);
    free(value);

    mlx_string_put(m->mlx,  m->mlx_win, 5, 13*7, 0xffffff, "Z: ");
    value = ft_itoa(m->z);
    mlx_string_put(m->mlx,  m->mlx_win, 20, 13*7, 0xffffff, value);
    free(value);
    }
}