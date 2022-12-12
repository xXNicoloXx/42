#include "libft.h"
#include "get_next_line.h"

# ifndef MAP
#  define MAP "./test_maps/42.fdf"
# endif


typedef struct s_pixel
{
	float		x;
	float		y;
	float		z;
	float		h;
}				t_pixel;

typedef struct s_img
{
	void	*i;
	int		size;
	int		p;
	int 	e;
	char 	*data;
	int		r;
	int		b;
	int		g;
}				t_img;

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
	t_img	img;


}					t_map;

void ft_pos_pixel(t_map *m);
void ft_ligne(float ax, float ay, float bx, float by, int color, t_map *m);
void ft_draw(t_map *m, float x, float y, int color);
