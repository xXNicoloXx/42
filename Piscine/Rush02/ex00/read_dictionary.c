/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:54:26 by snaji             #+#    #+#             */
/*   Updated: 2022/07/24 22:47:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

/* Checks if the number is not to long to be printed with the dictionary*/
int	can_dict_print_nb(char *nb, t_dictionary *dict)
{
	int	i;

	i = 0;
	while (dict[i].key != NULL)
	{
		if (ft_strlen(dict[i].key) > ft_strlen(nb) - 3)
			return (1);
		i++;
	}
	return (0);
}

/* Part 2 of make_struct*/
void	make_struct2(char *line, t_dictionary *el)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		(*el).value[j++] = line[i];
		i++;
	}
	(*el).value[j] = '\0';
}

/* Parse a line of the dictionary and return a t_dictionary
 containing the key and the value of this line*/
t_dictionary	make_struct(char *line)
{
	t_dictionary	el;
	size_t			i;
	size_t			j;

	el.key = malloc((get_key_size(line) + 1) * sizeof(char));
	el.value = malloc((get_value_size(line) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == '+' || line[i] == '-')
	{
		if (line[i] == '-')
			(el.key)[j++] = '-';
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		(el.key)[j++] = line[i];
		i++;
	}
	make_struct2(&line[i], &el);
	return (el);
}

/* Return an array of t_dictionary containing all the
 keys and values of a dictionary*/
t_dictionary	*generate_dict(char	*name)
{
	t_dictionary	*dictionnaire;
	char			**file_lines;
	size_t			i;
	size_t			j;

	file_lines = get_file_lines(name);
	if (file_lines == NULL)
		return (NULL);
	i = 0;
	while (file_lines[i] != 0)
		i++;
	dictionnaire = malloc((i + 1) * sizeof(t_dictionary));
	j = 0;
	while (j < i)
	{
		dictionnaire[j] = make_struct(file_lines[j]);
		j++;
	}
	dictionnaire[i].key = NULL;
	dictionnaire[i].value = NULL;
	free_split(file_lines);
	return (dictionnaire);
}

/* Return the value corresponding to a key in an array
 of t_dictionary, return NULL if the key is not found*/
char	*search_key(char *key, t_dictionary *dictionnaire)
{
	size_t	i;

	i = 0;
	while (dictionnaire[i].key != NULL)
	{
		if (ft_strcmp(key, dictionnaire[i].key) == 0)
		{
			free(key);
			return (dictionnaire[i].value);
		}
		i++;
	}
	free(key);
	return (NULL);
}
