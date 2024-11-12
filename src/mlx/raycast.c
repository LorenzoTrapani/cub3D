/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:53 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 18:27:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_planes(t_data *data)
{
	const double	plane_limit = 0.7;

	data->ray.plane_x = -data->player.dir_y * plane_limit;
	data->ray.plane_y = data->player.dir_x * plane_limit;
}

void	calculate_ray_direction(t_data *data, double camera_x)
{
	data->ray.ray_dir_x = data->player.dir_x + data->ray.plane_x * camera_x;
	data->ray.ray_dir_y = data->player.dir_y + data->ray.plane_y * camera_x;
}

void	calculate_delta_distance(t_data *data)
{
	data->ray.delta_dist_x = INT_MAX;
	data->ray.delta_dist_y = INT_MAX;
	if (data->ray.ray_dir_x != 0)
		data->ray.delta_dist_x = fabs(1.0 / data->ray.ray_dir_x);
	if (data->ray.ray_dir_y != 0)
		data->ray.delta_dist_y = fabs(1.0 / data->ray.ray_dir_y);
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

void	render_wall_column(t_data *data, int i)
{
	double	camera_x;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;

	camera_x = 2.0 * i / (double)WIN_WIDTH - 1.0;
	calculate_ray_direction(data, camera_x);
	calculate_delta_distance(data);
	init_step_and_side_dist(data, &data->ray);
	perform_dda(data, &data->ray);
	if (data->ray.perp_wall_dist < 0.001)
		data->ray.perp_wall_dist = 0.001;
	wall_height = (int)(WIN_HEIGHT / data->ray.perp_wall_dist);
	calculate_wall_limits(wall_height, &wall_top, &wall_bottom);
	while (wall_top <= wall_bottom)
	{
		draw_pixel(data->img, i, wall_top, 0x0);
		wall_top++;
	}
}
