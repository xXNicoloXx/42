/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:23:54 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 11:45:06 by ngriveau         ###   ########.fr       */
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

char *ft_upstr(char *str, char *ch)
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
	upstr[i] = ch[0];
	upstr[i + 1] = '\0';
	ch[0] = 127;
	free(str);
	return (upstr);
}

char *get_next_line(int fd)
{
	int i;
	char *str;
	static char *buffer;

	i = 0;
	if (buffer == NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer[i] == 127)
		i++;
	str = malloc(sizeof(char));
	str[0] = '\0';
										//printf("\t\t\t%s\n",buffer);
	while (buffer[i] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			if (0 == (read(fd, buffer, BUFFER_SIZE)))
				break;
			i = -1;
			//printf("\t\t\t\t\t%s\n",buffer);
			
		}
		else
			str = ft_upstr(str, &buffer[i]);
		i++;
	}
							//printf("\n\n");
	buffer[i] = 127;
	return(str);

}

int main(void)
{
	int i = 10;
	int fd = open("myfile.txt", O_RDONLY);
	while (0 < i)
	{
		printf("|%s|\n",get_next_line(fd));
		i--;
	}
    
}








/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:23:54 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 11:42:52 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_upstr(char *str, char *ch)
{
	int		i;
	char	*upstr;

	i = 0;
	if (ch[0] == 127)
		return (str);
	upstr = (malloc(sizeof(char) * ft_strlen(str) + 2));
	while (str[i] != '\0')
	{
		upstr[i] = str[i];
		i++;
	}
	upstr[i] = ch[0];
	upstr[i + 1] = '\0';
	ch[0] = 127;
	free(str);
	return (upstr);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*str;
	static char	*buffer;

	i = 0;
	if (buffer == NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (buffer[i] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			if (0 == (read(fd, buffer, BUFFER_SIZE)))
				break ;
			i = -1;
		}
		else
			str = ft_upstr(str, &buffer[i]);
		i++;
	}
	buffer[i] = 127;
	return (str);
}

// int main(void)
// {
// 	int i = 4880;
// 	int fd = open("livre.txt", O_RDONLY);
// 	while (0 < i)
// 	{
// 		printf("%s\n",get_next_line(fd));
// 		i--;
// 	}   
// }