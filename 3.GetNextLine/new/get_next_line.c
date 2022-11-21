/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:23:54 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/21 23:04:45 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_upstr(char *str, char ch)
{
	int i;
	char *upstr;

	i = 0;
	upstr = (malloc(sizeof(char) * ft_strlen(str) + 2));
	while (str[i] !='\0')
	{
		upstr[i] = str[i];
		i++;
	}
	upstr[i] = ch;
	upstr[i + 1] = '\0';
	free(str);
	return (upstr);
}

char *get_next_line(int fd)
{
	int j = 0;
	int i;
	char *str;
	static char *buffer;

	i = 0;
	if (buffer == NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer[i] == 'V')
		i++;
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (buffer[i] != '\n')
	{
		while (str[j] != '\0')
		{
			//printf("\t\tbuffer[%d] = \t%c (%d)\n", j, buffer[j], buffer[j]);
			j++;
		}
		j = 0;
		if (i == BUFFER_SIZE)
		{
			if (read(fd, buffer, BUFFER_SIZE) != BUFFER_SIZE)
				break;
			i = -1;
		}
		else
		{
			str = ft_upstr(str, buffer[i]);
			buffer[i] = 'V';
		}
		i++;
	}
	buffer[i] = 'V';
	i = 0;
	while (buffer[i])
	{
		printf("\t%c|%d|",buffer[i], buffer[i]);
		i++;
	}
	printf("\n");
	return(str);

}

int main(void)
{
	int i = 10;
	int fd = open("myfile.txt", O_RDONLY);
	while (0 < i)
	{
		printf("%s|\n",get_next_line(fd));
		i--;
	}
    
}