#include "libft.h"
#include "get_next_line.h"

# ifndef MAP
#  define MAP "./test_maps/worldmap.fdf"
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
	t_pixel	**m;
	int		x;
	int		y;

	float		minh;
	float		maxh;
	int		winx;
	int		winy;

	float	z;
	float	r;
	float	i;
	int		d;
	unsigned long		color[100];
	float		hcolor1;
	float		hcolor2;
	float 		lenline;
	


	void	*mlx;
	void	*mlx_win;

	t_img	img;


}					t_map;

void ft_pos_pixel(t_map *m);
void ft_ligne(float ax, float ay, float bx, float by, t_map *m);
void ft_draw(t_map *m, float x, float y, int color);
void ft_tab_color(t_map *m);
void ft_init_color(t_map *m);
