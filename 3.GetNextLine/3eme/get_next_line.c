/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:04:05 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 16:54:10 by ngriveau         ###   ########.fr       */
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

int ft_check_new_line(char *buffer, int i)
{
	int size;
	
	size = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
		size++;
	}
	return (size)
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
	int input;
	
	input = BUFFER_SIZE;
	while (buffer[0] != '\0' && i == BUFFER_SIZE - 1)
	{
		if (i == BUFFER_SIZE - 1)
		{
			buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
			i = 0;
		}
		else
			i = ft_check_new_line(buffer, i);
			
	}
	
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
		buffer[BUFFER_SIZE] ='\0';
		
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
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	printf("\n|%s|",get_next_line(fd));
	
}