#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_swap
{
	int tmp;
	int len;
	int move;
    int	*tab1;
    int	*filltab1;
    int	*tab2;
    int	*filltab2;
}	t_swap;

int	ft_atoi(const char *str);


void ft_sa(t_swap *s);
