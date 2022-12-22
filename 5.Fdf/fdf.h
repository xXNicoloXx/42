#include "libft.h"
#include "get_next_line.h"
#include <time.h>

# ifndef MAP
#  define MAP "./test_maps/42.fdf"
// #  define MAP "./moremaps/hardests/hardest01.fdf"
#  define Touch_LeftArrow 65361
#  define Touch_RightArrow 65363
#  define Touch_UpArrow 65362
#  define Touch_DownArrow 65364
#  define Touch_Moins 45
#  define Touch_Plus 61
#  define Touch_One 49
#  define Touch_Tow 50
#  define Touch_Three 51
#  define Touch_W 119
#  define Touch_A 100
#  define Touch_S 115
#  define Touch_D 97


// #  define Touch_LeftArrow 123
// #  define Touch_RightArrow 124
// #  define Touch_UpArrow 126
// #  define Touch_DownArrow 125
// #  define Touch_Moins 27
// #  define Touch_Plus 24
// #  define Touch_One 18
// #  define Touch_Tow 19
// #  define Touch_Three 20
// #  define Touch_W 13
// #  define Touch_A 0
// #  define Touch_S 1
// #  define Touch_D 2

# endif

typedef struct s_print
{
	int		x;
	int		y;
	int		h;
	int		cmpx;
	int		cmpy;
	int		cmph;
	int		resetx;
	int		resety;
	int		reseth;
}				t_print;

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
	t_pixel	**initm;
	t_pixel	**m;
	t_print print;
	int		x;
	int		y;
	float varcos;
	float varsin;

	float		minh;
	float		maxh;
	int		winx;
	int		winy;

	float	z;
	float	r;
	float	i;
	int		movex;
	int		movey;
	float		hauteur;
	unsigned long		color[201];
	float		hcolor1;
	float		hcolor2;
	float 		lenline;
	


	void	*mlx;
	void	*mlx_win;

	t_img	img;

	int mouse_move;
}					t_map;

void ft_pos_pixel(t_map *m);
void ft_ligne(float ax, float ay, float bx, float by, t_map *m);
void ft_draw(t_map *m, float x, float y, int color);
void ft_tab_color(t_map *m);
void ft_init_color(t_map *m);
int ft_monitoring(t_map *m);
void ft_intimap(t_map *m);