/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:48 by nicolasgriv       #+#    #+#             */
/*   Updated: 2022/11/21 15:14:17 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include  <limits.h> 

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
	if (str == NULL)
		return (ft_writestr("(null)", nbrch));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		nbrch++;
	}
	return (nbrch);
}

int	ft_verif_pc(char str)
{
	int	i;

	i = 0;
	if (str == '%')
	{
		if ((str + 1) == 'c' || (str + 1) == 's' || (str + 1) == 'p'
			|| (str + 1) == 'd' || (str + 1) == 'i' || (str + 1) == 'u'
			|| (str + 1) == 'x' || (str + 1) == 'X')
			return (1);
		else
			return (0);
	}
	else 
		return (1);
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
	if (str[1] == '%')
		nbrch = ft_writechar('%', nbrch);

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
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else if (ft_verif_pc(str[i]) == 1)
			nbrch = ft_writechar(str[i], nbrch);
		else if (str[i] == '%')
			nbrch = ft_print_pourcent(&str[i++], nbrch, &list);
		else
			nbrch = ft_writechar(str[i], nbrch);
	}
	va_end(list);
	return (nbrch);
}





int	main(void)
{
	int		original;
	int		mine;
	char	*str;

	str = "Just some text..";

	printf("\n\n--- ALL ---\n");
	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- SAME WITH %%%%%% AT THE END ---\n");
	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	printf("%d  | %d\n", original, mine);

	printf("\n\n--- SAME WITH %%%%%% AT THE END AND SOME TEXT ---\n");
	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%| texte", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%| texte", str[0], str, str, 42, 42, 42, 42, 42);
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- EMPTY STRING ---\n");
	original = printf("");
	mine = ft_printf("");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- WITH ft_printf(0) ---\n");
	original = printf(0);
	mine = ft_printf(0);
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- WITH STR AS ONLY ARGUMENT ---\n");
	original = printf(str);
	printf("\n");
	mine = ft_printf(str);
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- WITH NULL AS STRING AND ADRESS ---\n");
	original = printf("-> %s | %p", NULL, NULL);
	printf("\n");
	mine = ft_printf("-> %s | %p", NULL, NULL);
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- WITH TAB AND ANTICIPATED END OF STRING ---\n");
	original = printf("-> \t|\0\0gloubiboulgah");
	printf("\n");
	mine = ft_printf("-> \t|\0\0gloubiboulgah");
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- WITH NEGATIVE VALUES ---\n");
	original = printf("%u | %x | %X | %d | %i | %c | %p", -42, -42, -42, -42, -42, -42, (void *) -42);
	printf("\n");
	mine = ft_printf("%u | %x | %X | %d | %i | %c | %p", -42, -42, -42, -42, -42, -42, (void *) -42);
	printf("\n");
	printf("%d  : %d\n", original, mine);

	printf("\n\n--- PRINT ADRESS WITH %%x and %%X ---\n");
	original = printf("%x | %X | %x | %X", NULL, NULL, &str, &str);
	printf("\n");
	mine = ft_printf("%x | %X | %x | %X", NULL, NULL, &str, &str);
	printf("\n");
	printf("%d  : %d\n", original, mine);
}