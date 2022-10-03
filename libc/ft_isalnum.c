#include<stdio.h>

int isalnum( int character );

int	ft_isdigit(int str)
{	
	if (!((47 < str && str < 58) || (64 < str && str < 91) || (96 < str && str < 123)))
		return (0);
	return (1);
}


int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d \t", isalnum(i));
		printf("%d \t %c\n", ft_isdigit(i),i);
		i++;
	}
}
