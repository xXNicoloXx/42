/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:13 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/03 11:04:36 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_annimationpt2(t_map *m)
{
	int	i;

	i = -1;
	while (++i < 360 / 3)
	{
		m->i += 0.65;
		m->r += 3;
		ft_clean(m);
		ft_all(m);
	}
	i = -1;
	while (++i < 360 / 3)
	{
		m->i -= 0.65;
		m->r += 3;
		ft_clean(m);
		ft_all(m);
	}
}

void	ft_annimation(t_map *m)
{
	int	inc;
	int	rot;

	inc = m->i;
	rot = m->r;
	m->i = 0;
	m->r = 0;
	ft_annimationpt2(m);
	ft_clean(m);
	m->i = inc;
	m->r = rot;
	ft_all(m);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:49:25 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/11 11:18:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	nb;

	signe = 1;
	i = 0;
	nb = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -signe;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * signe);
}
// may la boss

// int main(void)
// {
// 	char *test = "    +286543554s";
// 	printf("%d\n", ft_atoi(test));
// 	printf("%d", atoi(test));
// }/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:33:14 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/15 14:48:41 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbitems, size_t size)
{
	size_t	count;
	size_t	tmax;
	char	*str;

	tmax = (size_t) -1;
	if (size != 0 && nbitems > (tmax / size))
		return (NULL);
	count = nbitems * size;
	str = malloc(nbitems * size);
	if (str == NULL)
		return (NULL);
	else
	{
		while (count)
		{
			str[count - 1] = '\0';
			count--;
		}
	}
	return (str);
}

// int main(void)
// {
//     char *test;
//     char *ft;
//     size_t i = 0;
//     size_t items = 10;
//     size_t size = 1;
//     size_t count = items * size; 
//     test = calloc(items,size);
//     ft = ft_calloc(items,size);
//     while (count)
//     {
//         printf("|%ld|\t", items);
//         printf("|%c|\t", test[i]);
//         printf("|%c|\n", ft[i]);
//         items--;
//         i++;
//         count--;
//     }
//     free(test);
//     free(ft);
// }/* ************************************************************************** */
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_calcul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:56:24 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:19:33 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_color(int nbr, t_map *m)
{
	int	tmp;

	tmp = nbr / 1048576;
	nbr = nbr - 1048576 * tmp;
	m->img.r = tmp * 16;
	tmp = nbr / 65536;
	nbr = nbr - 65536 * tmp;
	m->img.r += tmp;
	tmp = nbr / 4096;
	nbr = nbr - 4096 * tmp;
	m->img.g = tmp * 16;
	tmp = nbr / 256;
	nbr = nbr - 256 * tmp;
	m->img.g += tmp;
	tmp = nbr / 16;
	nbr = nbr - 16 * tmp;
	m->img.b = tmp * 16;
	m->img.b += nbr;
}

void	ft_draw(t_map *m, float x, float y, int color)
{
	unsigned long	pixel;

	x = roundf(x);
	y = roundf(y);
	ft_color(color, m);
	pixel = (y * m->img.size) + (x * 4);
	if ((m->img.size) * m->winy < pixel - 5 || x <= 0 || y <= 0
		|| y > m->y * m->winy || x > m->winx)
		return ;
	if (m->img.e == 1)
	{
		m->img.data[pixel + 0] = 0;
		m->img.data[pixel + 1] = m->img.r;
		m->img.data[pixel + 2] = m->img.g;
		m->img.data[pixel + 3] = m->img.b;
	}
	else if (m->img.e == 0)
	{
		m->img.data[pixel + 0] = m->img.b;
		m->img.data[pixel + 1] = m->img.g;
		m->img.data[pixel + 2] = m->img.r;
		m->img.data[pixel + 3] = 0;
	}
}

void	ft_tab_deg(t_map *m, int start, int end)
{
	int		i;
	float	pc;
	float	diff;
	int		color;
	t_map	c;

	ft_color(m->color[start], m);
	ft_color(m->color[end], &c);
	diff = end - start - 1;
	i = 0 ;
	while (i <= diff)
	{
		pc = ((i) / diff);
		color = roundf((m->img.r * (1 - pc)) + (c.img.r * pc)) * 65536;
		color += roundf((m->img.g * (1 - pc)) + (c.img.g * pc)) * 256;
		color += roundf((m->img.b * (1 - pc)) + (c.img.b * pc));
		m->color[start + i] = color;
		i++;
	}
}

void	ft_tab_color(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 101)
	{
		if (m->color[i] != 0)
		{
			j = i;
			i++;
			while (i <= 99 && m->color[i] == 0)
				i++;
			if (99 < i)
				return ;
			ft_tab_deg(m, j, i);
		}
		else
			i++;
	}
}

void	ft_init_color(t_map *m)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		m->color[i] = 0;
		i++;
	}
	if (m->setupcolor > 6)
		m->setupcolor = 0;
	ft_setup_color_pt1(m);
	ft_tab_color(m);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:51:00 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 15:56:04 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setup_color_pt3(t_map *m)
{
	if (m->setupcolor == 5)
	{
		m->color[0] = 0xff0000;
		m->color[15] = 0xffa500;
		m->color[30] = 0xffff00;
		m->color[45] = 0x00f000;
		m->color[60] = 0x0060ff;
		m->color[75] = 0x8b00f2;
		m->color[99] = 0xee82ee;
	}
	else if (m->setupcolor == 6)
	{
	m->color[0] = 0x000001;
	m->color[10] = 0x004C75;
	m->color[59] = 0x0094E3;
	m->color[61] = 0xe0cda9;
	m->color[63] = 0x72CC00;
	m->color[70] = 0x298000;
	m->color[78] = 0x4f3000;
	m->color[80] = 0xffffff;
	m->color[99] = 0xffffff;
	}
}

void	ft_setup_color_pt2(t_map *m)
{
	if (m->setupcolor == 4)
	{
		m->color[0] = 0x333333;
		m->color[99] = 0xffffff;
	}
	else
		ft_setup_color_pt3(m);
}

void	ft_setup_color_pt1(t_map *m)
{
	if (m->setupcolor == 0)
	{
		m->color[0] = 0x0000ff;
		m->color[99] = 0xff0000;
	}
	else if (m->setupcolor == 1)
	{
		m->color[0] = 0xff00ff;
		m->color[99] = 0x0070ff;
	}
	else if (m->setupcolor == 2)
	{
		m->color[0] = 0xff0000;
		m->color[99] = 0xffff00;
	}
	else if (m->setupcolor == 3)
	{
		m->color[0] = 0x00ff00;
		m->color[99] = 0xff00ff;
	}
	else
		ft_setup_color_pt2(m);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:21:17 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/10 17:35:05 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int str)
{	
	if (!((47 < str && str < 58)))
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:52:49 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/15 14:43:41 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nbr_to_str(char *str, int n, int signe, int size)
{
	int	i;

	i = 0;
	if (signe == -1)
	{
		str[i++] = '-';
	}
	while (n > 0)
	{
		str[size] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (str);
}

static	char	*ft_itoa_zero(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_min_int(int n)
{
	char	*str;

	if (n == 0)
		return (ft_itoa_zero());
	str = malloc(sizeof(char) * 12);
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		signe;
	int		size;
	int		ndb;

	signe = 1;
	size = 0;
	if (n == -2147483648 || n == 0)
		return (ft_min_int(n));
	if (n < 0)
	{
		signe = -1;
		size = 1;
		n = -n ;
	}
	ndb = n;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	nbr = malloc(sizeof(char) * (size + 1));
	nbr[size] = '\0';
	return (ft_nbr_to_str(nbr, ndb, signe, --size));
}

// int main (void)
// {
// 	printf("%s",ft_itoa(-2147483648));
// }/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:07:05 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/03 18:47:29 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mouse_move(int x, int y, t_map *m)
{
	static int	x1;
	static int	y1;

	if (m->mouse_move == 1)
	{
		ft_clean(m);
		m->mouse_move = 0;
		m->r += (x - x1) / 30;
		m->i += (y - y1) / 30;
		ft_all(m);
	}
	else
	{
		m->mouse_move = 1;
		x1 = x;
		y1 = y;
	}
}

int	ft_zoom(int keycode, int x, int y, t_map *m)
{
	if (keycode != 1)
		ft_clean(m);
	if (keycode == 5)
		m->z -= m->z * 0.2;
	else if (keycode == 4)
		m->z += m->z * 0.2;
	else if (keycode == 1)
	{
		ft_mouse_move(x, y, m);
		return (1);
	}	
	ft_all(m);
	return (1);
}

void	ft_key_pt3(int keycode, t_map *m)
{
	if (keycode == TOUCH_S)
			m->movey = m->movey - 30;
	else if (keycode == TOUCH_D)
			m->movex = m->movex + 30;
	else if (keycode == TOUCH_A)
			m->movex = m->movex - 30;
	else if (keycode == TOUCH_C)
			m->setupcolor += 1;
	else if (keycode == ESC || keycode == -16779872)
	{
		ft_free_map(m, 1);
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		exit(0);
	}
	else if (keycode == TOUCH_M)
			m->verifmonitor *= -1;
}

void	ft_key_pt2(int keycode, t_map *m)
{
	if (keycode == TOUCH_ONE)
	{
		m->r = 0;
		m->i = 0;
	}
	else if (keycode == TOUCH_TOW)
	{
		m->i = 90;
		m->r = 0;
	}
	else if (keycode == TOUCH_THREE)
	{
		m->r = 45;
		m->i = 20;
	}
	else if (keycode == TOUCH_FOUR)
	{
		m->r = -45;
		m->i = 20;
	}
	else if (keycode == TOUCH_SIX)
		ft_annimation(m);
	else if (keycode == TOUCH_W)
			m->movey = m->movey + 30;
}

int	ft_key(int keycode, t_map *m)
{
	if (keycode == TOUCH_UPARROW)
			m->i = m->i + 5;
	else if (keycode == TOUCH_DOWNARROW)
			m->i = m->i - 5;
	else if (keycode == TOUCH_LEFTARROW)
			m->r = m->r - 5;
	else if (keycode == TOUCH_RIGHTARROW)
			m->r = m->r + 5;
	else if (keycode == TOUCH_PLUS)
	{
		m->hauteur = m->hauteur + m->hauteur * 0.3;
		m->minh = 0;
		m->maxh = 0;
	}
	else if (keycode == TOUCH_MOINS)
	{
		m->minh = 0;
		m->maxh = 0;
		m->hauteur = m->hauteur - m->hauteur * 0.3;
	}
	ft_key_pt2(keycode, m);
	ft_key_pt3(keycode, m);
	ft_clean(m);
	ft_all(m);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 17:34:25 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "fdf.h"

void	ft_line_direction_pt1(float dx, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i++ < dx)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dx, i, m));
		m->line.ay = m->line.ay + unity;
		m->line.ax++;
	}
}

void	ft_line_direction_pt2(float dy, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i < dy)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dy, i, m));
		m->line.ay++;
		m->line.ax = m->line.ax + (1 / unity);
		i++;
	}
}

void	ft_line_direction_pt3(float dy, float unity, float tmp, t_map *m)
{
	int	i;

	i = 0;
	if (m->line.reverse == 1)
	{			
		tmp = m->line.hcolor1;
		m->line.hcolor1 = m->line.hcolor2;
		m->line.hcolor2 = tmp;
	}
	while (i > dy)
	{
		ft_draw(m, m->line.ax, m->line.ay, ft_color_line(dy, i, m));
		m->line.ay--;
		m->line.ax = m->line.ax - (1 / unity);
		i--;
	}
}

void	ft_reverse_direction(float tmp, t_map *m)
{
		tmp = m->line.bx;
		m->line.bx = m->line.ax;
		m->line.ax = tmp;
		tmp = m->line.by;
		m->line.by = m->line.ay;
		m->line.ay = tmp;
		m->line.reverse = 1;
}

void	ft_ligne(t_map *m)
{
	float	dx;
	float	dy;
	float	unity;
	float	i;
	float	tmp;

	if ((m->line.ax < 0 || m->line.ay < 0 || m->line.ax > m->winx
			|| m->line.ay > m->winy) && (m->line.bx < 0 || m->line.by < 0
			|| m->line.bx > m->winx || m->line.by > m->winy))
		return ;
	m->line.reverse = 0;
	if (m->line.bx < m->line.ax)
		ft_reverse_direction(tmp, m);
	dx = (float)m->line.bx - (float)m->line.ax;
	dy = (float)m->line.by - (float)m->line.ay;
	unity = dy / dx;
	i = 0;
	if (dy == 0 || (0 < unity && unity < 1) || (-1 <= unity && unity < 0))
		ft_line_direction_pt1(dx, unity, tmp, m);
	else if (1 <= unity)
		ft_line_direction_pt2(dy, unity, tmp, m);
	else
		ft_line_direction_pt3(dy, unity, tmp, m);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:34:31 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 17:36:15 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	if (nbpix < 0)
			nbpix *= -1;
	if (pospix < 0)
			pospix *= -1;
	tmp = 100 * (m->line.hcolor2 - m->minh) / deltah;
	tmp -= 100 * (m->line.hcolor1 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->line.hcolor1 - m->minh) / deltah) + tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m)
{
	float	tmp;

	tmp = 100 * (m->line.hcolor1 - m->minh) / deltah;
	tmp -= 100 * (m->line.hcolor2 - m->minh) / deltah;
	tmp /= nbpix;
	if (0 > (int)((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[0]);
	if (99 < (int)((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix))
		return (m->color[99]);
	tmp = ((100 * (m->line.hcolor1 - m->minh) / deltah) - tmp * pospix);
	return (m->color[(int)tmp]);
}

int	ft_color_line(float nbpix, float pospix, t_map *m)
{
	float	tmp;
	float	deltah;

	deltah = (float)m->maxh - (float)m->minh;
	if (m->line.hcolor1 < m->line.hcolor2)
		return (ft_color_line_up(nbpix, pospix, deltah, m));
	else if (m->line.hcolor1 > m->line.hcolor2)
		return (ft_color_line_down(nbpix, pospix, deltah, m));
	else
	{
		tmp = (100 * (m->line.hcolor2 - m->minh) / deltah);
		if (tmp == 100)
			tmp -= 1;
		return (m->color[(int)tmp]);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:01:20 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:18:51 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	m->m = malloc(sizeof(t_pixel *) * (m->y));
	while (y < m->y)
	{
		m->m[y] = ft_calloc(sizeof(t_pixel), (m->x));
		while (x < m->x)
		{
			m->m[y][x].y = y * m->z;
			m->m[y][x].x = x * m->z;
			m->m[y][x].z = m->initm[y][x].z ;
			x++;
		}
		y++;
		x = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:57:28 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 18:59:11 by ngriveau         ###   ########.fr       */
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
		if (ft_isdigit(ligne[i]))
		{
			x++;
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
		if (ft_isdigit(ligne[i]) || ligne[i] == '-')
		{
			m->initm[y][x].y = y * m->z;
			m->initm[y][x].x = x * m->z;
			m->initm[y][x].z = ft_atoi(ligne + i);
			x++;
			while (ft_isdigit(ligne[i]) || ligne[i] == '-')
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

void	ft_copy_map(t_map *map)
{
	int	fd;

	fd = open(MAP, O_RDONLY);
	map->y = ft_y_map(fd, &map->x);
	map->initm = malloc(sizeof(t_pixel *) * (map->y));
	fd = open(MAP, O_RDONLY);
	ft_fill_map(map, fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:02:49 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:20:29 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hauteur(t_map *m)
{
	float	tmpy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].h = m->m[y][x].z ;
			if (m->m[y][x].h < m->minh)
			{
				m->minh = m->m[y][x].h;
			}
			if (m->maxh < m->m[y][x].h)
				m->maxh = m->m[y][x].h;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_rota(t_map *m)
{
	float	tmpx;
	int		x;
	int		y;

	x = 0;
	y = 0;
	m->varcos = cos(m->r / 57.2958);
	m->varsin = sin(m->r / 57.2958);
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

void	ft_incl(t_map *m)
{
	int		x;
	int		y;
	float	varcos;
	float	varsin;

	x = 0;
	y = 0;
	varcos = cos(m->i / 57.2958);
	varsin = sin(m->i / 57.2958);
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].y = m->m[y][x].y * varsin;
			m->m[y][x].y += (m->m[y][x].z * m->hauteur) * m->z * -varcos;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_centre(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = m->m[y][x].x - m->x * m->z / 2;
			m->m[y][x].y = m->m[y][x].y - m->y * m->z / 2;
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_move(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			m->m[y][x].x = (m->m[y][x].x + m->winx / 2) + m->movex;
			m->m[y][x].y = (m->m[y][x].y + m->winy / 2) + m->movey;
			x++;
		}
		y++;
		x = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:09:00 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:19:40 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map_x(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y][x + 1].x;
	m->line.by = m->m[y][x + 1].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y][x + 1].h;
	ft_ligne(m);
}

void	ft_print_map_y(int x, int y, t_map *m)
{
	m->line.ax = m->m[y][x].x;
	m->line.ay = m->m[y][x].y;
	m->line.bx = m->m[y + 1][x].x;
	m->line.by = m->m[y + 1][x].y;
	m->line.hcolor1 = m->m[y][x].h;
	m->line.hcolor2 = m->m[y + 1][x].h;
	ft_ligne(m);
}

void	ft_print_map(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < m->y)
	{
		while (x < m->x)
		{
			if (x < m->x - 1)
				ft_print_map_x(x, y, m);
			if (y < m->y -1)
				ft_print_map_y(x, y, m);
			x++;
		}
		y++;
		x = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:13:18 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 16:22:34 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/X.h>

void	ft_monitoring_invalid_map(t_map *m)
{
	int		c;
	char	*t;

	t = MSG_INVALID_MAP;
	c = 0xffffff;
	mlx_string_put(m->mlx, m->mlx_win, m->winx / 2 - 100, m->winy / 2, c, t);
}

void	ft_monitoring_display_info_pt2(t_map *m, char *value)
{
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 6, 0xffffff, "I: ");
	value = ft_itoa((int)m->i);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 6, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 7, 0xffffff, "Z: ");
	value = ft_itoa((int)m->z);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 7, 0xffffff, value);
	free(value);
}

void	ft_monitoring_display_info_pt1(t_map *m)
{
	char	*value;

	mlx_string_put(m->mlx, m->mlx_win, 5, 13, 0xffffff, "x: ");
	value = ft_itoa((int)m->x);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 2, 0xffffff, "z: ");
	value = ft_itoa((int)m->y);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 2, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 3, 0xffffff, "h: ");
	value = ft_itoa((int)m->minh);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 3, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 4, 0xffffff, "H: ");
	value = ft_itoa((int)m->maxh);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 4, 0xffffff, value);
	free(value);
	mlx_string_put(m->mlx, m->mlx_win, 5, 13 * 5, 0xffffff, "R:");
	value = ft_itoa((int)m->r);
	mlx_string_put(m->mlx, m->mlx_win, 20, 13 * 5, 0xffffff, value);
	free(value);
	ft_monitoring_display_info_pt2(m, value);
}

void	ft_monitoring_fade_color(t_map *m)
{
	int	c;
	int	y;
	int	x;

	c = 99;
	y = m->winy -100;
	while (y <= m->winy)
	{
		x = m->winx -7;
		while (x <= m->winx)
		{
			mlx_pixel_put(m->mlx, m->mlx_win, x, y, m->color[c]);
			x++;
		}
		c--;
		y++;
	}
}

void	ft_monitoring(t_map *m)
{
	int		i;
	int		j;
	int		c;

	if (m->verifmonitor != 1)
		return ;
	i = 0;
	j = 0;
	if (m->y == 0 && m->x == 0)
		ft_monitoring_invalid_map(m);
	else
	{
		while (i < 95)
		{
			while (j < 50)
			{
				mlx_pixel_put(m->mlx, m->mlx_win, j, i, 0x202020);
				j++;
			}
			j = 0;
			i++;
		}
		ft_monitoring_fade_color(m);
		ft_monitoring_display_info_pt1(m);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:59 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/03 12:26:47 by ngriveau         ###   ########.fr       */
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
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->img.i, 0, 0);
	ft_monitoring(m);
}

void	ft_intivalue(t_map *m)
{
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
	m->setupcolor = 0;
	m->verifmonitor = 1;
	ft_copy_map(m);
	m->z = m->winx / sqrt(pow(m->x * m->z, 2) + pow(m->y * m->z, 2));
	m->hauteur = m->z / 1000;
	m->minh = 0;
	m->maxh = 0;
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

int	main(void)
{
	int		color;
	t_map	m;

	ft_intivalue(&m);
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
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/08 16:28:51 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_s(char *str, int verif)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n' && verif == 1)
		i++;
	return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int size)
{
	int		i;
	int		j;
	char	*upligne;

	i = 0;
	j = 0;
	if (buffer[i] == '\0')
		return (ligne);
	while (buffer[i] == -42)
		i++;
	upligne = malloc(sizeof(char) * (ft_s(ligne, 1) + ft_s(&buffer[i], 1) + 2));
	if (upligne == NULL)
		return (NULL);
	upligne[ft_s(ligne, 1) + ft_s(&buffer[i], 1)] = '\0';
	size = ft_s(ligne, 1);
	while (--size + 1)
	{
		upligne[j] = ligne[j];
		j++;
	}
	upligne = ft_dup_upligne(upligne, buffer, i, j);
	free(ligne);
	return (upligne);
}

char	*ft_new_line(char *buffer, int size, int fd)
{	
	char	*ligne;

	ligne = malloc(sizeof(char));
	if (ligne == NULL)
		return (NULL);
	ligne[0] = '\0';
	while (size != 0)
	{
		ligne = ft_my_malloc(buffer, ligne, size);
		if (ligne == NULL)
			return (free(ligne), NULL);
		if (ligne[ft_s(ligne, 0)] == '\n')
			return (ligne);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (ligne[0] == '\0')
	{
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

char	*get_next_line(int fd)
{
	int			size;
	static char	buffer[BUFFER_SIZE + 1] = {0};

	size = -5;
	buffer[BUFFER_SIZE] = '\0';
	if (buffer[0] == '\0')
		size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
		return (NULL);
	return (ft_new_line(buffer, size, fd));
}

// int main (void)
// {
// 	int i = 1;
// 	char *test;
// 	int fd = open("worldmap.fdf", O_RDONLY);
// 	printf("fd = %d",fd);
// 	while (test = get_next_line(fd))
// 	{
// 		free(test);
// 		test = get_next_line(fd);
// 	}
// }/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:14 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/29 10:29:22 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_dup_upligne(char *upligne, char *buffer, int i, int j)
{
	int	size;

	size = ft_s(&buffer[i], 1);
	while (--size + 1)
	{
		upligne[j] = buffer[i];
		buffer[i] = -42;
		i++;
		j++;
	}
	i = 0;
	while (upligne[i] != '\0')
	{
		if (upligne[i] == -42)
			upligne[i] = '\0';
		i++;
	}
	return (upligne);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:44:51 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/03 18:44:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <time.h>
# include <X11/X.h>

# define MAP "./test_maps/42.fdf"
# define MSG_INVALID_MAP "Error invalid map"
# define MSG_INVALID_OS "Error invalid OS"
# define OS 3
# define WIDTH 1500
# define HEIGHT 800

// #   define MAP "./moremaps/hardests/hardest01.fdf"
# define TOUCH_LEFTARROW 65361
# define TOUCH_RIGHTARROW 65363
# define TOUCH_UPARROW 65362
# define TOUCH_DOWNARROW 65364
# define TOUCH_MOINS 45
# define TOUCH_PLUS 61
# define TOUCH_ONE 49
# define TOUCH_TOW 50
# define TOUCH_THREE 51
# define TOUCH_FOUR 52
# define TOUCH_FIVE 53
# define TOUCH_SIX 54
# define TOUCH_W 119
# define TOUCH_A 100
# define TOUCH_S 115
# define TOUCH_D 97
# define ESC 65307
# define TOUCH_C 99
# define TOUCH_M 109 //

// #  define TOUCH_LEFTARROW 123
// #  define TOUCH_RIGHTARROW 124
// #  define TOUCH_UPARROW 126
// #  define TOUCH_DOWNARROW 125
// #  define TOUCH_MOINS 27
// #  define TOUCH_PLUS 24
// #  define TOUCH_ONE 18
// #  define TOUCH_TOW 19
// #  define TOUCH_THREE 20
// #  define TOUCH_W 13
// #  define TOUCH_A 0
// #  define TOUCH_S 1
// #  define TOUCH_D 2

typedef struct s_pixel
{
	float	x;
	float	y;
	float	z;
	float	h;

}	t_pixel;

typedef struct s_img
{
	void	*i;
	int		size;
	int		p;
	int		e;
	char	*data;
	int		r;
	int		b;
	int		g;
}	t_img;

typedef struct s_line
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	hcolor1;
	float	hcolor2;
	int		reverse;
}	t_line;

typedef struct s_map
{
	t_pixel			**initm;
	t_pixel			**m;
	t_line			line;
	int				x;
	int				y;
	float			minh;
	float			maxh;

	float			z;
	float			r;
	float			i;
	int				movex;
	int				movey;

	float			hauteur;

	unsigned long	color[101];
	int				setupcolor;

	void			*mlx;
	void			*mlx_win;
	int				winx;
	int				winy;
	t_img			img;

	int				mouse_move;
	float			varcos;
	float			varsin;
	int				verifmonitor;
}	t_map;

//		COLOR_MAP
void	ft_setup_color_pt1(t_map *m);
void	ft_setup_color_pt2(t_map *m);
void	ft_setup_color_pt3(t_map *m);

//		COLOR CALCUL
void	ft_color(int nbr, t_map *m);
void	ft_draw(t_map *m, float x, float y, int color);
void	ft_tab_deg(t_map *m, int start, int end);
void	ft_tab_color(t_map *m);
void	ft_init_color(t_map *m);

//		MONITORING
void	ft_monitoring_invalid_map(t_map *m);
void	ft_monitoring_display_info_pt1(t_map *m);
void	ft_monitoring_display_info_pt2(t_map *m, char *value);
void	ft_monitoring_fade_color(t_map *m);
void	ft_monitoring(t_map *m);

//		LINE
void	ft_line_direction_pt1(float dx, float unity, float tmp, t_map *m);
void	ft_line_direction_pt2(float dy, float unity, float tmp, t_map *m);
void	ft_line_direction_pt3(float dy, float unity, float tmp, t_map *m);
void	ft_reverse_direction(float tmp, t_map *m);
void	ft_ligne(t_map *m);

//		LINE COLOR
int		ft_color_line(float nbpix, float pospix, t_map *m);
int		ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m);
int		ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m);

//		MAP
int		ft_x_map(char *ligne, int xmax);
int		ft_y_map(int fd, int *xmax);
void	ft_fill_map(t_map *m, int fd);
int		ft_fill_map_pt2(t_map *m, char *ligne, int y);
void	ft_copy_map(t_map *map);
void	ft_map(t_map *m);

//		MAP CALCUL
void	ft_hauteur(t_map *m);
void	ft_rota(t_map *m);
void	ft_incl(t_map *m);
void	ft_centre(t_map *m);
void	ft_move(t_map *m);

//		KEY MOUSE
void	ft_mouse_move(int x, int y, t_map *m);
int		ft_zoom(int keycode, int x, int y, t_map *m);
int		ft_key(int keycode, t_map *m);
void	ft_key_pt2(int keycode, t_map *m);
void	ft_key_pt3(int keycode, t_map *m);

//		PRINT MAP
void	ft_print_map(t_map *m);
void	ft_print_map_y(int x, int y, t_map *m);
void	ft_print_map_x(int x, int y, t_map *m);

//		CLEAN
void	ft_free_map(t_map *m, int exit);
void	ft_clean(t_map *m);

// ANIMATION
void	ft_annimation(t_map *m);
void	ft_annimationpt2(t_map *m);

//		START
void	ft_all(t_map *m);
void	ft_intivalue(t_map *m);
int		main(void);
int		ft_cross_close(t_map *m);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:33:19 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/11 12:18:07 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include<stdio.h>
# include<fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_s(char *str, int verif);
char	*ft_my_malloc(char *buffer, char *ligne, int size);
char	*ft_new_line(char *buffer, int size, int fd);
char	*get_next_line(int fd);
char	*ft_dup_upligne(char *upligne, char *buffer, int i, int j);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:32:42 by ngriveau          #+#    #+#             */
/*   Updated: 2022/12/12 15:42:45 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fcntl.h>
//# include <bsd/string.h>
# include "get_next_line.h"
# include <math.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
int		ft_isalnum(int str);
int		ft_isalpha(int str);
int		ft_isascii(int str);
int		ft_isdigit(int str);
int		ft_isprint(int str);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strchr(char *str, int lettre);
char	*ft_strdup(char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *str, int lettre);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int character);
int		ft_toupper( int character );
char	*ft_strnstr(const char *src, const char *cmp, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
