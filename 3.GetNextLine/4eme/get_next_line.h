/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:32:42 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 18:51:49 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdio.h>
# include<fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_len_malloc(char *buffer);
char	*ft_my_malloc(char *buffer, char *ligne);
char	*ft_free_all(char *buffer, char *ligne, int info);
char	*ft_new_line(int i, int fd, char *buffer, char *ligne);
#endif
