/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:00:06 by emis              #+#    #+#             */
/*   Updated: 2022/07/24 22:13:45 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

/* Makes a string representing a number found in the dictionnary*/
char	*make_key(int digit, int zeroes)
{
	char	*key;
	int		z;

	z = 0;
	if (zeroes == -1)
	{
		key = malloc(sizeof(char) * (3));
		key[0] = '1';
		key[1] = digit + '0';
		key[2] = 0;
	}
	else
	{
		key = malloc(sizeof(char) * (zeroes + 2));
		key[0] = digit + '0';
		key[zeroes + 1] = 0;
		if (digit)
			while (++z < zeroes + 1)
				key[z] = '0';
	}
	return (key);
}

/* Finds and returns the index of the next non-nil number,
 or -1 if there is none.*/
int	nxn(char *nbr)
{
	int	i;

	i = -1;
	while (nbr[++i])
		if (nbr[i] != '0')
			return (i);
	return (-1);
}

/* Prints out the value in the dictionnary corresponding to
 the digit in the current position in the string representing the number.
Checks chronologically if the number is nil; if the digit in the
 tens' position is not 1, thus if the printed value is twenty onwards;
else if it is 1, the next iteration is skipped and a number 
 between 10 and 19 is directly printed instead; 
else if the digit is in the hundreds' or units' position AND then
 prints it accordingly. Or not, if no conditions were fulfilled.
The last test checks wether the end of the numer has been
 reached to decide wether to print a space or not.*/
void	ponder_my_orb(char *nbr, int *trio, int *iter, t_dictionary *d)
{
	char	*wrd;

	wrd = NULL;
	if (*iter == 0 && nbr[*iter] == 0 && nxn(nbr) != -1)
	{
		*iter = ft_strlen(nbr) - 1;
		wrd = search_key(make_key(0, 0), d);
	}
	if (nbr[*iter] != '0' && *trio == 2 && nbr[*iter] != '1')
		wrd = search_key(make_key(nbr[*iter] - '0', 1), d);
	else if (nbr[*iter] != '0' && *trio == 2 && nbr[*iter] == '1')
	{
		wrd = search_key(make_key(nbr[*iter + 1] - '0', -1), d);
		*iter += 1;
		*trio = 1;
	}
	else if (nbr[*iter] != '0' && (*trio == 1 || *trio == 0))
		wrd = search_key(make_key(nbr[*iter] - '0', 0), d);
	if (!wrd)
		return ;
	write(1, wrd, ft_strlen(wrd));
	if (*iter != ft_strlen(nbr) - 1)
		write(1, " ", 1);
}

/* Prints the 'hundred' or 'thousand' and so on.*/
int	hundred_percent_sexy(int nb, int *thou, int trio, t_dictionary *d)
{
	char	*wrd;

	if (trio == 0 && nb)
		wrd = search_key(make_key(1, 2), d);
	else if (trio == 1)
	{
		if (nb == -1)
			wrd = search_key(make_key(1, (*thou) * 3), d);
		(*thou)--;
		if (nb != -1)
			return (0);
	}
	else
		return (0);
	if (wrd != NULL)
		write(1, wrd, ft_strlen(wrd));
	return (1);
}

/* Prints the expected number*/
void	printnbr(char *n, t_dictionary *d)
{
	int		trio;
	int		thou;
	int		i;
	int		nzb4;

	trio = ft_strlen(n) % 3;
	thou = (ft_strlen(n) - 1) / 3;
	i = -1;
	while (n[++i])
	{
		ponder_my_orb(n, &trio, &i, d);
		if (trio <= 1 && i != ft_strlen(n) - 1
			&& ft_strlen(&n[i]) > 2)
		{
			nzb4 = n[i] - '0';
			if (trio == 1 && (n[i] != '0' || n[i - 1] != '0'
					|| n[i - 2] != '0'))
				nzb4 = -1;
			if (hundred_percent_sexy(nzb4, &thou, trio, d) && ((trio == 0
						&& thou > 0) || nxn(&n[i + 1]) > -1))
				write(1, " ", 1);
		}
		if (--trio <= -1)
			trio = 2;
	}
}
