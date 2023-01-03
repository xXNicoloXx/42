#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <time.h>
# include <X11/X.h>

# define MAP "./test_maps/42.fdf"
# define MSG_INVALID_MAP "Error invalid map"
# define MSG_INVALID_OS "Error invalid OS"
# define OS 3
# define WIDTH 1500
# define HEIGHT 800

// #  define MAP "./moremaps/hardests/hardest01.fdf"
# define Touch_LeftArrow 65361
# define Touch_RightArrow 65363
# define Touch_UpArrow 65362
# define Touch_DownArrow 65364
# define Touch_Moins 45
# define Touch_Plus 61
# define Touch_One 49
# define Touch_Tow 50
# define Touch_Three 51
# define Touch_Four 52
# define Touch_Five 53
# define Touch_Six 54
# define Touch_W 119
# define Touch_A 100
# define Touch_S 115
# define Touch_D 97
# define ESC 65307
# define Touch_C 99
# define Touch_M 109 //




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

typedef struct s_line
{
	float ax; 
	float ay;
	float bx;
	float by;
	float		hcolor1;
	float		hcolor2;
	int reverse;
}				t_line;

typedef struct s_map
{
	t_pixel	**initm;
	t_pixel	**m;
	t_line line;
	int		x;
	int		y;
	float		minh;
	float		maxh;

	float			z;
	float			r;
	float			i;
	int				movex;
	int				movey;

	float			hauteur;

	unsigned long	color[101];
	int				setupcolor;

	


	void	*mlx;
	void	*mlx_win;
	int		winx;
	int		winy;
	t_img	img;

	int mouse_move;
	float varcos;
	float varsin;
	int verifmonitor;
}					t_map;

//		COLOR_MAP
void	ft_setup_color_pt1(t_map *m);
void	ft_setup_color_pt2(t_map *m);
void	ft_setup_color_pt3(t_map *m);

//		COLOR CALCUL
void	ft_color(int nbr, t_map *m);
void	ft_draw(t_map *m, float x, float y, int color);
void	ft_tab_deg(t_map *m, int start, int end);
void	ft_tab_color(t_map *m);
void	ft_init_color(t_map *m);

//		MONITORING
void	ft_monitoring_invalid_map(t_map *m);
void	ft_monitoring_display_info_pt1(t_map *m);
void	ft_monitoring_display_info_pt2(t_map *m, char *value);
void	ft_monitoring_fade_color(t_map *m);
void	ft_monitoring(t_map *m);

//		LINE
void	ft_line_direction_pt1(float dx, float unity, float tmp, t_map *m);
void	ft_line_direction_pt2(float dy, float unity, float tmp, t_map *m);
void	ft_line_direction_pt3(float dy, float unity, float tmp, t_map *m);
void	ft_reverse_direction(float tmp, t_map *m);
void	ft_ligne(t_map *m);

//		LINE COLOR 	
int		ft_color_line(float nbpix, float pospix, t_map *m);
int		ft_color_line_down(float nbpix, float pospix, float deltah, t_map *m);
int		ft_color_line_up(float nbpix, float pospix, float deltah, t_map *m);

//		MAP
int		ft_x_map(char *ligne, int xmax);
int		ft_y_map(int fd, int *xmax);
void	ft_fill_map(t_map *m, int fd);
int		ft_fill_map_pt2(t_map *m, char *ligne, int y);
void	ft_copy_map(t_map *map);
void	ft_map(t_map *m);

//		MAP CALCUL
void	ft_hauteur(t_map *m);
void	ft_rota(t_map *m);
void	ft_incl(t_map *m);
void	ft_centre(t_map *m);
void	ft_move(t_map *m);

//		KEY MOUSE
void	ft_mouse_move(int x, int y, t_map *m);
int		ft_zoom(int keycode, int x, int y, t_map *m);
int		ft_key(int keycode, t_map *m);
void	ft_key_pt2(int keycode, t_map *m);
void	ft_key_pt3(int keycode, t_map *m);

//		PRINT MAP
void	ft_print_map(t_map *m);
void	ft_print_map_y(int x, int y, t_map *m);
void	ft_print_map_x(int x, int y, t_map *m);

//		CLEAN
void	ft_free_map(t_map *m, int exit);
void	ft_clean(t_map *m);

		//ANIMATION
void	ft_annimation(t_map *m);
void	ft_annimationpt2(t_map *m);

//		START
void	ft_all(t_map *m);
void	ft_intivalue(t_map *m);
int		main(void);
int		ft_cross_close(t_map *m);




