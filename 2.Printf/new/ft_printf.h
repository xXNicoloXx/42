/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:40:30 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/21 12:15:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:32:42 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/11 11:22:09 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
# include <stdarg.h>

int		ft_writechar(char ch, int nbrch);
int		ft_writestr(char *str, int nbrch);
int     ft_print_pourcent(const char *str, int nbrch, va_list *list);
int		ft_printf(const char *str, ...);

int		ft_pc_id(int nbr, int nbrch);
void	ft_putnbr_pc_id(int nb);
void	ft_putchar_pc_idu(char c);

int		ft_pc_p(unsigned long nbr, int nbrch);
int		ft_print_pc_p_base(unsigned long nbr, int nbrch);

int		ft_pc_u(unsigned int nbr, int nbrch);
void	ft_putnbr_pc_u(unsigned int nb);

int		ft_pc_x(long nbr, char *base, int nbrch);
int		ft_len_nbr_pc_x(unsigned long nbr, int nbrch);
void	ft_print_base_pc_x(unsigned long nbr, char *base);
#endif