/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzblah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:53:02 by yzblah            #+#    #+#             */
/*   Updated: 2022/07/09 14:21:01 by yzblah           ###   ########.fr       */
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
			if (xi == 1 && yi == y && y != 1)
				ft_putchar('C');
			else if (xi == x && yi == 1 && x != 1)
				ft_putchar('C');
			else if ((xi == 1 && yi == 1) || (xi == x && yi == y))
				ft_putchar('A');
			else if (xi == 1 || xi == x || yi == 1 || yi == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			xi = xi + 1;
		}
		ft_putchar('\n');
		yi = yi + 1;
	}
}
