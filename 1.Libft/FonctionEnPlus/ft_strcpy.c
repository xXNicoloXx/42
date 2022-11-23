#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



int main (void)
{
    char *test = "testsrc";
    char *test2;
    printf("%s\n", ft_strcpy(test2, test));
    printf("%s", strcpy(test2, test));
    return(0);
}

