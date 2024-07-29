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

# define WIN_WIDTH 1600
# define WIN_HEIGHT 800

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
}				t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_tex 		tex;
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

#endif