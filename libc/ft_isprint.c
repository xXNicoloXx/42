#include<stdio.h>

int isprint( int character );

int	ft_isprint(int str)
{	
	if (!(31 < str && str < 127))
		return (0);
	return (1);
}


int main(void)
{
	int i = -2;
	while (i<129)
	{
		printf("%d \t", isprint(i));
		printf("%d \t %c\n", ft_isprint(i),i);
		i++;
	}
}
