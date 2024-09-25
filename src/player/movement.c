/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/25 17:11:25 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data, double move_speed)
{
	double new_x;
	double new_y;

	new_x = data->player.x + data->player.dir_x * move_speed;
	new_y = data->player.y + data->player.dir_y * move_speed;
	if (data->map.map_mtx[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	move_backward(t_data *data, double move_speed)
{
	double new_x;
	double new_y;

	new_x = data->player.x - data->player.dir_x * move_speed;
	new_y = data->player.y - data->player.dir_y * move_speed;
	if (data->map.map_mtx[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	move_left(t_data *data, double move_speed)
{
	double new_x;
	double new_y;

	new_x = data->player.x - data->player.plane_x * move_speed;
	new_y = data->player.y - data->player.plane_y * move_speed;
	if (data->map.map_mtx[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	move_right(t_data *data, double move_speed)
{
	double new_x;
	double new_y;

	new_x = data->player.x + data->player.plane_x * move_speed;
	new_y = data->player.y + data->player.plane_y * move_speed;
	if (data->map.map_mtx[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}


void handle_movement(t_data *data)
{
	double move_speed;

	move_speed = 0.05;
	if (data->keys[KEY_W])
		move_forward(data, move_speed);
	if (data->keys[KEY_S])
		move_backward(data, move_speed);
	if (data->keys[KEY_A])
		move_left(data, move_speed);
	if (data->keys[KEY_D])
		move_right(data, move_speed);
}