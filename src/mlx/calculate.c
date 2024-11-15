/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:48:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/15 18:51:42 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	calculate_step(t_data *data, int wall_height, int wall_top)
{
	data->tex.step = (double)TEX_HEIGHT / wall_height;
	data->tex.tex_pos = (wall_top - WIN_HEIGHT / 2 + wall_height / 2)
		* data->tex.step;
}

double	calculate_hit_point(t_data *data)
{
	double	hit_point;

	if (data->ray.side == 0)
		hit_point = data->player.y + data->ray.perp_wall_dist
			* data->ray.ray_dir_y;
	else
		hit_point = data->player.x + data->ray.perp_wall_dist
			* data->ray.ray_dir_x;
	hit_point -= floor(hit_point);
	return (hit_point);
}
