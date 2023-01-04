/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dictionary2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:20:47 by snaji             #+#    #+#             */
/*   Updated: 2022/07/24 20:47:38 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

// Revoie la taille du dictionnaire afin de malloc
long	get_file_len(char *name)
{
	long		fd;
	long		ret;
	long		buf[1];
	long		len;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 1);
	while (ret)
	{
		len++;
		ret = read(fd, buf, 1);
	}
	if (close(fd) == -1)
		return (0);
	return (len);
}

/* Convertie toutes les ligne du dictionnaire en liste de
 chaine de caractere contenant chacune une ligne*/
char	**get_file_lines(char *name)
{
	long		fd;
	long		ret;
	char		*file_cpy;
	char		**file_lines;

	file_cpy = malloc((get_file_len(name) + 1) * sizeof(char));
	fd = open(name, O_RDONLY);
	if (fd == -1 || get_file_len(name) == 0)
		return (NULL);
	ret = read(fd, file_cpy, get_file_len(name));
	file_cpy[ret] = '\0';
	file_lines = ft_split(file_cpy, "\n");
	free(file_cpy);
	if (close(fd) == -1)
		return (NULL);
	return (file_lines);
}

// Renvoie la longueur de la cle afin de malloc, revoie 0 si cle invalide
size_t	get_key_size(char *line)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			len++;
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		i++;
		len++;
	}
	return (len);
}

// Renvoie la longueur de la valeur afin de malloc
size_t	get_value_size(char *line)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		i++;
		len++;
	}
	return (len);
}

/* Free le tableau de t_dictionnary*/
void	free_tab(t_dictionary *dict)
{
	int	i;

	i = 0;
	while (dict[i].key != NULL)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
