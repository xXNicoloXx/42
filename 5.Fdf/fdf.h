#include "libft.h"
#include "get_next_line.h"


typedef struct s_map
{
    int     x;
    int     y;
    int     z;
    float     r;
    int     d;
    int     inc;
    int     **map;
    void	*mlx;
	void	*mlx_win;
}					t_map;