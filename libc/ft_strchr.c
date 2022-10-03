#include <string.h>
#include <stdio.h>


char *strchr( const char * string, int searchedChar );

char *ft_strchr(char *str, int lettre)
{
    int i;

    i = 0;
    while (str[i] != lettre)
    {
        if (str[i] == '\0')
            return(NULL);
        i++;
    }
    return(&str[i]);
}


int main (void)
{
    char *texte = "ciuyguyguygciuyguygcd";
    int lettre = 'g';

    printf("1:%s\n", strchr(texte, lettre));
    printf("2:%s", ft_strchr(texte, lettre));    
}
