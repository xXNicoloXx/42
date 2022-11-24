/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/24 14:20:07 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_len_malloc(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (i + 1);
	else
		return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne)
{
	int		i;
	int		j;
	int		len;
	char	*upligne;

	i = 0;
	j = 0;
	while (buffer[i] == -42)
		i++;
	len = ft_len_malloc(&buffer[i]) + ft_strlen(ligne);
	upligne = malloc(sizeof(char) * (len + 1));
	upligne[len] = '\0';
	while (ligne[j] != '\0')
	{
		upligne[j] = ligne[j];
		j++;
	}
	len = ft_len_malloc(&buffer[i]);
	while (len-- > 0)
	{
		upligne[j++] = buffer[i];
		buffer[i++] = -42;
	}
	free(ligne);
	return (upligne);
}

char	*ft_new_line(int i, int fd, char *buffer, char *ligne)
{
	int	check;
	int	len;

	check = 42;
	if (i == -42)
			check = read(fd, buffer, BUFFER_SIZE);
	if (check == -1 || check == 0)
		return (ft_free_all(buffer, ligne, 3));
	while (check != 0 || i !=  -100)
	{	
		i = -100;
		ligne = ft_my_malloc(buffer, ligne);
		len = ft_strlen(ligne);
		if (ligne[len - 1] == '\n')
			break ;
		check = read(fd, buffer, BUFFER_SIZE);
		buffer[check] = '\0';
	}
	return (ligne);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*ligne;
	static char	buffer[BUFFER_SIZE + 1];

	i = -1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	ligne = malloc(sizeof(char) * 1);
	ligne[0] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	//printf("buffer[0] = %d\n", buffer[0]);
	while (buffer[i] != '\0')
	{
		buffer[i] = 'B';
		i++;
		printf("print\n");
	}
	i = -42;
	}
	//printf("|%s|",buffer);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_all(buffer, ligne, 1));
	return (ft_new_line(i, fd, buffer, ligne));
}

int main (void)
{
	int i = 5051;

	int fd = open("livre.txt", O_RDONLY);
	while (i)
	{
		printf("%s",get_next_line(fd));
		i--;
	}
	//printf(" %s\n\n", get_next_line(fd)); 

	//printf(" %s\n\n", get_next_line(fd));
}