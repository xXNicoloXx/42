/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mouse_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:20:20 by ngriveau          #+#    #+#             */
/*   Updated: 2023/01/04 11:51:57 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_init_path_map(t_map  *m)
{
    m->pathmap.map1 = MAP1;
    m->pathmap.map2 = MAP2;
    m->pathmap.map3 = MAP3;
    m->pathmap.map4 = MAP4;
    m->pathmap.MAP5 = MAP5;
    m->pathmap.MAP6 = MAP6;
    m->pathmap.MAP7 = MAP7;
    m->pathmap.MAP8 = MAP8;
    m->pathmap.MAP9 = MAP9;
}

void	ft_key_pt4(int keycode, t_map *m)
{
    if (keycode == TOUCH_M)
    {
        ft_free_map(m, 1);
        
        ft_intivalue(&m);

    }
}

// touche m
// free map
// clear
// chaanger path
// init map 
// suite