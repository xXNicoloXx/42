/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:57:49 by snaji             #+#    #+#             */
/*   Updated: 2022/07/24 22:28:22 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2_H
# define RUSH2_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct Dictionary
{
	char				*key;
	char				*value;
}	t_dictionary;
t_dictionary	*generate_dict(char	*name);
char			**ft_split(char *str, char *charset);
char			**get_file_lines(char *name);
size_t			get_key_size(char *line);
size_t			get_value_size(char *line);
int				ft_strcmp(char *s1, char *s2);
char			*search_key(char *key, t_dictionary *dictionnaire);
void			printnbr(char *nbr, t_dictionary *d);
int				ft_atoi(char *str);
int				ft_putstr(char *str);
int				ft_strlen(char *str);
void			free_tab(t_dictionary *dict);
void			free_split(char **split);
int				can_dict_print_nb(char *nb, t_dictionary *dict);
#endif