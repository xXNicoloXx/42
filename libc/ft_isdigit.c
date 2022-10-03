#include<stdio.h>

int isdigit( int character );

int	ft_isdigit(int str)
{	
	if (!((47 < str && str < 58)))
		return (0);
	return (1);
}


int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d \t", isdigit(i));
		printf("%d \t %c\n\n", ft_isdigit(i),i);
		i++;
	}
}
