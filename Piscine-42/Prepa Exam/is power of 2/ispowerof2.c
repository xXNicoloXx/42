#include <stdio.h>


int	    is_power_of_2(unsigned int n)
{
    int res;
    
    res = 2;
    if (n == 1 || n == 2)
        return (1);
    while(res < n)
    {
        res = res * 2;
        printf("res = %d\n", res);
        if (res == n)
            return (1);
    }
    return (0);
}

int main(int c, char v)
{
    printf("%d", is_power_of_2(512));
}