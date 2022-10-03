/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 09:25:37 by yzblah            #+#    #+#             */
/*   Updated: 2022/07/09 14:39:54 by yzblah           ###   ########.fr       */
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
			if ((xi == 1 || xi == x) && (yi == 1 || yi == y))
				c = 'o';
			else if (xi == 1 || xi == x)
				c = '|';
			else if (yi == 1 || yi == y)
				c = '-';
			else
				c = ' ';
			ft_putchar(c);
			xi = xi + 1;
		}
		ft_putchar('\n');
		yi = yi + 1;
	}
}
