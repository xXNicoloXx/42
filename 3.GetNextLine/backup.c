/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/25 12:13:43 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != 'N')
		i++;
	if (str[i] == 'N')
		i++;
	return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int size)
{
		int		i;
		int		j;
		char	*upligne;
		
		i = 0;
		j = 0;
		if (buffer[i] == '\0')
			return (ligne);
		while (buffer[i] == 'V')
			i++;
		upligne = malloc(sizeof(char) * (ft_strlen(ligne) + ft_strlen(&buffer[i]) + 1));
		upligne[ft_strlen(ligne) + ft_strlen(&buffer[i])] = '\0';
		size = ft_strlen(ligne);
		//printf("\t\t\t\t\t\tSTART\tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );
		while (--size + 1)
		{
			upligne[j] = ligne[j];
			//printf("\tupligne[%d] = |%c|(%d) \t buffer(%d) = |%c|(%d)\n\n", j, upligne[j], upligne[j], j , ligne[j], ligne[j]);
			j++;
		}
		size = ft_strlen(&buffer[i]);
		//printf("\t\t\t\t\t\tMID   \tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );
		while(--size + 1)
		{
			upligne[j] = buffer[i];
			//printf("\n\tupligne[%d] = |%c|(%d) \t buffer(%d) = |%c|(%d)\n\n", j, upligne[j], upligne[j], i , upligne[i], upligne[i]);
			buffer[i] = 'V';
			i++;
			j++;
		}
		//printf("\t\t\t\t\t\tend   \tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );

		return (upligne);	
}

char	*ft_new_line(char *buffer, int size, int fd)
{	
	char *ligne;

	ligne = malloc(sizeof(char));
	ligne[0] = '\0';
	while (size != 0)
	{
		ligne = ft_my_malloc(buffer, ligne ,size);
		//printf("buffer = |%s|\tligne = |%s|\n", buffer, ligne);
		if (ligne[ft_strlen(ligne) - 1] == 'N')
			return (ligne);
		size = read(fd, buffer, BUFFER_SIZE);
		//printf("\t\t\t\t\t\tNEW buffer = |%s|\n",buffer);
	}
	return(NULL);
}

char	*get_next_line(int fd)
{
	int size;
	static char	buffer[BUFFER_SIZE + 1] = {0};
	
	size = 1;
	buffer[BUFFER_SIZE] = '\0';
	if (buffer[0] == '\0' && BUFFER_SIZE > 1)
		size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
		return (NULL);
	return (ft_new_line(buffer, size, fd));
}

int main (void)
{
	int i = 10;

	int fd = open("myfile.txt", O_RDONLY);
	while (i)
	{
		printf("gnl = |%s|\n",get_next_line(fd));
		i--;
	}
	//printf(" %s\n\n", get_next_line(fd)); 

	//printf(" %s\n\n", get_next_line(fd));
}

/// 0 leak 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/24 17:47:19 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str, int verif)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n' && verif == 1)
		i++;
	return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int size)
{
		int		i;
		int		j;
		char	*upligne;
		
		i = 0;
		j = 0;
		if (buffer[i] == '\0')
			return (ligne);
		while (buffer[i] == -42)
			i++;
		upligne = malloc(sizeof(char) * (ft_strlen(ligne, 1) + ft_strlen(&buffer[i], 1) + 1));
		upligne[ft_strlen(ligne, 1) + ft_strlen(&buffer[i], 1)] = '\0';
		size = ft_strlen(ligne, 1);
		//printf("\t\t\t\t\t\tSTART\tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );
		while (--size + 1)
		{
			upligne[j] = ligne[j];
			//printf("\tupligne[%d] = |%c|(%d) \t buffer(%d) = |%c|(%d)\n\n", j, upligne[j], upligne[j], j , ligne[j], ligne[j]);
			j++;
		}
		size = ft_strlen(&buffer[i], 1);
		//printf("\t\t\t\t\t\tMID   \tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );
		while(--size + 1)
		{
			upligne[j] = buffer[i];
			//printf("\n\tupligne[%d] = |%c|(%d) \t buffer(%d) = |%c|(%d)\n\n", j, upligne[j], upligne[j], i , upligne[i], upligne[i]);
			buffer[i] = -42;
			i++;
			j++;
		}
		//printf("\t\t\t\t\t\tend   \tbuffer = |%s|\tligne = |%s|\t upligne = |%s|\n", buffer, ligne, upligne );
		free(ligne);
		return (upligne);	
}

char	*ft_new_line(char *buffer, int size, int fd)
{	
	char *ligne;

	ligne = malloc(sizeof(char));
	ligne[0] = '\0';
	while (size != 0)
	{
		ligne = ft_my_malloc(buffer, ligne ,size);
		//printf("buffer = |%s|\tligne = |%s|\n", buffer, ligne);
		if (ligne[ft_strlen(ligne, 0)] == '\n')
			return (ligne);
		size = read(fd, buffer, BUFFER_SIZE);
		//printf("\t\t\t\t\t\tNEW buffer = |%s|\n",buffer);
	}
	return(ligne);
}

char	*get_next_line(int fd)
{
	int size;
	static char	buffer[BUFFER_SIZE + 1] = {0};
	
	size = 1;
	buffer[BUFFER_SIZE] = '\0';
	if (buffer[0] == '\0' && BUFFER_SIZE > 1)
		size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
		return (NULL);
	return (ft_new_line(buffer, size, fd));
}

int main (void)
{
	int i = 5000;
	char *test;
	int fd = open("livre.txt", O_RDONLY);
	while (i)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free(test);		
		
		i--;
	}
	//printf(" %s\n\n", get_next_line(fd)); 

	//printf(" %s\n\n", get_next_line(fd));
}

// ok tester

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/25 12:12:37 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_s(char *str, int verif)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n' && verif == 1)
		i++;
	return (i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int size)
{
	int		i;
	int		j;
	char	*upligne;

	i = 0;
	j = 0;
	if (buffer[i] == '\0')
		return (ligne);
	while (buffer[i] == -42)
		i++;
	upligne = malloc(sizeof(char) * (ft_s(ligne, 1) + ft_s(&buffer[i], 1) + 2));
	upligne[ft_s(ligne, 1) + ft_s(&buffer[i], 1)] = '\0';
	size = ft_s(ligne, 1);
	while (--size + 1)
	{
		upligne[j] = ligne[j];
		j++;
	}
	size = ft_s(&buffer[i], 1);
	while (--size + 1 && buffer[i] != -66)
	{
		upligne[j] = buffer[i];
		buffer[i] = -42;
		i++;
		j++;
	}
	i = 0;
	while (upligne[i] != '\0')
	{
		if (upligne[i] == -42)
			upligne[i] = '\0';
		i++;
	}
	
	free(ligne);
	return (upligne);
}

char	*ft_new_line(char *buffer, int size, int fd)
{	
	char	*ligne;

	ligne = malloc(sizeof(char));
	ligne[0] = '\0';
	while (size != 0)
	{
		ligne = ft_my_malloc(buffer, ligne, size);
		if (ligne[ft_s(ligne, 0)] == '\n')
			return (ligne);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (ligne[0] == '\0')
	{
		free(ligne);
		return (NULL);
	}
	return(ligne);
}

char	*get_next_line(int fd)
{
	int			size;
	static char	buffer[BUFFER_SIZE + 1] = {0};

	size = -5;
	buffer[BUFFER_SIZE] = '\0';
	if (buffer[0] == '\0')
		size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
		return (NULL);
	return (ft_new_line(buffer, size, fd));
}

// int main (void)
// {
// 	int i = 1;
// 	char *test;
// 	int fd = open("test.txt", O_RDONLY);
// 	while (i)
// 	{
// 		test = get_next_line(fd);
// 		printf(" %s", test);
// 		i--;
// 	}
// 	while (i < 12)
// 	{
// 		printf(" ligne[%d] = %c (%d)\n", i, test[i], test[i]);
// 		i++;
// 	}
// }