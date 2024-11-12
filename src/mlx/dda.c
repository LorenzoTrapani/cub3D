/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:30 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 16:07:51 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void perform_dda(t_data *data)
{
	bool hit;
	
	hit = false;
	while (!hit) 
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.last_hit_nord = false;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.last_hit_nord = true;
		}
		if (data->map.map_mtx[data->ray.map_y][data->ray.map_x] == '1')
			hit = true;
	}
	if (data->ray.last_hit_nord == false)
		data->ray.perp_wall_dist = (data->ray.side_dist_x - data->ray.delta_dist_x);
	else
		data->ray.perp_wall_dist = (data->ray.side_dist_y - data->ray.delta_dist_y);
}

void calculate_wall_limits(int wall_height, int *wall_top, int *wall_bottom)
{
	const int half_win_height = WIN_HEIGHT / 2;
	int half_wall_height;
	
	half_wall_height = wall_height / 2;
	*wall_top = half_win_height - half_wall_height;
	*wall_bottom = half_win_height + half_wall_height;
	if (*wall_top < 0)
		*wall_top = 0;
	if (*wall_bottom >= WIN_HEIGHT)
		*wall_bottom = WIN_HEIGHT - 1;
}
