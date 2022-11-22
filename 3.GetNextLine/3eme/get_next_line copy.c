/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:04:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 16:04:04 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_my_malloc(char *str, char *buffer, int i)
{
	int j;
	char *upstr;
	
	j = 0;
	upstr = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[j] != '\0')
	{
		upstr[j] = str[j];
		j++; 
	}
	upstr[j] = buffer[i];
	upstr[j + 1] = '\0';
	buffer[i] = 'V';
	free(str);
	return (upstr);
}

char *ft_new_line(char *buffer, char *str, int fd, int i)
{
	int end;
	
	while (buffer[i] != 'N' || (i == BUFFER_SIZE + 1))
	{
		if (i >= BUFFER_SIZE)
		{
			end = read(fd, buffer, BUFFER_SIZE);
			buffer[end] = '\0';
			printf("\t\t%s\n", buffer);
			if (end == 0)
				return (NULL);	
			i = - 1;
		}
		else
			str = ft_my_malloc(str, buffer, i);
		i++;
	}
	buffer[i] = 'V';
	printf("\t\tend =%s\n", buffer);
	return (str);
}

char *get_next_line(int fd)
{
	int i;
	char *str;
	static char *buffer;

	i = 0;
	if (fd < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		i = BUFFER_SIZE + 1;
	}
	while (buffer[i] == 'V')
		i++;
	str = malloc(sizeof(char));
	str[0] = '\0';
	return (ft_new_line(buffer, str, fd, i));
}

int main (void)
{
	int i = 10;
	int fd = open("myfile.txt", O_RDONLY);
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	printf("\n\n|%s|",get_next_line(fd));
	
}