/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 21:51:48 by ngriveau         ###   ########.fr       */
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
int ft_len_malloc(char *buffer, int check)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != 'N' && buffer[i] != '\0')
		i++;
	//printf("\t\t\tbuffer[0] = %c(%d)(check %d)\n", buffer[0],i ,check);	
	return (i + 1); 
}

char *ft_my_malloc(char *buffer, char *ligne, int check)
{
	int i;
	int j;
	int len;
	char *upligne;

	i = 0;
	j = 0;
	while (buffer[i] == 'V')
		i++;
	len = ft_len_malloc(&buffer[i], check) + ft_strlen(ligne);
	printf("\t\t\tlen buffer =%d len ligne= %d len = %d\n", ft_len_malloc(&buffer[i], check), ft_strlen(ligne), len);

	upligne = malloc(sizeof(char) * (len + 1));
	upligne[len - 1] = '\0';
	while (ligne[j] != '\0')
	{
		upligne[j] = ligne[j];
		j++;
	}
	len = ft_len_malloc(&buffer[i], check);
	while (len > 0)
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
	check = 42;
	if (i == -42)
	{
			check = read(fd, buffer, BUFFER_SIZE);
	}
	while (check != 0)
	{	
		ligne = ft_my_malloc(buffer, ligne, check);
		printf("\t\t\tinter ligne = |%s|\tbuffer = \t|%s|\n",ligne, buffer);
		len = ft_strlen(ligne);
		if (ligne[len - 1] == 'N')
		{
			//printf("str[%d] = %c\n", len, ligne[len - 1]);
			ligne[len - 1] = '\0';
			break ;
		}
		check = read(fd, buffer, BUFFER_SIZE);
		printf("\t\t\tnewbuffer = |%s| check = %d\n", buffer, check);
		buffer[check] = '\0'; 
	}
	printf("\t\t\tendbuffer = %s\n\n\n", buffer);
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