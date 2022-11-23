/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:14 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 18:51:28 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_all(char *buffer, char *ligne, int info)
{
    if (info == 1)
        free(buffer);
    else if (info = 2)
        free(ligne);
    else
    {
        free(buffer);
        free(ligne);
    }
    return(NULL);
}