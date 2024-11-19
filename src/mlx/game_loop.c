/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:15:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/19 17:40:42 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_w_e(t_data *data)
{
	if (data->ray.ray_dir_x > 0)
	{
		data->tex.width = data->tex.west_img.width;
		data->tex.height = data->tex.west_img.height;
	}
	else
	{
		data->tex.width = data->tex.east_img.width;
		data->tex.height = data->tex.east_img.height;
	}
}

void	calculate_texture_limit(t_data *data)
{
	if (data->ray.side == false)
		assign_w_e(data);
	else
	{
		if (data->ray.ray_dir_y > 0)
		{
			data->tex.width = data->tex.north_img.width;
			data->tex.height = data->tex.north_img.height;
		}
		else
		{
			data->tex.width = data->tex.south_img.width;
			data->tex.height = data->tex.south_img.height;
		}
	}
}

void	update_player(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
}

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	update_player(data);
	render_ceiling(data);
	render_floor(data);
	render_walls(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (1);
}
