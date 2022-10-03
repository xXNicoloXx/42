

#include <ctype.h>
#include <stdio.h>

int toupper( int character );


int ft_toupper( int character )
{
    if (96 < character && character < 123)
    {
        return(character - 32);
    }
    return(character);
}


int main(void)
{
	int i = -2;
    printf("%c \t", toupper(i));
    printf("%c \t\t\t %c\n", ft_toupper(i),i);
	while (i<130)
	{
        printf("%c \t", toupper(i));
    	printf("%c \t %c\n", ft_toupper(i),i);
		i++;
	}
}
