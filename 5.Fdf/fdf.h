#include "libft.h"
#include "get_next_line.h"

# ifndef PI
#  define PI 3.14159265359
# endif

typedef struct s_pixel
{
	float		x;
	float		y;
	float		z;
	float		h;
}				t_pixel;

typedef struct s_map
{
	int		x;
	int		y;
	float	z;

	float	r;
	float	i;
	int		d;
	
	t_pixel	**m;
	void	*mlx;
	void	*mlx_win;
	int		winx;
	int		winy;
}					t_map;

void ft_pos_pixel(t_map *m);