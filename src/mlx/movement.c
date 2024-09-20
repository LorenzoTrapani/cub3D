/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/20 17:52:27 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + cos(data->player.angle) * MOVE_SPEED;
	new_y = data->player.y + sin(data->player.angle) * MOVE_SPEED;
	if (data->map.map_mtx[(int)new_y][(int)data->player.x] == '0')
		data->player.y = new_y;
	if (data->map.map_mtx[(int)data->player.y][(int)new_x] == '0')
		data->player.x = new_x;
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x - cos(data->player.angle) * MOVE_SPEED;
	new_y = data->player.y - sin(data->player.angle) * MOVE_SPEED;
	if (data->map.map_mtx[(int)new_y][(int)data->player.x] == '0')
		data->player.y = new_y;
	if (data->map.map_mtx[(int)data->player.y][(int)new_x] == '0')
		data->player.x = new_x;
}

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x - cos(data->player.angle + M_PI_2) * MOVE_SPEED;
	new_y = data->player.y - sin(data->player.angle + M_PI_2) * MOVE_SPEED;
	if (data->map.map_mtx[(int)new_y][(int)data->player.x] == '0')
		data->player.y = new_y;
	if (data->map.map_mtx[(int)data->player.y][(int)new_x] == '0')
		data->player.x = new_x;
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + cos(data->player.angle + M_PI_2) * MOVE_SPEED;
	new_y = data->player.y + sin(data->player.angle + M_PI_2) * MOVE_SPEED;
	if (data->map.map_mtx[(int)new_y][(int)data->player.x] == '0')
		data->player.y = new_y;
	if (data->map.map_mtx[(int)data->player.y][(int)new_x] == '0')
		data->player.x = new_x;
	
}

void handle_movement(t_data *data)
{
	if (data->keys[KEY_W])
		move_forward(data);
	if (data->keys[KEY_S])
		move_backward(data);
	if (data->keys[KEY_A])
		move_left(data);
	if (data->keys[KEY_D])
		move_right(data);
}