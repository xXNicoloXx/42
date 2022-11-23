/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:31 by ngriveau         ###   ########.fr       */
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
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
	while (buffer[i] == 127)
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
		buffer[i] = 127;
		len--;
		i++;
		j++;z
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
		if (ligne[len - 1] == '\n')
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


// marche mais leak


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 12:17:27 by ngriveau         ###   ########.fr       */
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
		return(i);
}

char	*ft_my_malloc(char *buffer, char *ligne, int check)
{
	int		i;
	int		j;
	int		len;
	char	*upligne;

	i = 0;
	j = 0;
	while (buffer[i] == 127)
		i++;
	len = ft_len_malloc(&buffer[i], check) + ft_strlen(ligne);
	//printf("\tLEN buffer =%d len ligne= %d len = %d\n", ft_len_malloc(&buffer[i], check), ft_strlen(ligne), len);
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
		//rintf("swap buffer[%d] = %c\n", i, buffer[i]);
		upligne[j++] = buffer[i];
		buffer[i++] = 127;
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
		//printf("\t.... inter ligne = |%s|\tbuffer = |%s|\n",ligne, buffer);
		
		ligne = ft_my_malloc(buffer, ligne, check);
		len = ft_strlen(ligne);
		//printf("\t&&&& inter ligne = |%s|\tbuffer = |%s|\n\t ligne[%d] = %c",ligne, buffer, len, ligne[len]);

		if (ligne[len - 1] == '\n')
		{
			ligne[len - 1] = '\0';
			break ;
		}
		check = read(fd, buffer, BUFFER_SIZE);
		buffer[check] = '\0';
	}
	//printf("  buffer out = |%s|\n", buffer);
	return (ligne);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*ligne;
	static char	*buffer;

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
	int i = 5001;
	int fd = open("livre.txt", O_RDONLY);
	while (i != 0)
	{
		printf("%s\n", get_next_line(fd));
		i--;
	}
}

///////chp bacup sattic nbrbuf

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:56:26 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/23 16:53:57 by ngriveau         ###   ########.fr       */
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
		return(i);
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
	//printf("\tLEN buffer =%d len ligne= %d len = %d\n", ft_len_malloc(&buffer[i], check), ft_strlen(ligne), len);
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
		//rintf("swap buffer[%d] = %c\n", i, buffer[i]);
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
						static int test = -1;
	check = 42;
	if (i == -42)
																{
			check = read(fd, buffer, BUFFER_SIZE);			
	while (check != 0)
	{	
		//printf("\t.... inter ligne = |%s|\tbuffer = |%s|\n",ligne, buffer);
		
		ligne = ft_my_malloc(buffer, ligne, check);
		len = ft_strlen(ligne);
		//printf("\t&&&& inter ligne = |%s|\tbuffer = |%s|\n\t ligne[%d] = %c",ligne, buffer, len, ligne[len]);

		if (ligne[len - 1] == '\n')
			break ;
		check = read(fd, buffer, BUFFER_SIZE);
		++test;
		buffer[check] = '\0';
		printf("%d|%s|\n", test, buffer);
	}
	//printf("  buffer out = |%s|\n", buffer);
	//printf("buffer = %d\n", test);
	return (ligne);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*ligne;
	static char	*buffer;
	
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
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
	int i = 1500;
	int fd = open("livre.txt", O_RDONLY);
	while (i != 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
} 

///////// norminette marche 5000 leak

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