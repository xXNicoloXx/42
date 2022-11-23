/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 17:02:46 by ngriveau         ###   ########.fr       */
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

int	ft_len_malloc(char *buffer, int check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		return (i + 1);
	else
		return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int check)
{
	int		i;
	int		j;
	int		len;
	char	*upligne;

	i = 0;
	j = 0;
	while (buffer[i] == -42)
		i++;
	len = ft_len_malloc(&buffer[i], check) + ft_strlen(ligne);
	upligne = malloc(sizeof(char) * (len + 1));
	upligne[len] = '\0';
	while (ligne[j] != '\0')
	{
		upligne[j] = ligne[j];
		j++;
	}
	len = ft_len_malloc(&buffer[i], check);
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
	while (check != 0)
	{	
		ligne = ft_my_malloc(buffer, ligne, check);
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
	static char	*buffer;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
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
	int i = 5000;
	int fd = open("livre.txt", O_RDONLY);
	while (i != 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
}