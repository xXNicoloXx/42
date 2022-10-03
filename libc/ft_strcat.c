char	strlen1(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\0'))
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	lendest;
	int	i;

	lendest = strlen1(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (dest);
}
