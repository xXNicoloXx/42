#include <string.h> 
#include <stdio.h> 



void	*ft_memset(void *b, int c, size_t len)
{
	char *str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
int main (void)
{
    void *ptr = "r";
    int value = 34;
    int n = 2;
    printf("%d", ft_memset(ptr, value, n));
}