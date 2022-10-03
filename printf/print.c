#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


int printf( const char * restrict format, ... );
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putnbr_base(int nbr, char *base);
void ft_pourcentP(char *str);


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

int ft_affarg(const char *str,char lettre, int i_arg, va_list list)
{
    int printint;
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


}


int    ft_printf(const char *str,  ...)
{
    int i;
    int nbr_arg;
    int i_arg;

    i = 0;
    i_arg = 0;
    nbr_arg = ft_nbr_arg(str);
    
    va_list list;
    va_start(list, str);

    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if ((str[i] == 'c') || (str[i] == 's') || (str[i] == 'p') || (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u') || (str[i] == 'x') || (str[i] == 'X'))
            {
                
                ft_affarg(str, str[i], i_arg, list);
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
    
    

    printf("\n%s\n",str);
    printf("nbr arg = %d\n",nbr_arg);
    
    return (0);



}




int main (void)
{
    char *poucentp = "test";

    ft_printf("\tBonjour %c %d %s %p les amis", 108, 109, "|", poucentp);
    printf("\tBonjour %c %d %s %p les amis", 108, 109, "|", poucentp);
    
    printf("\n");
}




void ft_pourcentP(char *str)
{
    char * base;
    unsigned long test;

    base = "0123456789abcdef";
    test = (unsigned long) str;
    test = 827456;
    ft_putnbr_base(test, base);
    //printf("%ld", test);

}