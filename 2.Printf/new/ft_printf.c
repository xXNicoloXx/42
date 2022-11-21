/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:48 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/21 12:14:46 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writechar(char ch, int nbrch)
{
	write(1, &ch, 1);
	nbrch++;
	return (nbrch);
}

int	ft_writestr(char *str, int nbrch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		nbrch++;
	}
	return (nbrch);
}

int	ft_print_pourcent(const char *str, int nbrch, va_list *list)
{
	if (str[1] == 'c')
		nbrch = ft_writechar(va_arg(*list, int), nbrch);
	if (str[1] == 's')
		nbrch = ft_writestr(va_arg(*list, char *), nbrch);
	if (str[1] == 'p')
		nbrch = ft_pc_p(va_arg(*list, unsigned long), nbrch);
	if (str[1] == 'd')
		nbrch = ft_pc_id(va_arg(*list, int), nbrch);
	if (str[1] == 'i')
		nbrch = ft_pc_id(va_arg(*list, int), nbrch);
	if (str[1] == 'u')
		nbrch = ft_pc_u(va_arg(*list, unsigned int), nbrch);
	if (str[1] == 'x')
		nbrch = ft_pc_x(va_arg(*list, long), "0123456789abcdef", nbrch);
	if (str[1] == 'X')
		nbrch = ft_pc_x(va_arg(*list, long), "0123456789ABCDEF", nbrch);
	return (nbrch);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nbrch;
	va_list	list;

	i = -1;
	nbrch = 0;
	va_start(list, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			nbrch = ft_writechar(str[i++], nbrch);
		else if (str[i] == '%')
			nbrch = ft_print_pourcent(&str[i++], nbrch, &list);
		else
			nbrch = ft_writechar(str[i], nbrch);
	}
	va_end(list);
	return (nbrch);
}

// int main (void)
// {
// 	int oui  = 0;
// 	oui = ft_printf(" |%c ||%c |||%c ", '1', '2', '3');
// 	printf("\nNombre de write |%d|\n",oui);	
// 	oui = printf(" %c %c %c ", '1', '2', '3');
// 	printf("\nNombre de write |%d|\n",oui);
// }
//pointeur de i pour avoir le meme i pour toute les fonction
//pointeur de mot pour avoir le meme nombre pour toute les fonction
//je fais une verif avec ft_verif_pourcent, chaque pourcent est un numero pour
//pourvoir le revoyer direct sans rescan
//ft write pour prendre aquune ligne a chaque wrote 
