/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:48 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/18 20:18:32 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_writechar(char ch, int nbrch)
{
	write(1,&ch,1);
	nbrch++;
	return (nbrch);
}

int ft_writestr(char *str, int nbrch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1,&str[i],1);
		i++;
		nbrch++;
	}
	return (nbrch);
}


int ft_print_pourcent(const char *str, int nbrch, va_list list, int mot)
{
	while (mot-- )
		va_arg(list, int);
	if (str[1] == 'c')
		nbrch = ft_writechar(va_arg(list, int), nbrch);
	if (str[1] == 's')
		nbrch = ft_writestr(va_arg(list, char *), nbrch);
	if (str[1] == 'p')
		nbrch = ft_pourcentP(va_arg(list, unsigned long), nbrch);
	if (str[1] == 'd')
		nbrch = ft_pourcent_i(va_arg(list, int), nbrch);

	if (str[1] == 'i')

	if (str[1] == 'u')

	if (str[1] == 'x')

	if (str[1] == 'X')
	printf("\tnbr = %d\n",nbrch);
	return (nbrch);
}

int	ft_printf(const char *str, ...)
{
	int i;
	int nbrch;
	int mot;
	va_list list;

	i = - 1;
	nbrch = 0;
	mot = -1;
	va_start(list, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i+1] == '%')
			nbrch = ft_writechar(str[i++], nbrch);
		else if (str[i] == '%')
			nbrch = ft_print_pourcent(&str[i++], nbrch, list, ++mot);
		else
			nbrch = ft_writechar(str[i], nbrch);
	}
	return (nbrch);
}

int main (void)
{
	int oui  = 0;
	char *test = "NUL";

	oui = ft_printf("%p   %d %% ", test, 3939);
	printf("\nNombre de write |%d|\n",oui);
	
	oui = printf("%p   %d %% %X", test, 3939, 894);
	printf("\nNombre de write |%d|\n",oui);


	
	
}

//pointeur de i pour avoir le meme i pour toute les fonction
//pointeur de mot pour avoir le meme nombre pour toute les fonction
//je fais une verif avec ft_verif_pourcent, chaque pourcent est un numero pour
//pourvoir le revoyer direct sans rescan
//ft write pour prendre aquune ligne a chaque wrote 

