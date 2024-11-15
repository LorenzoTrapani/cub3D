/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:30 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/15 18:19:18 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_side_f(t_raycasting *ray)
{
	ray->side_d_x += ray->delta_dist_x;
	ray->map_x += ray->step_x;
	ray->side = false;
}

void	assign_side_t(t_raycasting *ray)
{
	ray->side_d_y += ray->delta_dist_y;
	ray->map_y += ray->step_y;
	ray->side = true;
}

void	get_wall_dir(t_raycasting *ray)
{
	if (ray->side == false)
	{
		if (ray->ray_dir_x > 0)
			ray->wall_dir = WEST;
		else
			ray->wall_dir = EAST;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->wall_dir = NORTH;
		else
			ray->wall_dir = SOUTH;
	}
}

void	perform_dda(t_data *data, t_raycasting *ray)
{
	bool	hit;
	double	offset;

	hit = false;
	offset = 0.01;
	while (!hit)
	{
		if (ray->side_d_x < ray->side_d_y)
			assign_side_f(ray);
		else
			assign_side_t(ray);
		if (data->map.map_mtx[ray->map_y][ray->map_x] == '1')
		{
			get_wall_dir(ray);
			hit = true;
		}
	}
	if (ray->side == false)
		ray->perp_wall_dist = (ray->side_d_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_d_y - ray->delta_dist_y);
	if (ray->perp_wall_dist < offset)
		ray->perp_wall_dist = offset;
}

void	calculate_wall_limits(int wall_height, int *wall_top, int *wall_bottom)
{
	const int	half_win_height = WIN_HEIGHT / 2;
	int			half_wall_height;

	half_wall_height = wall_height / 2;
	*wall_top = half_win_height - half_wall_height;
	*wall_bottom = half_win_height + half_wall_height;
	if (*wall_top < 0)
		*wall_top = 0;
	if (*wall_bottom >= WIN_HEIGHT)
		*wall_bottom = WIN_HEIGHT - 1;
}
