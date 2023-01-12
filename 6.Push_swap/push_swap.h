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

    int verifsens;
    int verifsensnbr;
    int verifrb;
}	t_swap;

int	ft_atoi(const char *str);


void ft_sa(t_swap *s);
void ft_sb(t_swap *s);
void ft_ss(t_swap *s);


void ft_pa(t_swap *s);
void ft_pb(t_swap *s);

void ft_rr(t_swap *s);
void ft_ra(t_swap *s, int rr);
void ft_rb(t_swap *s, int rr);

void ft_rra(t_swap *s);
void ft_rrb(t_swap *s);

