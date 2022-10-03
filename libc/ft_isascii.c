#include<stdio.h>

int isascii( int character );

int	ft_isascii(int str)
{	
	if (!(-1 < str && str < 128))
		return (0);
	return (1);
}


int main(void)
{
	int i = -4;
	while (i<130)
	{
		printf("%d \t", isascii(i));
		printf("%d \t %c\n", ft_isascii(i),i);
		i++;
	}
}
