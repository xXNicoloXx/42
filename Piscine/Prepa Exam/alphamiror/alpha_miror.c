#include <stdio.h>
#include <unistd.h>


void    ft_aplha_miror(char *str)
{
    int i;
    char    lettre;

    i = 0;
    lettre = 0;
    while (str[i] != '\0')
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            lettre = str[i];
            lettre = lettre - 'a';
            lettre = 'z' - lettre;
            write(1, &lettre, 1);
        }
        else if ('A' <= str[i] && str[i] <= 'Z')
                {
            lettre = str[i];
            lettre = lettre - 'A';
            lettre = 'Z' - lettre;
            write(1, &lettre, 1);
        }
        else
            write(1, &str[i], 1);
        i++;

    }
}
int main(int c, char **v)
{
	if (c == 2)
		ft_aplha_miror(v[1]);
	write(1, "\n", 1);
    	
}
