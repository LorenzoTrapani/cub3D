/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:15 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 15:01:14 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			draw_pixel(data->img, x, y, data->tex.ceiling);
	}
}

void	render_floor(t_data *data)
{
	int	x;
	int	y;

	y = WIN_HEIGHT / 2 - 1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			draw_pixel(data->img, x, y, data->tex.floor);
	}
}

void	draw_line_dir(t_data *data)
{
	double	new_x;
	double	new_y;
	int		i;

	i = 0;
	new_x = data->player.x * TILE_SIZE;
	new_y = data->player.y * TILE_SIZE;
	while (i < 20)
	{
		new_x += data->player.dir_x;
		new_y += data->player.dir_y;
		draw_pixel(data->img, new_x, new_y, RED);
		i++;
	}
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	if (data->minimap.show == 1)
		return ;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map.map_mtx[y]))
		{
			color = data->tex.ceiling;
			if (data->map.map_mtx[y][x] == '1')
				color = GREY;
			else if (data->map.map_mtx[y][x] == '0')
				color = WHITE;
			if (color != data->tex.ceiling)
				draw_tile(data->img, x * TILE_SIZE, y * TILE_SIZE, color);
		}
	}
	draw_player(data);
	draw_line_dir(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 10, 10);
}

void render_walls(t_data *data)
{
	const double plane_limit = 0.7;
	double plane_x = -data->player.dir_y * plane_limit;
	double plane_y = data->player.dir_x * plane_limit;
	int i;
	i = -1;
	while (++i < WIN_WIDTH)
	{
		double camera_x = (double)(2.0 * i) / (double)WIN_WIDTH - 1.0;
		double ray_dir_x = data->player.dir_x + plane_x * camera_x;
		double ray_dir_y = data->player.dir_y + plane_y * camera_x;


		double delta_dist_x = INT_MAX;
		if (ray_dir_x != 0)
			delta_dist_x = fabs(1.0 / ray_dir_x);
		double delta_dist_y = INT_MAX;
		if (ray_dir_y != 0)
			delta_dist_y = fabs(1.0 / ray_dir_y);

		int mapX = (int)(data->player.x);
		int mapY = (int)(data->player.y);

		int step_x = 1;

		int step_y = 1;

		double side_dist_x;
		double side_dist_y;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->player.x - mapX) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (mapX + 1.0 - data->player.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->player.y - mapY) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (mapY + 1.0 - data->player.y) * delta_dist_y;
		}

		double perpWallDist;


		bool hit = false; // was there a wall hit?
		bool last_hit_nord;	 // was a NS or a EW wall hit?
		//printf("\t[PRE]\tsideDist[%f][%f]\n", side_dist_x, side_dist_y);
		while (!hit)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				mapX += step_x;
				last_hit_nord = false;
			}
			else
			{
				side_dist_y += delta_dist_y;
				mapY += step_y;
				last_hit_nord = true;
			}
			//printf("\t[%d][%d]", mapX, mapY);
			// Check if ray has hit a wall
			if (data->map.map_mtx[mapY][mapX] == '1')
				hit = true;
		}
		//printf("\n");
		//printf("\t[POST]\tsideDist[%f][%f]\n", side_dist_x, side_dist_y);
		if (last_hit_nord == false)
			perpWallDist = (side_dist_x - delta_dist_x);
		else
			perpWallDist = (side_dist_y - delta_dist_y);

		int wall_height = (int)(WIN_HEIGHT / perpWallDist);
		//printf("\tlastHitNord[%s]\n", last_hit_nord ? "true":"false");

		// calculate lowest and highest pixel to fill in current stripe
		const int win_half_height = WIN_HEIGHT / 2;
		const int wall_half_height = wall_height / 2;

		int wall_top = win_half_height - wall_half_height;
		if (wall_top < 0)
			wall_top = 0;

		int wall_bottom = win_half_height + wall_half_height;
		if (wall_bottom >= WIN_HEIGHT)
			wall_bottom = WIN_HEIGHT - 1;

		while (wall_top <= wall_bottom)
		{
			draw_pixel(data->img, i, wall_top, 0x0);
			wall_top++;
		}
	}
}
