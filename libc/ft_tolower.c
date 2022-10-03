

#include <ctype.h>
#include <stdio.h>

int tolower( int character );


int ft_tolower(int character)
{
    if (64 < character && character < 91)
    {
        return(character + 32);
    }
    return(character);
}


int main(void)
{
	int i = -2;
	while (i<130)
	{
        printf("%c \t", tolower(i));
    	printf("%c \t %c\n", ft_tolower(i),i);
		i++;
	}
}
