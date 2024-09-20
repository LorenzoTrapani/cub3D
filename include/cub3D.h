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
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_M XK_m

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800
# define MAP_WIDTH 400
# define MAP_HEIGHT 400
# define MOVE_SPEED 0.001
# define ROT_SPEED 0.1
# define FOV 60
# define M_PI 3.14159265358979323846
# define M_PI_2 1.57079632679489661923
# define TILE_SIZE 8
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREY 0x00808080

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
	double		angle;
}				t_player;

typedef struct s_minimap
{
	t_img		*minimap;
	char		*minimap_data;
	bool 		show;
}				t_minimap;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_minimap	minimap;
	t_map		map;
	t_tex 		tex;
	t_player	player;
	int			keys[256];
}				t_data;


/*-------FILE_VALIDATION-------*/
int		 file_validation(t_data *data, int argc, char **argv);
/*-------PARSE_LINE-------*/
int		parse_line(t_tex *texture, char *line, int *error);
/*-------CLEANUP-------*/
void	cleanup(t_data *data);
/*-------WINDOW-------*/
void	open_window(t_data *data);
/*-------TEXTURE-------*/
int	get_texture(t_tex *texture, char *line, int *error);

void init_player(t_data *data);
void move_forward(t_data *data);
void move_backward(t_data *data);
void move_left(t_data *data);
void move_right(t_data *data);
void get_angle(char c, t_player *player);
void open_minimap(t_data *data);
int	load_game(t_data *data);
void handle_movement(t_data *data);

int	map_validation(t_map map);

#endif