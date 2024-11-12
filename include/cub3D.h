/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 16:11:45 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define MOVE_SPEED .22
# define MAX_FOV .7
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

typedef struct s_tex
{
	void		*north;
	void		*south;
	void		*west;
	void		*east;
	int			floor;
	int			ceiling;
}			t_tex;

typedef struct s_map
{
	char		**map_mtx;
	int			width;
	int			height;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		dir_angle;
}				t_player;

typedef struct s_minimap
{
	char		*minimap_data;
	int			show;
}				t_minimap;

typedef struct
{
	double plane_x;
	double plane_y;
	double ray_dir_x;
	double ray_dir_y;
	double delta_dist_x;
	double delta_dist_y;
	double side_dist_x;
	double side_dist_y;
	double perp_wall_dist;
	int step_x;
	int step_y;
	int map_x;
	int map_y;
	bool last_hit_nord;
}				t_raycasting;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	int				keys[6];
	t_img			*img;
	t_map			map;
	t_player		player;
	t_tex			tex;
	t_minimap		minimap;
	t_raycasting	ray;
}				t_data;

/*-------FREE-------*/
void	cleanup(t_data *data);
/*-------INIT-------*/
int		file_validation(t_data *data, int argc, char **argv);
int		parse_line(t_tex *texture, char *line);
int		map_validation(t_map map);
int		get_texture(t_tex *texture, char *line);
void	init_keys(t_data *data);
/*-------MLX-------*/
void	draw_tile(t_img *img, int x, int y, int color);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_player(t_data *data);
int		game_loop(t_data *data);
void	render_ceiling(t_data *data);
void	render_floor(t_data *data);
void	render_player(t_data *data);
void	render_minimap(t_data *data);
void	open_window(t_data *data);
void	render_walls(t_data *data);
void	init_planes(t_data *data);
void	render_wall_column(t_data *data, int i);
void	perform_dda(t_data *data);
void	calculate_wall_limits(int wall_height, int *wall_top, int *wall_bottom);
/*-------PLAYER-------*/
int		get_position(char **map_mtx, t_player *player);
void	handle_movement(t_data *data);
void	handle_rotation(t_data *data);
int		check_orizontal_collision(t_data *data, double new_x);
int		check_vertical_collision(t_data *data, double new_y);


#endif