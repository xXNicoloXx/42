#include <string.h>
#include <stdio.h>


char *strchr( const char * string, int searchedChar );

char *ft_strchr(char *str, int lettre)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    i--;
    while (str[i] != lettre)
    {
        if (str[i] == '\0')
            return(NULL);
        i--;
    }
    return(&str[i]);
    
}


int main (void)
{
    char *texte = "cwufgwugfuwguygcjhwfjhfhgfwcd";
    int lettre = 'c';

    printf("1:%s\n", strrchr(texte, lettre));
    printf("2:%s", ft_strchr(texte, lettre));    
}
