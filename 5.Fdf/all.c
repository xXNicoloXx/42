/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:13 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/02 19:26:54 by ngriveau         ###   ########.fr       */
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
		suite(m);
	}
	i = -1;
	while (++i < 360 / 3)
	{
		m->i -= 0.65;
		m->r += 3;
		ft_clean(m);
		suite(m);
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
	suite(m);
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
/*   Updated: 2023/01/02 19:18:26 by ngriveau         ###   ########.fr       */
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
		suite(m);
	}
	else
	{
		m->mouse_move = 1;
		x1 = x;
		y1 = y;
	}
}

void	ft_zoom(int keycode, int x, int y, t_map *m)
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
		return ;
	}	
	suite(m);
}

void	ft_key_pt3(int keycode, t_map *m)
{
	if (keycode == Touch_S)
			m->movey = m->movey - 30;
	else if (keycode == Touch_D)
			m->movex = m->movex + 30;
	else if (keycode == Touch_A)
			m->movex = m->movex - 30;
	else if (keycode == Touch_C)
			m->setupcolor += 1;
	else if (keycode == ESC)
	{
		ft_free_map(m, 1);
		mlx_destroy_image(m->mlx, m->img.i);
		mlx_destroy_window(m->mlx, m->mlx_win);
		mlx_destroy_display(m->mlx);
		free(m->mlx);
		exit(0);
	}
	else if (keycode == Touch_M)
			m->verifmonitor *= -1;
}

void	ft_key_pt2(int keycode, t_map *m)
{
	if (keycode == Touch_One)
	{
		m->r = 0;
		m->i = 0;
	}
	else if (keycode == Touch_Tow)
	{
		m->i = 90;
		m->r = 0;
	}
	else if (keycode == Touch_Three)
	{
		m->r = 45;
		m->i = 20;
	}
	else if (keycode == Touch_Four)
	{
		m->r = -45;
		m->i = 20;
	}
	else if (keycode == Touch_Six)
		ft_annimation(m);
	else if (keycode == Touch_W)
			m->movey = m->movey + 30;
}

void	ft_key(int keycode, t_map *m)
{
	if (keycode == Touch_UpArrow)
			m->i = m->i + 5;
	else if (keycode == Touch_DownArrow)
			m->i = m->i - 5;
	else if (keycode == Touch_LeftArrow)
			m->r = m->r - 5;
	else if (keycode == Touch_RightArrow)
			m->r = m->r + 5;
	else if (keycode == Touch_Plus)
	{
		m->hauteur = m->hauteur + m->hauteur * 0.3;
		m->minh = 0;
		m->maxh = 0;
	}
	else if (keycode == Touch_Moins)
	{
		m->minh = 0;
		m->maxh = 0;
		m->hauteur = m->hauteur - m->hauteur * 0.3;
	}
	ft_key_pt2(keycode, m);
	ft_key_pt3(keycode, m);
	ft_clean(m);
	suite(m);
	return ;
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
/*   Updated: 2023/01/02 19:22:31 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/X.h>

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
	suite(&m);
	mlx_hook(m.mlx_win, 2, 1L<<0, ft_key, &m);
	mlx_mouse_hook(m.mlx_win, ft_zoom, &m);
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
