#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *strdup(const char *s);

char *ft_strdup(char *str)
{
    int i;
    char *dup;

    i = 0;
    while (str[i] != '\0')
        i++;
    dup = malloc(sizeof(char) * i);
    i = 0;
    while (str[i] != '\0')
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return(dup);
}

int main (void)
{
    char *test = "Bonjoujcsyfjwgfwr les \n amis";
    printf("%s\n", ft_strdup(test));
    printf("%s", strdup(test));
    return(0);
}