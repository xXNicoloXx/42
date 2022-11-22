/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:23:54 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/22 12:38:40 by ngriveau         ###   ########.fr       */
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

char	*ft_start_malloc(char *str)
{
	int i;

	i = 0;
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
	{
		str[i] = 127;
		i++;
	}
	return(str);
}

char	*ft_upstr(char *str, char *ch)
{
	int		i;
	int		len;
	char	*upstr;

	i = 0;
	len = ft_strlen(str);
	if (ch[0] == 127)
		return (str);
	upstr = (malloc(sizeof(char) * (len + 2)));
	if (upstr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		upstr[i] = str[i];
		i++;
	}
	upstr[len] = ch[0];
	upstr[len + 1] = '\0';
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
		buffer = ft_start_malloc(buffer);
	buffer[BUFFER_SIZE] = '\0';
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (buffer[i] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			if (0 == (read(fd, buffer, BUFFER_SIZE)))
				return (NULL);
			i = -1;
		}
		else
			str = ft_upstr(str, &buffer[i]);
		i++;
	}
	buffer[i] = 127;
	return (str);
}

int main(void)
{
	int i = 6;
	int fd = open("myfile.txt", O_RDONLY);
	while (0 < i)
	{
		printf("%s\n",get_next_line(fd));
		i--;
	}   
}