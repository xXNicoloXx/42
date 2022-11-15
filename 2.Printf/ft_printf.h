#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int printf( const char * restrict format, ... );
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_print_pourcentP(unsigned long nbr);
void ft_putnbr_base(unsigned long nbr, char *base);
void    ft_pourcentP(char *str);
void	ft_pourcentu(unsigned long nb);
int ft_nbr_arg(const char *str);
void    ft_affarg(char lettre, int i_arg, va_list list);
int     ft_printf(const char *str,  ...);


#endif