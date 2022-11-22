/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 20:30:14 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i - 1); 
}
int ft_len_malloc(char *buffer, int check)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != 'N' && buffer[i] != '\0' && i < check)
		i++;
	return (i); 
}

char *ft_my_malloc(char *buffer, char *ligne, int check)
{
	int i;
	int j;
	int len;
	char *upligne;

	i = 0;
	j = 0;
	len = ft_len_malloc(buffer, check) + ft_strlen(ligne);
	printf("len buffer =%d len ligne= %d\n", ft_len_malloc(buffer, check), ft_strlen(ligne));
	while (buffer[i] == 'V')
		i++;
	upligne = malloc(sizeof(char) * (len + 1));
	upligne[len] = '\0';
	while (ligne[j] != '\0')
	{
		upligne[j] = ligne[j];
		j++;
	}
	len = ft_len_malloc(buffer, check);
	while (len >= 0)
	{
		upligne[j] = buffer[i];
		buffer[i] = 'V';
		len--;
		i++;
		j++;
	}
	return (upligne);
}

char *ft_new_line(int i, int fd, char *buffer, char *ligne)
{
	int check;
	int len;
		printf("\t\t\tstart buffer = \t|%s|\n", buffer);

	if (i == -42)
	{
			check = read(fd, buffer, BUFFER_SIZE);
	}
	while (1)
	{	
		ligne = ft_my_malloc(buffer, ligne, check);
		printf("\t\t\tinter ligne = |%s|\n",ligne);
		printf("\t\t\tbuffer = \t|%s|\n", buffer);
		len = ft_strlen(ligne);
		if (ligne[len] == 'N')
		{
			//printf("str[%d] = %c\n", len, ligne[len - 1]);
			ligne[len] = '\0';
			break ;
		}
		check = read(fd, buffer, BUFFER_SIZE);
		printf("\t\t\t\t\t\t\t\t\t\tnewbuffer = |%s| check = %d\n", buffer, check);
		buffer[10] = '\0'; 
	}
	printf("\tendbuffer = %s\n", buffer);
	return(ligne);
}

char *get_next_line(int fd)
{
    int i;
    char *ligne;
    static char* buffer;
    
    i = 0;
	if (fd < 0)
		return (NULL);
    ligne = malloc(sizeof(char) * 1);
    ligne[0] = '\0';
    if (buffer == NULL)
	{
        buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		buffer[BUFFER_SIZE] = '\0';
		i = -42;
	}
	return (ft_new_line(i, fd, buffer, ligne));
	
}

int main (void)
{
	int i = 10;
	int fd = open("myfile.txt", O_RDONLY);
	printf("fd = %d\n\n", fd);
	printf("|%s|\n",get_next_line(fd));
	printf("|%s|\n",get_next_line(fd));
	printf("|%s|\n",get_next_line(fd));
	printf("|%s|\n",get_next_line(fd));
	printf("|%s|\n",get_next_line(fd));
	printf("|%s|\n",get_next_line(fd));
}