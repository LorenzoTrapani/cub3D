#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define KEY_ESC XK_Escape
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M XK_m
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define MOVE_SPEED 0.01
# define ROTATE_SPEED 0.1
# define FOV 60
# define NUM_RAYS 100
# define M_PI 3.14159265358979323846
# define M_PI_2 1.57079632679489661923
# define TILE_SIZE 8
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREY 0x00808080
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define ORANGE 0x00FFA500

typedef	struct s_map
{
	char		**map_mtx;
	int			width;
	int			height;
}				t_map;

typedef struct s_tex
{
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	int			floor;
	int			ceiling;
}			t_tex;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_minimap
{
	char		*minimap_data;
	bool 		show;
}				t_minimap;

typedef struct s_ray 
{
    double angle;     
    double distance;
} 				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			keys[256];
	t_img		*img;
	t_map		map;
	t_player	player;
	t_tex 		tex;
	t_ray		*rays;
	t_minimap	minimap;
}				t_data;


/*-------FREE-------*/
void	cleanup(t_data *data);
/*-------INIT-------*/
int		file_validation(t_data *data, int argc, char **argv);
int		parse_line(t_tex *texture, char *line, int *error);
int		map_validation(t_map map);
int		get_texture(t_tex *texture, char *line, int *error);
/*-------MLX-------*/
void	draw_tile(t_img *img, int x, int y, int color);
void	draw_pixel(t_img *img, int x, int y, int color);
int		game_loop(t_data *data);
void	render_ceiling(t_data *data);
void	render_floor(t_data *data);
void	render_player(t_data *data);
void	render_minimap(t_data *data);
void	open_window(t_data *data);
/*-------PLAYER-------*/
void	init_player(t_data *data);



#endif