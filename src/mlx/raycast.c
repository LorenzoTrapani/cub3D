/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:53 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/19 17:39:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_planes(t_data *data)
{
	const double	plane_limit = FOV;

	data->ray.plane_x = -data->player.dir_y * plane_limit;
	data->ray.plane_y = data->player.dir_x * plane_limit;
}

void	init_step_and_side_dist(t_data *data, t_raycasting *ray)
{
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->step_x = 1;
	ray->step_y = 1;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_d_x = (data->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_d_x = (ray->map_x + 1.0 - data->player.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_d_y = (data->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_d_y = (ray->map_y + 1.0 - data->player.y) * ray->delta_dist_y;
	}
}

t_img	*selected_texture(t_data *data)
{
	t_img	*texture;

	if (data->ray.wall_dir == NORTH)
		texture = &data->tex.north_img;
	else if (data->ray.wall_dir == SOUTH)
		texture = &data->tex.south_img;
	else if (data->ray.wall_dir == WEST)
		texture = &data->tex.west_img;
	else
		texture = &data->tex.east_img;
	return (texture);
}

int	get_texture_color(t_data *data, int tex_x, double tex_pos)
{
	int		tex_y;
	int		color;
	int		pixel_color;
	t_img	*texture;

	texture = selected_texture(data);
	tex_y = (int)tex_pos % texture->height;
	pixel_color = (tex_y * texture->size_line) + (tex_x * (texture->bpp / 8));
	color = *(int *)(texture->data + pixel_color);
	return (color);
}

void	render_wall_column(t_data *data, int x)
{
	double	camera_x;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;

	camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	calculate_ray_direction(data, camera_x);
	calculate_delta_distance(data);
	init_step_and_side_dist(data, &data->ray);
	perform_dda(data, &data->ray);
	wall_height = (int)(WIN_HEIGHT / data->ray.perp_wall_dist);
	calculate_wall_limits(wall_height, &wall_top, &wall_bottom);
	calculate_step(data, wall_height, wall_top);
	calculate_texture_limit(data);
	data->tex.hit_point = calculate_hit_point(data);
	data->tex.tex_x = (int)(data->tex.hit_point * (double)data->tex.width);
	draw_wall(data, x, wall_top, wall_bottom);
}
