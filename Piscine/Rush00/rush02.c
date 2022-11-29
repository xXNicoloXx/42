/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaboin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:48:04 by mbaboin           #+#    #+#             */
/*   Updated: 2022/07/09 14:20:34 by yzblah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	char	c;
	int		yi;
	int		xi;

	yi = 1;
	while (yi <= y)
	{
		xi = 1;
		while (xi <= x)
		{
			if ((xi == 1 || xi == x) && (yi == 1))
				c = 'A';
			else if ((xi == 1 || xi == x) && (yi == y))
				c = 'C';
			else if (xi == 1 || xi == x || yi == 1 || yi == y)
				c = 'B';
			else
				c = ' ';
			ft_putchar(c);
			xi = xi + 1;
		}
		ft_putchar('\n');
		yi = yi + 1;
	}
}
