/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/13 17:31:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_rotation(t_data *data)
{
	double	angle_rad;

	if (data->keys[5] == 1)
	{
		data->player.dir_angle -= ROT_SPEED;
		if (data->player.dir_angle < 0)
			data->player.dir_angle += 360;
	}
	if (data->keys[4] == 1)
	{
		data->player.dir_angle += ROT_SPEED;
		if (data->player.dir_angle >= 360)
			data->player.dir_angle -= 360;
	}
	angle_rad = data->player.dir_angle * (M_PI / 180.0);
	data->player.dir_x = cos(angle_rad);
	data->player.dir_y = sin(angle_rad);
}
