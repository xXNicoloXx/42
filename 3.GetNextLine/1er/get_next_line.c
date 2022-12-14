/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:01 by ngriveau          #+#    #+#             */
/*   Updated: 2022/11/21 17:52:13 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{	
	int	i;

	i = 0;
	while (!(str[i] == '\0'))
		i++;
	return (i);
}

char *ft_my_malloc(char *ligne, char lettre)
{
    int len;
    int i;
    char *tempon;

    i = 0;
    len = ft_strlen(ligne);
	//printf("len = %d, str = %d(%c)\n", len, lettre, lettre);
   tempon = malloc(sizeof(char) * (len+1));
    tempon[len+1] = '\0';
    while (ligne[i] != '\0')
    {
        tempon[i] = ligne[i];
        i++;
    }
	tempon[i] = lettre;
	free(ligne);
	//printf("\nstrlen = %d tempon = %s", len, tempon);
	return(tempon);
}

char *get_next_line(int fd)
{
	int size = 20;
	int i = 0;
	int ok;
    char *ligne;
				int test = 1;
	static char *str;
	static int readnbr = 1; //////
	if (str == (NULL))
		str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	ligne = malloc(sizeof(char));
	ligne[0] = '\0';
	while (str[i] == 127)
		i++;
	//printf("i = %d", i);  ////////
	ok = 1;
	while (str[i] != '\n' || ok)
	{
		//printf("str[%d] = %c (size = %d)\n", i, str[i], size);    ////////
		if (i >= size)
		{
			test = read(fd, str, size);
			//printf("%d\n",test);
			//printf("\n\t\tREAD %d str = %s\n", readnbr, str);   ///////
			readnbr++;
			i = 0;
		}

		else
		{
			ligne = ft_my_malloc(ligne, str[i]);
			str[i] = 127;
			i++;
			ok = 0;
		}
		if (test == 0)
		{
			free(str);
			return(NULL);
		}
	}
	str[i] = 127;
	printf("\n\t\toutro str = %s\n",str);   //////////////
	//free(str);  
	return(ligne);
}

int main ()	
{
	char *read;
	int fd = open("myfile.txt", O_RDONLY, 0);
	//int fd = 0;
	while (1)
	{
		read = get_next_line(fd);
		if (read == NULL)
			break;
		else
			free(read);
	}
}
