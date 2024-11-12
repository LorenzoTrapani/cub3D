/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 14:52:46 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_rotation(t_data *data)
{
	if (data->keys[5] == 1)
	{
		data->player.dir_angle -= 1;
		if (data->player.dir_angle < 0)
			data->player.dir_angle = 359;
		data->player.dir_x = cos(data->player.dir_angle * M_PI / 180)
			* MOVE_SPEED;
		data->player.dir_y = sin(data->player.dir_angle * M_PI / 180)
			* MOVE_SPEED;
	}
	if (data->keys[4] == 1)
	{
		data->player.dir_angle += 1;
		if (data->player.dir_angle >= 360)
			data->player.dir_angle = 0;
		data->player.dir_x = cos(data->player.dir_angle * M_PI / 180)
			* MOVE_SPEED;
		data->player.dir_y = sin(data->player.dir_angle * M_PI / 180)
			* MOVE_SPEED;
	}
}
