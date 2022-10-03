#include<stdio.h>

int isalpha( int character );

int	ft_isalpha(int str)
{	
	if (!((64 < str && str < 91) || (96 < str && str < 123)))
		return (0);
	return (1);
}


int main(void)
{
	int i = 0;
	while (i<127)
	{
		printf("%d\n", isalpha(i));
		printf("%d\n\n\n", ft_str_is_alpha(i));
		i++;
	}
}
