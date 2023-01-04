#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	*r;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				break ;
		if (j != ft_strlen(charset))
			break ;
	}
	size = i + 1;
	r = malloc(sizeof(char) * size);
	i = -1;
	while (++i < size - 1)
		r[i] = str[i];
	r[i] = '\0';
	return (r);
}

void	ft_split_str(char *str, char *charset, char **tab)
{
	int	i;
	int	j;
	int	non_sep;
	int	index;

	non_sep = 0;
	index = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				break ;
		if (j == ft_strlen(charset))
		{
			if (non_sep++ == 0)
				tab[index++] = ft_strdup(&(str[i]), charset);
		}
		else
			non_sep = 0;
	}
}

int	ft_cw(char *str, char *charset)
{
	int	i;
	int	j;
	int	non_sep;
	int	words;

	non_sep = 0;
	words = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				break ;
		if (j == ft_strlen(charset))
		{
			if (non_sep++ == 0)
				words++;
		}
		else
			non_sep = 0;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_cw(str, charset) + 1));
	if (tab == NULL)
		return (0);
	tab[ft_cw(str, charset)] = 0;
	ft_split_str(str, charset, tab);
	return (tab);
}
