#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"



int ft_nbr_arg(const char *str)
{
    int i;
    int nbr_arg;

    i = 0;
    nbr_arg = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if ((str[i] == 'c') || (str[i] == 's') || (str[i] == 'p') || (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u') || (str[i] == 'x') || (str[i] == 'X'))
                nbr_arg++;
            if (str[i] == '%')
                i++;
            i--;
        }
        i++; 
    }
    return (nbr_arg);
}

void ft_affarg(char lettre, int i_arg, va_list list)
{
    long printint;
    char *printchar;

    if (lettre == 'c')      // char
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , int);
            i_arg--;
        }
        write(1, &printint, 1);
    }
    if (lettre == 'd')      // int
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , int);
            i_arg--;
        }
        ft_putnbr(printint);
    }
    if (lettre == 's')      // char*
    {
        while (i_arg+1)
        {
            printchar = va_arg(list  , char *);
            i_arg--;
        }
        ft_putstr(printchar);
    }
    if (lettre == 'p')      // %p
    {
        while (i_arg+1)
        {
            printchar = va_arg(list  , char *);
            i_arg--;
        }
        ft_pourcentP(printchar);
    }
    if (lettre == 'x')      // x (min base hexa)
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , long long);
            i_arg--;
        }
        ft_putnbr_base(printint, "0123456789abcdef");
    }
    if (lettre == 'X')      // X (max base hexa)
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , int);
            i_arg--;
        }
        ft_putnbr_base(printint, "0123456789ABCDEF");
    }
    if (lettre == 'i')      // entier en base 10
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , int);
            i_arg--;
        }
        ft_putnbr(printint);
    }
    if (lettre == 'u')      // entier en base 10
    {
        while (i_arg+1)
        {
            printint = va_arg(list  , int);
            i_arg--;
        }
        printint = (unsigned int) printint;
        ft_pourcentu(printint);
    }
}

void ft_pourcentP(char *str)
{
    unsigned long test;

    test = (unsigned long) str;
    write(1, "0", 1); 
    write(1, "x", 1); 
    ft_print_pourcentP(test);
}
void	ft_print_pourcentP(unsigned long nbr)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr < 16)
		write (1, &base[nbr], 1);
	else
	{
		ft_print_pourcentP(nbr / 16);
		ft_print_pourcentP(nbr % 16);
	}
}

int    ft_printf(const char *str,  ...)
{
    int i;
    //int nbr_arg;
    int i_arg;

    i = 0;
    i_arg = 0;
    //nbr_arg = ft_nbr_arg(str);
    
    va_list list;
    va_start(list, str);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if ((str[i] == 'c') || (str[i] == 's') || (str[i] == 'p') || (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u') || (str[i] == 'x') || (str[i] == 'X'))
            {   
                ft_affarg(str[i], i_arg, list);
                i_arg++;
                i++;
            }
            else if (str[i] == '%')
            {
                i++;
                write(1, "%", 1); 
            }
            i--;
        }
        else
            write(1, &str[i], 1);
        i++;
    }
    //printf("nbr arg = %d\n",nbr_arg);
    return (0);
}
int main (void)
{
    char *poucentp = "4";
    int nbr = 15;
    int nbrr = 728764;

    ft_printf("test %%  %d %s %p %x %X %i %u\n",  1, "|", poucentp, nbr, nbr ,nbrr, nbrr);
    printf("test %%  %d %s %p %x %X %i %u\n", 1, "|", poucentp, nbr, nbr , nbrr, nbrr);
}
