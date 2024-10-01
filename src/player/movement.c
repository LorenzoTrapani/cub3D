/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 14:48:57 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = MOVE_SPEED * data->player.dir_x + data->player.x;
	new_y = MOVE_SPEED * data->player.dir_y + data->player.y;
	if (!check_vertical_collision(data, new_y)
		&& !check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		return ;
	}
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = -MOVE_SPEED * data->player.dir_x + data->player.x;
	new_y = -MOVE_SPEED * data->player.dir_y + data->player.y;
	if (!check_vertical_collision(data, new_y)
		&& !check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		return ;
	}
}

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = MOVE_SPEED * data->player.dir_y + data->player.x;
	new_y = -MOVE_SPEED * data->player.dir_x + data->player.y;
	if (!check_orizontal_collision(data, new_x)
		&& !check_vertical_collision(data, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		return ;
	}
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = -MOVE_SPEED * data->player.dir_y + data->player.x;
	new_y = MOVE_SPEED * data->player.dir_x + data->player.y;
	if (!check_orizontal_collision(data, new_x)
		&& !check_vertical_collision(data, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		return ;
	}
}

void	handle_movement(t_data *data)
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
