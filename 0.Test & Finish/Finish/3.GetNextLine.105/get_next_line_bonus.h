/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:33:19 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/29 10:41:32 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
