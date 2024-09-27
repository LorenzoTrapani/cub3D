/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/27 19:39:43 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	orizontal_adjust(t_data *data, double dir_x)
{
	double new_x;

	new_x = data->player.x + dir_x * 0.01;
	if (!check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		orizontal_adjust(data, dir_x);
	}
}

void	vertical_adjust(t_data *data, double dir_y)
{
	double new_y;

	new_y = data->player.y + dir_y * 0.01;
	if (!check_vertical_collision(data, new_y))
	{
		data->player.y = new_y;
		vertical_adjust(data, dir_y);
	}
}
void move_forward(t_data *data)
{
    double new_y;

	new_y = -MOVE_SPEED * data->player.dir_y + data->player.y;
	if (!check_vertical_collision(data, new_y))
	{
		data->player.y = new_y;
		return ;
	}
	vertical_adjust(data, -data->player.dir_y);
}


void	move_backward(t_data *data)
{
	double new_y;

	new_y = MOVE_SPEED * data->player.dir_y + data->player.y;
	if (!check_vertical_collision(data, new_y))
	{
		data->player.y = new_y;
		return ;
	}
	vertical_adjust(data, data->player.dir_y);	
}

void	move_left(t_data *data)
{
	double new_x;

	new_x = -MOVE_SPEED * data->player.dir_x + data->player.x;
	if (!check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		return ;
	}
	orizontal_adjust(data, -data->player.dir_x);
}

void	move_right(t_data *data)
{
	double new_x;

	new_x = MOVE_SPEED * data->player.dir_x + data->player.x;
	if (!check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		return ;
	}
	orizontal_adjust(data, data->player.dir_x);
}

void handle_movement(t_data *data)
{
	if (data->player.orientation == 'N' || data->player.orientation == 'S')
	{
		if (data->keys[0] == 1)
			move_forward(data);
		if (data->keys[1] == 1)
			move_backward(data);
		if (data->keys[2] == 1)
			move_left(data);
		if (data->keys[3] == 1)
			move_right(data);
	}
	else if (data->player.orientation == 'E' || data->player.orientation == 'W')
	{
		if (data->keys[0] == 1)
			move_right(data);
		if (data->keys[1] == 1)
			move_left(data);
		if (data->keys[2] == 1)
			move_forward(data);
		if (data->keys[3] == 1)
			move_backward(data);
	}
} 