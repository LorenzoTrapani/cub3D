/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:30 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 17:38:25 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	perform_dda(t_data *data, t_raycasting *ray)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (ray->side_d_x < ray->side_d_y)
		{
			ray->side_d_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->last_hit_nord = false;
		}
		else
		{
			ray->side_d_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->last_hit_nord = true;
		}
		if (data->map.map_mtx[ray->map_y][ray->map_x] == '1')
			hit = true;
	}
	if (ray->last_hit_nord == false)
		ray->perp_wall_dist = (ray->side_d_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_d_y - ray->delta_dist_y);
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