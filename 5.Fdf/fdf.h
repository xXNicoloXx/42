#include "libft.h"
#include "get_next_line.h"

# ifndef PI
#  define PI 3.14159265359
# endif

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